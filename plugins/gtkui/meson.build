gtk23ui_sources = [
  '../../src/utf8.c',
  'actions.c', 'actions.h',
  'callbacks.c', 'callbacks.h',
  'support.c', 'support.h',
  'interface.c', 'interface.h',
  'ddbseekbar.c', 'ddbseekbar.h',
  'ddbcellrenderertextmultiline.c', 'ddbcellrenderertextmultiline.h',
  'ddbequalizer.c', 'ddbequalizer.h',
  'ddbtabstrip.c', 'ddbtabstrip.h',
  'ddbvolumebar.c', 'ddbvolumebar.h',
  'gdkdrawing.c', 'drawing.h',
  'dspconfig.c', 'dspconfig.h',
  'eq.c', 'eq.h',
  'fileman.c',
  'gtkui.c', 'gtkui.h',
  'gtkui_deletefromdisk.c', 'gtkui_deletefromdisk.h',
  'plmenu.c', 'plmenu.h',
  'pluginconf.c', 'pluginconf.h',
  'progress.c', 'progress.h',
  'rg.c', 'rg.h',
  'search.c', 'search.h',
  'tagwritersettings.c', 'tagwritersettings.h',
  'trkproperties.c', 'trkproperties.h',
  'widgets.c', 'widgets.h',
  'selpropertieswidget.c', 'selpropertieswidget.h',
  'wingeom.c', 'wingeom.h',
  'actionhandlers.c', 'actionhandlers.h',
  'clipboard.c', 'clipboard.h',
  'ctmapping.c', 'ctmapping.h',
  'ddb_splitter.c', 'ddb_splitter.h',
  'ddb_splitter_size_mode.c', 'ddb_splitter_size_mode.h',
  'hotkeys.c', 'hotkeys.h',
  'namedicons.c', 'namedicons.h',
  'pltmenu.c',
  'tfimport.c', 'tfimport.h',
  'medialib/medialibwidget.c', 'medialib/medialibwidget.h',
  'medialib/medialibmanager.c', 'medialib/medialibmanager.h',
  'medialib/mlcellrendererpixbuf.c', 'medialib/mlcellrendererpixbuf.h',
  'covermanager/covermanager.c', 'covermanager/covermanager.h',
  'covermanager/gobjcache.c', 'covermanager/gobjcache.h',
  'covermanager/albumartwidget.c', 'covermanager/albumartwidget.h',
  'playlist/ddblistview.c', 'playlist/ddblistview.h',
  'playlist/ddblistviewheader.c', 'playlist/ddblistviewheader.h',
  'playlist/mainplaylist.c', 'playlist/mainplaylist.h',
  'playlist/playlistcontroller.c', 'playlist/playlistcontroller.h',
  'playlist/playlistrenderer.c', 'playlist/playlistrenderer.h',
  'playlist/plcommon.c', 'playlist/plcommon.h',
  'playlist/searchplaylist.c', 'playlist/searchplaylist.h',
  'prefwin/prefwin.c', 'prefwin/prefwin.h',
  'prefwin/prefwinappearance.c', 'prefwin/prefwinappearance.h',
  'prefwin/prefwinmedialib.c', 'prefwin/prefwinmedialib.h',
  'prefwin/prefwinmisc.c', 'prefwin/prefwinmisc.h',
  'prefwin/prefwinnetwork.c', 'prefwin/prefwinnetwork.h',
  'prefwin/prefwinplayback.c', 'prefwin/prefwinplayback.h',
  'prefwin/prefwinplugins.c', 'prefwin/prefwinplugins.h',
  'prefwin/prefwinsound.c', 'prefwin/prefwinsound.h',
  'scriptable/gtkScriptable.c', 'scriptable/gtkScriptable.h',
  'scriptable/gtkScriptableListEditViewController.c',
  'scriptable/gtkScriptableListEditViewController.h',
  'scriptable/gtkScriptableListEditWindowController.c',
  'scriptable/gtkScriptableListEditWindowController.h',
  'scriptable/gtkScriptableSelectViewController.c',
  'scriptable/gtkScriptableSelectViewController.h',
  'undostack.c', 'undostack.h',
  'undointegration.c', 'undointegration.h'
]

install_headers(['gtkui_api.h'], subdir : 'deadbeef')

gtk3_dep = dependency('gtk+-3.0', version: '>=3.12.0', required: get_option('plugin-gtk3'))

has_gtk3_plugin = not get_option('plugin-gtk3').disabled() and gtk3_dep.found()

if gtk3_dep.found()

  gnome = import('gnome')

  gtk3ui_resources = gnome.compile_resources(
    'gtkui-gresources', 'gtkui.gresources.xml',
    #source_dir: '.',
    c_name: 'gtkui'
  )

  gtk3ui_sources = ['deadbeefapp.c', 'deadbeefapp.h']

  plugin_gtk3ui = shared_library('ddb_gui_GTK3', gtk23ui_sources + gtk3ui_resources + gtk3ui_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    c_args: '-DGLIB_DISABLE_DEPRECATION_WARNINGS -DGDK_DISABLE_DEPRECATION_WARNINGS -DGTK_DISABLE_DEPRECATION_WARNINGS -DDDB_WARN_DEPRECATED=1',
    link_with: [libtrkpropertiesutil, libtftintutil, libdeletefromdisk, libeqpreset, libanalyzer, libscope, libparser],
    dependencies : [m_dep, gtk3_dep, jansson_dep, libscriptable_dep, libdispatch_dep],
  )

endif

summary({'GTK3 GUI': gtk3_dep.found()}, bool_yn: true, section: 'Plugins')

gtk2_dep = dependency('gtk+-2.0', required: get_option('plugin-gtk2'))

has_gtk2_plugin = not get_option('plugin-gtk2').disabled() and gtk2_dep.found()

if gtk2_dep.found()

  plugin_gtk2ui = shared_library('ddb_gui_GTK2', gtk23ui_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    c_args: '-DGLIB_DISABLE_DEPRECATION_WARNINGS -DGDK_DISABLE_DEPRECATION_WARNINGS -DGTK_DISABLE_DEPRECATION_WARNINGS -DDDB_WARN_DEPRECATED=1',
    link_with: [libtrkpropertiesutil, libtftintutil, libdeletefromdisk, libeqpreset, libanalyzer, libscope, libparser],
    dependencies : [m_dep, gtk2_dep, jansson_dep, libscriptable_dep, libdispatch_dep],
  )

endif

summary({'GTK2 GUI': gtk2_dep.found()}, bool_yn: true, section: 'Plugins')
