notify_sources = [
  'notify.c'
]


dbus_dep = dependency('dbus-1', required: get_option('plugin-notify'))

has_notify = dbus_dep.found()

if has_notify
  plugin_notify = shared_library('notify', notify_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [dbus_dep, dependency('blocks'), cc.find_library('dispatch')]
  )
endif

summary({'notification-daemon support plugin': has_notify}, bool_yn: true, section: 'Plugins')
