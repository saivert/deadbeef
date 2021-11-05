mms_sources = [
  'mmsplug.c',
	'libmms/mms.c',
	'libmms/mmsh.c',
	'libmms/mmsx.c',
	'libmms/uri.c',
	'libmms/asfheader.h',
	'libmms/bswap.h',
	'libmms/mms-common.h',
	'libmms/mms.h',
	'libmms/mmsh.h',
	'libmms/mmsio.h',
	'libmms/mmsx.h',
	'libmms/uri.h'
]

has_mms = not get_option('plugin-mms').disabled()

if has_mms
  plugin_mms = shared_library('mms', mms_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  )
endif

summary({'mms streaming support': has_mms}, bool_yn: true, section: 'Plugins')
