
mpris_sources = [
  'mpris.c',
  'mprisServer.c',
  'mprisServer.h'
]


mpris_deps = [
  dependency('glib-2.0', required: get_option('plugin-mpris')),
  dependency('gio-2.0', required: get_option('plugin-mpris')),
  dependency('gio-unix-2.0', required: get_option('plugin-mpris')),
  dependency('gthread-2.0', required: get_option('plugin-mpris')),
]

has_mpris_deps = true
foreach dep : mpris_deps
  if not dep.found()
    has_mpris_deps = false
    break
  endif
endforeach

has_mpris = has_mpris_deps and not get_option('plugin-mpris').disabled()

if has_mpris
  shared_library('mpris', mpris_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: deadbeef_inc,
    dependencies: mpris_deps
  )
endif

summary({'MPRIS support': has_mpris}, bool_yn: true, section: 'Plugins')

