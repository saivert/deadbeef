liboggedit_sources = [
	'oggedit_internal.c',
    'oggedit_utils.c',
    'oggedit_art.c',
    'oggedit_opus.c',
    'oggedit_vorbis.c',
    'oggedit_flac.c'
]

liboggedit_cflags = []

ogg_dep = dependency('ogg', required: false)

if not ogg_dep.found()
  liboggedit_dep = dependency('', required: false)
  subdir_done()
endif

if cc.has_function('ogg_stream_flush_fill', dependencies: [ogg_dep])
  liboggedit_cflags += '-DHAVE_OGG_STREAM_FLUSH_FILL'
endif

liboggedit = static_library('oggedit', liboggedit_sources,
  c_args: liboggedit_cflags,
  include_directories: deadbeef_inc,
  install: false)

liboggedit_dep = declare_dependency(
  link_with: liboggedit,
  dependencies: [ogg_dep],
)