wavpack_sources = [
  'wavpack.c'
]

wavpack_dep = dependency('wavpack', required: get_option('plugin-wavpack'))

has_wavpack = wavpack_dep.found()

if has_wavpack
  shared_library('wavpack', wavpack_sources,
    name_prefix: '',
    install : true,
    install_dir: plugindir,
    include_directories: [deadbeef_inc],
    dependencies: [wavpack_dep]
  )
endif

summary({'Wavpack player': has_wavpack}, bool_yn: true, section: 'Plugins')
