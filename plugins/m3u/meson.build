m3u_sources = [
  'm3u.c',
  'm3u.h'
]

has_m3u = not get_option('plugin-m3u').disabled()

if has_m3u
  plugin_m3u = shared_library('m3u', m3u_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep],
  )
endif

summary({'M3U and PLS support': has_m3u}, bool_yn: true, section: 'Plugins')
