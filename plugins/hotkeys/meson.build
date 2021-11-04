hotkeys_sources = [
  'hotkeys.c',
  'hotkeys.h',
  'actionhandlers.c',
  'actionhandlers.h'
]


if host_machine.system() != 'windows'
  xlib_dep = dependency('X11', required: get_option('plugin-hotkeys'))
  has_hotkeys = xlib_dep.found()
else
  xlib_dep = []
  has_hotkeys = not get_option('plugin-hotkeys').disabled()
endif

if has_hotkeys
  plugin_hotkeys = shared_library('hotkeys', hotkeys_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [xlib_dep, libparser_dep],
  )
endif

summary({'Local and global hotkeys support': has_hotkeys}, bool_yn: true, section: 'Plugins')
