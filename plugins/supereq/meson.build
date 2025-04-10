supereq_sources = [
  'supereq.c',
  'libsupereq/Equ.cpp',
  'libsupereq/Equ.h',
  'libsupereq/Fftsg_fl.c',
  'libsupereq/paramlist.hpp'
]

has_supereq = not get_option('plugin-supereq').disabled()
if has_supereq
  shared_library('supereq', supereq_sources,
  name_prefix: '',
  install : true,
  c_args: ['-DUSE_OOURA'],
  cpp_args: ['-fno-exceptions', '-fno-rtti', '-fno-unwind-tables', '-DUSE_OOURA'],
  install_dir: plugindir,
  include_directories: [deadbeef_inc, 'libsupereq'],
  dependencies: [m_dep]
  )
endif

summary({'Equalizer based on Super EQ library by Naoki Shibata': has_supereq}, bool_yn: true, section: 'Plugins')
