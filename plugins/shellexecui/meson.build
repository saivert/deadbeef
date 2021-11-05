shellexecui_sources = [
  'shellexecui.c',
  'interface.c',
  'support.c',
  'callbacks.c',
  'interface.h',
  'support.h',
  'callbacks.h'
]

has_shellexecui = not get_option('plugin-shellexecui').disabled()

if has_shellexecui and gtk2_dep.found()
  plugin_shellexecui = shared_library('shellexecui_gtk2', shellexecui_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk2_dep]
  )
endif

if has_shellexecui and gtk3_dep.found()
  plugin_shellexecui = shared_library('shellexecui_gtk3', shellexecui_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk3_dep]
  )
endif

if gtk2_dep.found() or gtk3_dep.found()
summary({'GTK user interface for shellexec plugin': has_shellexecui}, bool_yn: true, section: 'Plugins')
endif
