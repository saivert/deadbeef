
alsa_sources = [
    'alsa.c'
]

summary({'ALSA': need_alsa}, bool_yn: true, section: 'Plugins')

plugin_alsa = shared_library('alsa', alsa_sources,
  name_prefix: '',
#  version : libversion,
#  soversion : soversion,
#  c_args : libpipewire_c_args,
#  include_directories : [pipewire_inc, configinc, spa_inc, includes_inc],
  install : true,
  install_dir: plugindir,
  dependencies : [m_dep, pthread_lib, alsa_dep],
)
