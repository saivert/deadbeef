rg_scanner_sources = [
  'rg_scanner.c',
  'rg_scanner.h',
  'ebur128/ebur128.c',
  'ebur128/ebur128.h'
]

rg_scanner_cargs = []

if have_sse2
  rg_scanner_cargs += [sse2_args, '-mfpmath=sse', '-DHAVE_SSE2']
endif

has_rg_scanner = not get_option('plugin-rg_scanner').disabled()

if has_rg_scanner
  plugin_rg_scanner = shared_library('rg_scanner', rg_scanner_sources,
  name_prefix: '',
  install : true,
  c_args: rg_scanner_cargs,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [m_dep]
  )
endif

summary({'Plugin for ReplayGain scanner support': has_rg_scanner}, bool_yn: true, section: 'Plugins')
