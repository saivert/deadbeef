
mp3mad_sources = [
  'mp3_mad.c'
]

mp3_mpg123_sources = [
  'mp3_mpg123.c'
]

mp3_sources = [
  'mp3.c',
  'mp3parser.c'
]

mp3_libs_list = []
mp3_cargs = []
mp3_deps_list = []

mad_dep = dependency('mad', required: false)
mpg123_dep = dependency('mpg123', required: false)

has_mp3 = false

if mad_dep.found() and not get_option('plugin-mp3').disabled()
  mp3_sources += mp3mad_sources
  mp3_libs_list += 'libmad'
  mp3_cargs += '-DUSE_LIBMAD=1'
  has_mp3 = true
endif

if mpg123_dep.found() and not get_option('plugin-mp3').disabled()
  mp3_sources += mpg123_sources
  mp3_libs_list += 'libmpg123'
  mp3_cargs += '-DUSE_LIBMPG123=1'
  has_mp3 = true
endif

mp3_summary = {'MP3': has_mp3}

if has_mp3
  plugin_mp3 = shared_library('mp3', mp3_sources,
  name_prefix: '',
  install : true,
  c_args: mp3_cargs,
  install_dir: plugindir,
  dependencies : [m_dep, mad_dep, mpg123_dep],
  )
  mp3_summary += {'MP3 libraries': mp3_libs_list}
endif

summary(mp3_summary, bool_yn: true, section: 'Plugins')
