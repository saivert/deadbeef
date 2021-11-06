wma_sources = [
  'wma_plugin.c',
	'asfheader.c',
	'libasf/asf.c',
	'libasf/asf.h',
	'libwma/wmafixed.c',
	'libwma/wmadeci.c',
	'libwma/fft-ffmpeg.c',
	'libwma/mdct_lookup.c',
	'libwma/mdct.c',
	'libwma/ffmpeg_bitstream.c',
	'libwma/asm_arm.h',
	'libwma/fft-ffmpeg_arm.h',
	'libwma/types.h',
	'libwma/codeclib_misc.h',
	'libwma/fft.h',
	'libwma/wmadata.h',
	'libwma/ffmpeg_get_bits.h',
	'libwma/mdct.h',
	'libwma/wmadec.h',
	'libwma/ffmpeg_intreadwrite.h',
	'libwma/mdct_lookup.h',
	'libwma/wmafixed.h'
]

has_wma = not get_option('plugin-wma').disabled()

if has_wma
  plugin_wma = shared_library('wma', wma_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [m_dep]
  )
endif

summary({'WMA plugin': has_wma}, bool_yn: true, section: 'Plugins')
