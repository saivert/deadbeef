medialib_sources = [
    'medialib.c',
    'medialibcommon.c',
    'medialibdb.c',
    'medialibfilesystem_inotify.c',
    'medialibscanner.c',
    'medialibsource.c',
    'medialibstate.c',
    'medialibtree.c',
    'scriptable_tfquery.c',
    'medialib.h',
    'medialibcommon.h',
    'medialibdb.h',
    'medialibfilesystem.h',
    'medialibscanner.h',
    'medialibsource.h',
    'medialibstate.h',
    'medialibtree.h',
    'scriptable_tfquery.h',
]

has_medialib = not get_option('plugin-medialib').disabled()

if has_medialib
    plugin_medialib = shared_library(
        'medialib',
        medialib_sources,
        name_prefix: '',
        install: true,
        install_dir: plugindir,
        include_directories: deadbeef_inc,
        dependencies: [libscriptable_dep, jansson_dep, libdispatch_dep],
    )
endif

summary(
    {'Media library support': has_hotkeys},
    bool_yn: true,
    section: 'Plugins',
)