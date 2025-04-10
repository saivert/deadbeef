shn_sources = [
  'shnplugin.c',
  'libshn/array.c',
  'libshn/convert.c',
  'libshn/misc.c',
  'libshn/output.c',
  'libshn/seek.c',
  'libshn/shorten.c',
  'libshn/sulawalaw.c',
  'libshn/vario.c',
  'libshn/wave.c'
]

has_shn = not get_option('plugin-shn').disabled()
if has_shn
  shared_library('ddb_shn', shn_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: [deadbeef_inc, 'libshn'],
    dependencies: [m_dep]
  )
endif

summary({'SHN plugin based on xmms-shn': has_shn}, bool_yn: true, section: 'Plugins')

