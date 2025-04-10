vtx_sources = [
  'vtx.c',
  'libayemu/ay8912.c',
  'libayemu/ayemu_8912.h',
  'libayemu/ayemu.h',
  'libayemu/ayemu_vtxfile.h',
  'libayemu/lh5dec.c',
  'libayemu/vtxfile.c'
]

has_vtx = not get_option('plugin-vtx').disabled()

if has_vtx
  plugin_vtx = shared_library('vtx', vtx_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc, 'libayemu'],
  )
endif

summary({'vtx file player (ay8910/12 emulation)': has_vtx}, bool_yn: true, section: 'Plugins')
