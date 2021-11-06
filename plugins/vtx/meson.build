vtx_sources = [
  'vtx.c',
  'ay8912.c',
  'ayemu_8912.h',
  'ayemu.h',
  'ayemu_vtxfile.h',
  'lh5dec.c',
  'vtxfile.c'
]

has_vtx = not get_option('plugin-vtx').disabled()

if has_vtx
  plugin_vtx = shared_library('vtx', vtx_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  )
endif

summary({'vtx file player (ay8910/12 emulation)': has_vtx}, bool_yn: true, section: 'Plugins')
