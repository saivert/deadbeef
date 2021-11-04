
alsa_sources = [
  'alsa.c'
]

alsa_dep = dependency('alsa', version : '>=1.1.7', required: get_option('plugin-alsa'))

has_alsa = alsa_dep.found()

if has_alsa
plugin_alsa = shared_library('alsa', alsa_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, pthread_lib, alsa_dep],
)
endif

summary({'ALSA': has_alsa}, bool_yn: true, section: 'Plugins')
