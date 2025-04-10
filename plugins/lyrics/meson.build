lyrics_sources = [
    'lyrics.c',
    'support.c',
    'support.h'
]

gtk3_dep = dependency('gtk+-3.0', version: '>=3.12.0', required: get_option('plugin-gtk3'))

if gtk3_dep.found()

  plugin_gtk3_lyrics = shared_library('lyrics_gtk3', lyrics_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    dependencies : [gtk3_dep],
  )

endif

summary({'GTK3 GUI': gtk3_dep.found()}, bool_yn: true, section: 'Plugins')

gtk2_dep = dependency('gtk+-2.0', required: get_option('plugin-gtk2'))

if gtk2_dep.found()

  plugin_gtk2_lyrics = shared_library('lyrics_gtk2', lyrics_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    dependencies : [gtk2_dep],
  )

endif

summary({'GTK2 GUI': gtk2_dep.found()}, bool_yn: true, section: 'Plugins')
