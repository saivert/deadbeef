
vorbis_sources = [
  'vorbis.c'
]

vorbis_dep = dependency('vorbis', required: get_option('plugin-vorbis'))
vorbisfile_dep = dependency('vorbisfile', required: get_option('plugin-vorbis'))

has_vorbis = vorbis_dep.found() and vorbisfile_dep.found() and liboggedit_dep.found()

if has_vorbis
  plugin_vorbis = shared_library('vorbis', vorbis_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, vorbis_dep, vorbisfile_dep, liboggedit_dep],
  )
endif

summary({'Vorbis': has_vorbis}, bool_yn: true, section: 'Plugins')
