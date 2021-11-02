alac_sources = [
  'alac_plugin.c',
  'alac.c'
]

has_alac = not get_option('plugin-alac').disabled()

if has_alac
  plugin_alac = shared_library('alac', alac_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, libmp4p_dep, libmp4tagutil_dep],
  )
endif

summary({'ALAC': has_alac}, bool_yn: true, section: 'Plugins')
