tta_sources = [
  'ttaplug.c',
  'filter.h',
  'ttadec.c',
  'ttadec.h'
]

has_tta = not get_option('plugin-tta').disabled()
if has_tta
  plugin_tta = shared_library('tta', tta_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: [deadbeef_inc],
  )
endif

summary({'TTA player plugin': has_tta}, bool_yn: true, section: 'Plugins')
