notify_sources = [
  'notify.c'
]


dbus_dep = dependency('dbus-1', required: get_option('plugin-notify'))

#glib-2.0 >= 2.26 gio-2.0 gdk-pixbuf-2.0

glib2_dep = dependency('glib-2.0', version: '>=2.26', required: get_option('plugin-notify'))
gdk_pixbuf_dep = dependency('gdk-pixbuf-2.0', required: get_option('plugin-notify'))

has_notify = dbus_dep.found() and glib2_dep.found() and gdk_pixbuf_dep.found()

if has_notify
  plugin_notify = shared_library('notify', notify_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [dbus_dep, glib2_dep, gdk_pixbuf_dep, dependency('blocks'), cc.find_library('dispatch')]
  )
endif

summary({'notification-daemon support plugin': has_notify}, bool_yn: true, section: 'Plugins')
