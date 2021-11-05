oss_sources = [
  'oss.c'
]

oss_cargs = []
has_oss_header = cc.has_header('sys/soundcard.h') or cc.has_header('soundcard.h')

if cc.has_header('sys/soundcard.h')
  oss_cargs += ['-DHAVE_SYS_SOUNDCARD_H']
endif

has_oss = not get_option('plugin-oss').disabled() and has_oss_header

if has_oss
  plugin_oss = shared_library('oss', oss_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: oss_cargs,
  include_directories: deadbeef_inc,
  )
endif

summary({'OSS output': has_oss}, bool_yn: true, section: 'Plugins')
