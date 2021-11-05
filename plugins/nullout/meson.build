nullout_sources = [
  'nullout.c'
]

has_nullout = not get_option('plugin-nullout').disabled()

if has_nullout
  plugin_nullout = shared_library('nullout', nullout_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  )
endif

summary({'NULL output': has_nullout}, bool_yn: true, section: 'Plugins')
