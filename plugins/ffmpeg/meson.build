ffmpeg_sources = [
  'ffmpeg.c'
]

needs_ffmpeg_plugin = get_option('plugin-ffmpeg')

libavcodec_dep = dependency('libavcodec', version: '>=51.0.0', required: needs_ffmpeg_plugin)
libavformat_dep = dependency('libavformat', version: '>=52.0.0', required: needs_ffmpeg_plugin)
libavutil_dep = dependency('libavutil', required: needs_ffmpeg_plugin)

has_ffmpeg = libavcodec_dep.found() and libavformat_dep.found() and libavutil_dep.found()

if has_ffmpeg
  plugin_ffmpeg = shared_library('ffmpeg', ffmpeg_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies : [m_dep, libavcodec_dep, libavformat_dep, libavutil_dep],
  )
endif

summary({'ffmpeg': has_ffmpeg}, bool_yn: true, section: 'Plugins')
