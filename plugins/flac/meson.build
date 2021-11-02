flac_sources = [
  'flac.c'
]

libflac_dep = dependency('flac', required: get_option('plugin-flac'))

has_flac = libflac_dep.found()

flac_args = [
  '-DUSE_OGGEDIT=1',
]

if has_flac
  plugin_flac = shared_library('flac', flac_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: flac_args,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, libflac_dep, liboggedit_dep],
  )
endif

summary({'FLAC': has_flac}, bool_yn: true, section: 'Plugins')
