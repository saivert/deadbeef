musepack_sources = [
  'musepack.c',
  'huffman.c',
  'mpc_bits_reader.c',
  'mpc_decoder.c',
  'mpc_demux.c',
  'mpc_reader.c',
  'requant.c',
  'streaminfo.c',
  'synth_filter.c',
  'crc32.c',
  'decoder.h',
  'huffman.h',
  'internal.h',
  'mpc_bits_reader.h',
  'mpc/mpcdec.h',
  'mpcdec_math.h',
  'mpc/reader.h',
  'requant.h',
  'mpc/streaminfo.h',
  'mpc/mpc_types.h',
  'mpc/minimax.h'
]

has_musepack = not get_option('plugin-musepack').disabled()

if has_musepack
  plugin_musepack = shared_library('musepack', musepack_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [m_dep]
  )
endif

summary({'musepack player plugin': has_musepack}, bool_yn: true, section: 'Plugins')
