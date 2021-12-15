aac_sources = [
  'aac.c',
  'aac_decoder_faad2.c',
  'aac_decoder_wrap.c',
  'aac_parser.c',
]

faad2_dep = dependency('faad2', required: get_option('plugin-aac'))
if not faad2_dep.found()
  faad2_dep = cc.find_library('faad2', required: get_option('plugin-aac'))
endif

has_aac = faad2_dep.found()

if has_aac
  plugin_aac = shared_library('aac', aac_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, faad2_dep, libmp4tagutil_dep, libmp4p_dep],
  )
endif

summary({'AAC': has_aac}, bool_yn: true, section: 'Plugins')
