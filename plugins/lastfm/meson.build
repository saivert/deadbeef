lastfm_sources = [
  'lastfm.c'
]

has_lastfm = curl_dep.found() and not get_option('plugin-lastfm').disabled()

if has_lastfm
  plugin_lastfm = shared_library('lastfm', lastfm_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [curl_dep, dependency('blocks'), cc.find_library('dispatch')],
  )
endif

summary({'Last.fm scrobbling': has_lastfm}, bool_yn: true, section: 'Plugins')
