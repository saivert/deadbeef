artwork_legacy_sources = [
  'artwork.c',
  'cache.c',
  'artwork_internal.c'
]

artwork_legacy_cargs = []
artwork_legacy_libs = []

if curl_dep.found()
  artwork_legacy_cargs += ['-DUSE_VFS_CURL']
  artwork_legacy_sources += ['musicbrainz.c', 'albumartorg.c', 'lastfm.c', 'wos.c', 'escape.c']
endif

install_headers('artwork.h', subdir : 'deadbeef')

imlib2_dep = dependency('imlib2', required: get_option('plugin-artwork-imlib2'))

libpng_dep = []
libjpeg_dep = []

if imlib2_dep.found()
  artwork_legacy_cargs += ['-DUSE_IMLIB2']
  has_artwork_legacy = true
else
  libpng_dep = dependency('libpng', required: false)
  libjpeg_dep = dependency('libjpeg', required: false)
  has_artwork_legacy = libpng_dep.found() and libjpeg_dep.found()
endif

if libflac_dep.found()
  artwork_legacy_cargs += ['-DUSE_METAFLAC']
endif

if ogg_dep.found()
  artwork_legacy_cargs += ['-DUSE_OGG=1']
endif

if has_artwork_legacy
plugin_artwork_legacy = shared_library('artwork', artwork_legacy_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: artwork_legacy_cargs,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, pthread_lib, libpng_dep, libjpeg_dep, libflac_dep, ogg_dep, imlib2_dep, libmp4tagutil_dep, libmp4p_dep],
)
endif

summary({'artwork': has_artwork_legacy, 'artwork-imlib2 enabled': imlib2_dep.found()}, bool_yn: true, section: 'Plugins')

