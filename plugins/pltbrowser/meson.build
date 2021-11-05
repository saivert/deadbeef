pltbrowser_sources_gtk2 = [
  'pltbrowser.c',
  'support.c',
  'support.h'
]

pltbrowser_sources_gtk3 = [
  'pltbrowser.c'
]

has_pltbrowser = not get_option('plugin-pltbrowser').disabled()

if has_pltbrowser and gtk2_dep.found()
  plugin_pltbrowser = shared_library('pltbrowser_gtk2', pltbrowser_sources_gtk2,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk2_dep]
  )
endif

if has_pltbrowser and gtk3_dep.found()
  plugin_pltbrowser = shared_library('pltbrowser_gtk3', pltbrowser_sources_gtk3,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk3_dep]
  )
endif

summary({'playlist browser gui plugin': has_pltbrowser}, bool_yn: true, section: 'Plugins')
