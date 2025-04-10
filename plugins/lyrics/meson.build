lyrics_sources = [
    'lyrics.c',
    'support.c',
    'support.h'
]

has_lyrics = not get_option('plugin-lyrics').disabled() and (has_gtk3_plugin or has_gtk2_plugin)

if gtk3_dep.found()

  plugin_gtk3_lyrics = shared_library('lyrics_gtk3', lyrics_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    dependencies : [gtk3_dep],
  )

endif


if gtk2_dep.found()

  plugin_gtk2_lyrics = shared_library('lyrics_gtk2', lyrics_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    dependencies : [gtk2_dep],
  )

endif

summary({'Lyrics': has_lyrics}, bool_yn: true, section: 'Plugins')
