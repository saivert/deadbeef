dca_sources = [
  'dcaplug.c',
  'libdca/bitstream.c',
  'libdca/downmix.c',
  'libdca/extract_dca.c',
  'libdca/gettimeofday.c',
  'libdca/parse.c',
  'libdca/audio_out.h',
  'libdca/bitstream.h',
  'libdca/dca.h',
  'libdca/dca_internal.h',
  'libdca/dts.h',
  'libdca/gettimeofday.h',
  'libdca/tables.h',
  'libdca/tables_adpcm.h',
  'libdca/tables_fir.h',
  'libdca/tables_huffman.h',
  'libdca/tables_quantization.h',
  'libdca/tables_vq.h',
  'libdca/tendra.h'
]

has_dca = not get_option('plugin-dca').disabled()

if has_dca
  plugin_dca = shared_library('dca', dca_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc, 'libdca'],
  dependencies : [m_dep],
  )
endif

summary({'dca (DTS Audio)': has_dca}, bool_yn: true, section: 'Plugins')
