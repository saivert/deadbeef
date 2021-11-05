vfs_zip_sources = [
  'vfs_zip.c'
]

zlib_dep = dependency('zlib', required: get_option('plugin-vfs-zip'))
libzip_dep = dependency('libzip', required: get_option('plugin-vfs-zip'))

has_vfs_zip = zlib_dep.found() and libzip_dep.found()

if has_vfs_zip
  plugin_vfs_zip = shared_library('vfs_zip', vfs_zip_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [zlib_dep, libzip_dep],
  )
endif

summary({'zip archive support': has_vfs_zip}, bool_yn: true, section: 'Plugins')
