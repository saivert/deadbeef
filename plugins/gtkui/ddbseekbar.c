/*
    DeaDBeeF -- the music player
    Copyright (C) 2009-2015 Alexey Yakovenko and other contributors

    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.

    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.
*/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <drawing.h>
#include <gtkui.h>
#include <math.h>
#include "support.h"
#include "ddbseekbar.h"


G_DEFINE_TYPE (DdbSeekbar, ddb_seekbar, GTK_TYPE_EVENT_BOX);

static gboolean ddb_seekbar_real_draw (GtkWidget* base, cairo_t *cr);
static gboolean ddb_seekbar_real_configure_event (GtkWidget* base, GdkEventConfigure* event);
gboolean
ddb_seekbar_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event);

gboolean
ddb_seekbar_button_release_event        (GtkWidget       *widget,
                                        GdkEventButton  *event);

gboolean
ddb_seekbar_motion_notify_event         (GtkWidget       *widget,
                                        GdkEventMotion  *event);
static gboolean ddb_seekbar_real_draw (GtkWidget* base, cairo_t *cr) {
	seekbar_draw (base, cr);
	return FALSE;
}

#if !GTK_CHECK_VERSION(3,0,0)
static gboolean ddb_seekbar_real_expose_event (GtkWidget* base, GdkEventExpose* event) {
    cairo_t *cr = gdk_cairo_create (gtk_widget_get_window (base));
    ddb_seekbar_real_draw (base, cr);
    cairo_destroy (cr);
	return FALSE;
}
#endif

static gboolean ddb_seekbar_real_configure_event (GtkWidget* base, GdkEventConfigure* event) {
	DdbSeekbar * self;
	gboolean result = FALSE;
	self = (DdbSeekbar*) base;
	g_return_val_if_fail (event != NULL, FALSE);
	gtkui_init_theme_colors ();
	result = FALSE;
	return result;
}

static int
seek_sec (float sec) {
    float pos = deadbeef->streamer_get_playpos ();
    pos += sec;
    deadbeef->sendmessage (DB_EV_SEEK, 0, (uint32_t)(pos * 1000), 0);
    return 0;
}

static gboolean ddb_seekbar_scroll_event(GtkWidget *widget, GdkEventScroll *event) {

    if (event->direction == GDK_SCROLL_UP || event->direction == GDK_SCROLL_RIGHT) {
        seek_sec (5.0f);
    }
    else if (event->direction == GDK_SCROLL_DOWN || event->direction == GDK_SCROLL_LEFT) {
        seek_sec (-5.0f);
    }

    return FALSE;
}

GtkWidget* ddb_seekbar_new (void) {
	return GTK_WIDGET (g_object_new(DDB_TYPE_SEEKBAR, NULL));
}

static void ddb_seekbar_class_init (DdbSeekbarClass * klass) {
#if GTK_CHECK_VERSION(3,0,0)
	GTK_WIDGET_CLASS (klass)->draw = ddb_seekbar_real_draw;
#else
	GTK_WIDGET_CLASS (klass)->expose_event = ddb_seekbar_real_expose_event;
#endif
	GTK_WIDGET_CLASS (klass)->button_press_event = ddb_seekbar_button_press_event;
	GTK_WIDGET_CLASS (klass)->button_release_event = ddb_seekbar_button_release_event;
	GTK_WIDGET_CLASS (klass)->motion_notify_event = ddb_seekbar_motion_notify_event;
	GTK_WIDGET_CLASS (klass)->configure_event = ddb_seekbar_real_configure_event;
    GTK_WIDGET_CLASS (klass)->scroll_event = ddb_seekbar_scroll_event;
}


static void ddb_seekbar_init (DdbSeekbar * self) {
	gtk_widget_set_has_window ((GtkWidget*) self, FALSE);
	gtk_widget_set_has_tooltip ((GtkWidget*) self, TRUE);
    gtk_widget_add_events (GTK_WIDGET (self), GDK_SCROLL_MASK);
	self->seekbar_moving = 0;
    self->seekbar_move_x = 0;
}



