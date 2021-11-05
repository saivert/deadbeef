shellexec_sources = [
  'shellexec.c',
  'shellexec.h',
  'shellexecutil.c',
  'shellexecutil.h'
]

has_shellexec = not get_option('plugin-shellexec').disabled() and jansson_dep.found()
if has_shellexec
  plugin_shellexec = shared_library('shellexec', shellexec_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [jansson_dep]
  )
endif

summary({'shell commands plugin': has_shellexec}, bool_yn: true, section: 'Plugins')
