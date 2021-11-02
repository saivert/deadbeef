dca_sources = [
  'dcaplug.c',
  'extract_dca.c',
  'gettimeofday.c',
  'parse.c',
  'bitstream.c',
  'downmix.c',
  'audio_out.h',
  'dca.h',
  'dts.h',
  'gettimeofday.h',
  'tendra.h',
  'dca_internal.h',
  'tables_adpcm.h',
  'tables_fir.h',
  'tables.h',
  'tables_huffman.h',
  'tables_quantization.h',
  'tables_vq.h',
  'bitstream.h',
]

has_dca = not get_option('plugin-dca').disabled()

if has_dca
  plugin_dca = shared_library('dca', dca_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep],
  )
endif

summary({'dca (DTS Audio)': has_dca}, bool_yn: true, section: 'Plugins')