enum
{
	CORNER_NONE        = 0,
	CORNER_TOPLEFT     = 1,
	CORNER_TOPRIGHT    = 2,
	CORNER_BOTTOMLEFT  = 4,
	CORNER_BOTTOMRIGHT = 8,
	CORNER_ALL         = 15
};

static void
clearlooks_rounded_rectangle (cairo_t * cr,
			      double x, double y, double w, double h,
			      double radius, uint8_t corners)
{
    if (radius < 0.01 || (corners == CORNER_NONE)) {
        cairo_rectangle (cr, x, y, w, h);
        return;
    }
	
    if (corners & CORNER_TOPLEFT)
        cairo_move_to (cr, x + radius, y);
    else
        cairo_move_to (cr, x, y);

    if (corners & CORNER_TOPRIGHT)
        cairo_arc (cr, x + w - radius, y + radius, radius, M_PI * 1.5, M_PI * 2);
    else
        cairo_line_to (cr, x + w, y);

    if (corners & CORNER_BOTTOMRIGHT)
        cairo_arc (cr, x + w - radius, y + h - radius, radius, 0, M_PI * 0.5);
    else
        cairo_line_to (cr, x + w, y + h);

    if (corners & CORNER_BOTTOMLEFT)
        cairo_arc (cr, x + radius, y + h - radius, radius, M_PI * 0.5, M_PI);
    else
        cairo_line_to (cr, x, y + h);

    if (corners & CORNER_TOPLEFT)
        cairo_arc (cr, x + radius, y + radius, radius, M_PI, M_PI * 1.5);
    else
        cairo_line_to (cr, x, y);
	
}

void
seekbar_draw (GtkWidget *widget, cairo_t *cr) {
    if (!widget) {
        return;
    }

    DdbSeekbar *self = DDB_SEEKBAR (widget);

#if GTK_CHECK_VERSION(3,0,0)
    GtkAllocation allocation;
    gtk_widget_get_allocation (widget, &allocation);
    cairo_translate (cr, -allocation.x, -allocation.y);
#endif

    GdkColor clr_selection, clr_back;
    gtkui_get_bar_foreground_color (&clr_selection);
    gtkui_get_bar_background_color (&clr_back);

    GtkAllocation a;
    gtk_widget_get_allocation (widget, &a);

    int ax = a.x;
    int ay = a.y;
    int aw = a.width;
    int ah = a.height;

    DB_playItem_t *trk = deadbeef->streamer_get_playing_track ();
    // filler, only while playing a finite stream
    if (trk && deadbeef->pl_get_item_duration (trk) > 0) {
        float pos = 0;
        if (self->seekbar_moving) {
            int x = self->seekbar_move_x;
            if (x < 0) {
                x = 0;
            }
            if (x > a.width-1) {
                x = a.width-1;
            }
            pos = x;
        }
        else {
            if (deadbeef->pl_get_item_duration (trk) > 0) {
                pos = deadbeef->streamer_get_playpos () / deadbeef->pl_get_item_duration (trk);
                pos *= a.width;
            }
        }
        // left
        if (pos > 0) {
            cairo_set_source_rgb (cr, clr_selection.red/65535.f, clr_selection.green/65535.f, clr_selection.blue/65535.f );
            cairo_rectangle (cr, ax, ah/2-4+ay, pos, 8);
            cairo_clip (cr);
            clearlooks_rounded_rectangle (cr, 2+ax, ah/2-4+ay, aw-4, 8, 4, 0xff);
            cairo_fill (cr);
            cairo_reset_clip (cr);
        }
    }

    // empty seekbar, just a frame, always visible
    clearlooks_rounded_rectangle (cr, 2+ax, a.height/2-4+ay, aw-4, 8, 4, 0xff);
    cairo_set_source_rgb (cr, clr_selection.red/65535.f, clr_selection.green/65535.f, clr_selection.blue/65535.f );
    cairo_set_line_width (cr, 2);
    cairo_stroke (cr);

    // overlay, only while playing a finite stream, and only during seeking
    if (trk && deadbeef->pl_get_item_duration (trk) > 0) {
        if (!gtkui_disable_seekbar_overlay && (self->seekbar_moving || self->seekbar_moved > 0.0) && trk) {
            float time = 0;
            float dur = deadbeef->pl_get_item_duration (trk);

            if (self->seekbar_moved > 0) {
                time = deadbeef->streamer_get_playpos ();
            }
            else {
                time = self->seekbar_move_x * dur / (a.width);
            }

            if (time < 0) {
                time = 0;
            }
            if (time > dur) {
                time = dur;
            }
            char s[1000];
            int hr = time/3600;
            int mn = (time-hr*3600)/60;
            int sc = time-hr*3600-mn*60;
            snprintf (s, sizeof (s), "%02d:%02d:%02d", hr, mn, sc);

            cairo_set_source_rgba (cr, clr_selection.red/65535.f, clr_selection.green/65535.f, clr_selection.blue/65535.f, self->seektime_alpha);
            cairo_save (cr);
            cairo_set_font_size (cr, 20);

            cairo_text_extents_t ex;
            cairo_text_extents (cr, s, &ex);
            if (self->textpos == -1) {
                self->textpos = ax + aw/2 - ex.width/2;
                self->textwidth = ex.width + 20;
            }

            clearlooks_rounded_rectangle (cr, ax + aw/2 - self->textwidth/2, ay+4, self->textwidth, ah-8, 3, 0xff);
            cairo_fill (cr);

            cairo_move_to (cr, self->textpos, ay+ah/2+ex.height/2);
            GdkColor clr;
            gtkui_get_listview_selected_text_color (&clr);
            cairo_set_source_rgba (cr, clr.red/65535.f, clr.green/65535.f, clr.blue/65535.f, self->seektime_alpha);
            cairo_show_text (cr, s);
            cairo_restore (cr);

            int fps = deadbeef->conf_get_int ("gtkui.refresh_rate", 10);
            if (fps < 1) {
                fps = 1;
            }
            else if (fps > 30) {
                fps = 30;
            }
            if (self->seekbar_moved >= 0.0) {
                self->seekbar_moved -= 1.0/fps;
            }
            else {
                self->seekbar_moved = 0.0;
            }
        }
    }

    if (trk) {
        deadbeef->pl_item_unref (trk);
    }
}

