shn_sources = [
  'array.c',
  'convert.c',
  'misc.c',
  'output.c',
  'seek.c',
  'shn.c',
  'shn.h',
  'shorten.c',
  'shorten.h',
  'sulawalaw.c',
  'vario.c',
  'wave.c',
  'bitshift.h'
]

has_shn = not get_option('plugin-shn').disabled()
if has_shn
  plugin_shn = shared_library('ddb_shn', shn_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [m_dep]
  )
endif

summary({'SHN plugin based on xmms-shn': has_shn}, bool_yn: true, section: 'Plugins')

