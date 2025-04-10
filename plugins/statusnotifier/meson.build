statusnotifier_sources = [
  'statusnotifier.c',
  'statusnotifier.h',
  'ddb_statusnotifier.c',
  'ddb_statusnotifier.h'
]

has_statusnotifier = not get_option('plugin-statusnotifier').disabled()

glib2_dep = dependency('glib-2.0', version: '>=2.26', required: get_option('plugin-statusnotifier'))
gdk_pixbuf_dep = dependency('gdk-pixbuf-2.0', required: get_option('plugin-statusnotifier'))

if has_statusnotifier
  plugin_statusnotifier = shared_library('ddb_statusnotifier', statusnotifier_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_header_inc,
  dependencies: [glib2_dep, gdk_pixbuf_dep]
  )
endif

summary({'KDE Status notifier support': has_statusnotifier}, bool_yn: true, section: 'Plugins')
