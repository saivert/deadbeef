ffap_sources = [
  'ffap.c'
]

yasm = find_program('yasm')

if yasm.found()

  gen = generator(yasm,
    output  : '@BASENAME@.o',
    arguments : YASM_FLAGS + ['-D', 'PIC',  '-o', '@OUTPUT@', '@INPUT@'])

  yasmobjs = gen.process(['dsputil_yasm.asm'])

  ffap_sources = [yasmobjs] + ffap_sources
endif

has_ffap = not get_option('plugin-ffap').disabled()

if has_ffap
  plugin_ffap = shared_library('ffap', ffap_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: ['-DHAVE_SSE2'],
  include_directories: deadbeef_inc,
  dependencies : [m_dep],
  )
endif

summary({'ffap (APE)': has_ffap}, bool_yn: true, section: 'Plugins')
