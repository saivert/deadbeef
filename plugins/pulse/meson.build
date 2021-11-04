
pulse_sources = [
  'pulse.c'
]

pulse_dep = dependency('libpulse-simple', required: get_option('plugin-pulse'))

has_pulse = pulse_dep.found()

if has_pulse
plugin_pulse = shared_library('pulse', pulse_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [pthread_lib, pulse_dep],
)
endif

summary({'PulseAudio': has_pulse}, bool_yn: true, section: 'Plugins')
