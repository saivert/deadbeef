vfs_curl_sources = [
  'vfs_curl.c',
  'vfs_curl.h'
]

has_vfs_curl = curl_dep.found() and not get_option('plugin-vfs-curl').disabled()

if has_vfs_curl
  plugin_vfs_curl = shared_library('vfs_curl', vfs_curl_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [curl_dep],
  )
endif

summary({'HTTP streaming vfs plugin': has_vfs_curl}, bool_yn: true, section: 'Plugins')
