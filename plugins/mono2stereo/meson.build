mono2stereo_sources = [
  'mono2stereo.c'
]

has_mono2stereo = not get_option('plugin-mono2stereo').disabled()

if has_mono2stereo
  plugin_mono2stereo = shared_library('ddb_mono2stereo', mono2stereo_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  )
endif

summary({'mono2stereo DSP plugin': has_mono2stereo}, bool_yn: true, section: 'Plugins')
