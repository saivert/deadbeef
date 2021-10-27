
gtk3ui_sources = [
    'actionhandlers.c',
    'actions.c',
    'callbacks.c',
    'clipboard.c',
    'coverart.c',
    'ctmapping.c',
    'ddbcellrenderertextmultiline.c',
    'ddbequalizer.c',
    'ddblistview.c',
    'ddbseekbar.c',
    'ddb_splitter.c',
    'ddb_splitter_size_mode.c',
    'ddbtabstrip.c',
    'ddbvolumebar.c',
    'deadbeefapp.c',
    'dspconfig.c',
    'eq.c',
    'fileman.c',
    'gdkdrawing.c',
    'gtkui.c',
    'gtkui_deletefromdisk.c',
    'hotkeys.c',
    'interface.c',
    'mainplaylist.c',
    'namedicons.c',
    'plcommon.c',
    'prefwin/prefwin.c',
    'prefwin/prefwinappearance.c',
    'prefwin/prefwinmedialib.c',
    'prefwin/prefwinmisc.c',
    'prefwin/prefwinnetwork.c',
    'prefwin/prefwinplayback.c',
    'prefwin/prefwinplugins.c',
    'prefwin/prefwinsound.c',
    'pltmenu.c',
    'pluginconf.c',
    'progress.c',
    'rg.c',
    'search.c',
    'support.c',
    'tagwritersettings.c',
    'tfimport.c',
    'trkproperties.c',
    'widgets.c',
    'wingeom.c',
    '../../utf8.c',
    'medialib/medialibwidget.c',
    'medialib/medialibmanager.c',
    '../libparser/parser.c',
    '../../analyzer/analyzer.c',
    '../../scope/scope.c'
]

install_headers(['gtkui_api.h'], subdir : 'deadbeef')

gnome = import('gnome')

gtk3ui_resources = gnome.compile_resources(
    'gtkui-gresources', 'gtkui.gresources.xml',
    #source_dir: '.',
    c_name: 'gtkui'
)

summary({'GTK3 GUI': need_gtk3ui}, bool_yn: true, section: 'Plugins')

plugin_gtk3ui = shared_library('ddb_gui_GTK3', gtk3ui_sources + gtk3ui_resources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: ['../..'],
  link_with: [libtrkpropertiesutil, libtftintutil, libdeletefromdisk, libeqpreset],
  dependencies : [m_dep, gtk3_dep, jansson_dep],
)