artwork_sources = [
  'artwork.c',
  'cache.c',
  'artwork_internal.c',
  'artwork_flac.c',
  'coverinfo.c',
]

artwork_cargs = []
artwork_libs = []

if curl_dep.found()
  artwork_cargs += ['-DUSE_VFS_CURL']
  artwork_sources += ['musicbrainz.c', 'albumartorg.c', 'lastfm.c', 'wos.c', 'escape.c']
endif

install_headers('artwork.h', subdir : 'deadbeef')

if libflac_dep.found()
  artwork_cargs += ['-DUSE_METAFLAC']
endif

vorbis_dep = dependency('vorbis', required: false)
vorbisfile_dep = dependency('vorbisfile', required: false)

if ogg_dep.found() and vorbis_dep.found() and vorbisfile_dep.found()
  artwork_cargs += ['-DUSE_OGG=1']
  artwork_sources += ['base64.c', 'artwork_ogg.c']
endif


has_artwork = not get_option('plugin-artwork').disabled() and curl_dep.found()

artwork_include_dirs = include_directories(
  '../../external/mp4p/include',
  '../../shared'
)

if has_artwork
plugin_artwork = shared_library('artwork', artwork_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  c_args: artwork_cargs,
  include_directories: [deadbeef_inc, artwork_include_dirs],
  dependencies : [m_dep, pthread_lib, libflac_dep, vorbis_dep, vorbisfile_dep, liboggedit_dep, libmp4tagutil_dep, libmp4p_dep, libdispatch_dep],
)
endif

summary({'artwork': has_artwork}, bool_yn: true, section: 'Plugins')

