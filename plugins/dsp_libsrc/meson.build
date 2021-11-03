dsp_libsrc_sources = [
  'src.c',
  'src.h'
]

libsamplerate_dep = dependency('samplerate', required: get_option('plugin-dsp_libsrc'))

has_dsp_libsrc = libsamplerate_dep.found()

if has_dsp_libsrc
  plugin_dsp_libsrc = shared_library('dsp_libsrc', dsp_libsrc_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  dependencies : [libsamplerate_dep],
  )
endif

summary({'dsp_libsrc': has_dsp_libsrc}, bool_yn: true, section: 'Plugins')
