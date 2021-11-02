sndfile_sources = [
  'sndfile.c'
]

libsndfile_dep = dependency('sndfile', required: get_option('plugin-sndfile'))

has_sndfile = libsndfile_dep.found()

if has_sndfile
  plugin_sndfile = shared_library('sndfile', sndfile_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, libsndfile_dep],
  )
endif

summary({'sndfile': has_sndfile}, bool_yn: true, section: 'Plugins')
