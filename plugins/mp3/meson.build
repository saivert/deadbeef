
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

mad_dep = cc.find_library('mad', required: false)
mpg123_dep = cc.find_library('mpg123', required: false)

if mad_dep.found()
  mp3_sources += mp3mad_sources
  mp3_libs_list += 'libmad'
  mp3_cargs += '-DUSE_LIBMAD=1'
endif

if mpg123_dep.found()
  mp3_sources += mpg123_sources
  mp3_libs_list += 'libmpg123'
  mp3_cargs += '-DUSE_LIBMPG123=1'
endif

has_mp3 = mad_dep.found() or mpg123_dep.found()

if has_mp3
plugin_mp3 = shared_library('mp3', mp3_sources,
name_prefix: '',
install : true,
c_args: mp3_cargs,
install_dir: plugindir,
dependencies : [m_dep, pthread_lib, mad_dep, mpg123_dep],
)
endif

summary({'MP3': has_mp3, 'MP3 libraries': mp3_libs_list}, bool_yn: true, section: 'Plugins')