gboolean
ddb_seekbar_motion_notify_event         (GtkWidget       *widget,
                                        GdkEventMotion  *event)
{
    DdbSeekbar *self = DDB_SEEKBAR (widget);
    if (self->seekbar_moving) {
        self->seekbar_move_x = event->x;
        gtk_widget_queue_draw (widget);
    }
    return FALSE;
}

gboolean
ddb_seekbar_button_press_event          (GtkWidget       *widget,
                                        GdkEventButton  *event)
{
    DdbSeekbar *self = DDB_SEEKBAR (widget);
    if (deadbeef->get_output ()->state () == DDB_PLAYBACK_STATE_STOPPED) {
        return FALSE;
    }
    self->seekbar_moving = 1;
    self->seekbar_moved = 0;
    self->textpos = -1;
    self->textwidth = -1;
    self->seektime_alpha = 0.8;
    self->seekbar_move_x = event->x;
    gtk_widget_queue_draw (widget);
    return FALSE;
}


gboolean
ddb_seekbar_button_release_event        (GtkWidget       *widget,
                                        GdkEventButton  *event)
{
    DdbSeekbar *self = DDB_SEEKBAR (widget);
    self->seekbar_moving = 0;
    self->seekbar_moved = 1.0;
    DB_playItem_t *trk = deadbeef->streamer_get_playing_track ();
    if (trk) {
        if (deadbeef->pl_get_item_duration (trk) >= 0) {
            GtkAllocation a;
            gtk_widget_get_allocation (widget, &a);
            float time = (event->x) * deadbeef->pl_get_item_duration (trk) / (a.width);
            if (time < 0) {
                time = 0;
            }
            deadbeef->sendmessage (DB_EV_SEEK, 0, time * 1000, 0);
        }
        deadbeef->pl_item_unref (trk);
    }
    gtk_widget_queue_draw (widget);
    return FALSE;
}

