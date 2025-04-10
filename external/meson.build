mp4p_sources = [
    'mp4p/src/mp4p.c',
    'mp4p/src/mp4patomdata.c',
    'mp4p/src/mp4pfile.c',
]

libmp4p = static_library('mp4p', sources: mp4p_sources, include_directories: include_directories('mp4p/include'))

libmp4p_dep = declare_dependency(link_with: libmp4p, include_directories: include_directories('mp4p/include'))


ddb_output_pw_cflags = ['-DPW_ENABLE_DEPRECATED']

if get_option('buildtype').startswith('debug')
  ddb_output_pw_cflags += '-DDDBPW_DEBUG'
endif

pipewire_dep = dependency('libpipewire-0.3')

has_pipewire = not get_option('plugin-pipewire').disabled() and pipewire_dep.found()

if has_pipewire
  shared_library('ddb_out_pw', 'ddb_output_pw/pw.c',
    dependencies : [dependency('libpipewire-0.3')],
    name_prefix: '',
    install: true,
    c_args: ddb_output_pw_cflags,
    include_directories: deadbeef_inc,
    install_dir: 'lib/deadbeef'
  )
endif

summary({'Pipewire output': has_pipewire}, bool_yn: true, section: 'Plugins')

has_dsplibretro = not get_option('plugin-dsplibretro').disabled()

if has_dsplibretro
  shared_library('ddb_dsp_libretro', 'ddb_dsp_libretro/libretro.cpp',
    name_prefix: '',
    install: true,
    include_directories: [deadbeef_inc, 'ddb_dsp_libretro/ppsimd'],
    install_dir: 'lib/deadbeef'
  )
endif

summary({'Libretro DSP': has_dsplibretro}, bool_yn: true, section: 'Plugins')
