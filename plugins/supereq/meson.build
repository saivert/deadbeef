supereq_sources = [
  'supereq.c',
  'Equ.cpp',
  'Equ.h',
  'Fftsg_fl.c',
  'paramlist.hpp'
]

has_supereq = not get_option('plugin-supereq').disabled()
if has_supereq
  plugin_supereq = shared_library('supereq', supereq_sources,
  name_prefix: '',
  install : true,
  c_args: ['-DUSE_OOURA'],
  cpp_args: ['-fno-exceptions', '-fno-rtti', '-fno-unwind-tables', '-DUSE_OOURA'],
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  dependencies: [m_dep]
  )
endif

summary({'Equalizer based on Super EQ library by Naoki Shibata': has_supereq}, bool_yn: true, section: 'Plugins')
