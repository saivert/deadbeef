wildmidi_sources = [
  'wildmidiplug.c',
  'src/wildmidi_lib.c',
  'include/wildmidi_lib.h'
]

has_wildmidi = not get_option('plugin-wildmidi').disabled()

if has_wildmidi
  plugin_wildmidi = shared_library('wildmidi', wildmidi_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: ['-DWILDMIDI_VERSION="0.2.2"', '-DWILDMIDILIB_VERSION="0.2.2"', '-DTIMIDITY_CFG="/etc/timidity.conf"'],
  include_directories: [deadbeef_inc, 'include'],
  dependencies: [m_dep]
  )
endif

summary({'WildMidi player': has_wildmidi}, bool_yn: true, section: 'Plugins')
