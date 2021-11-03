soundtouch_sources = [
  'plugin.c',
  'st.cpp',
  'st.h',
  'soundtouch/include/BPMDetect.h',
  'soundtouch/include/FIFOSampleBuffer.h',
  'soundtouch/include/FIFOSamplePipe.h',
  'soundtouch/include/STTypes.h',
  'soundtouch/include/SoundTouch.h',
  'soundtouch/include/soundtouch_config.h',
  'soundtouch/source/SoundTouch/AAFilter.cpp',
  'soundtouch/source/SoundTouch/AAFilter.h',
  'soundtouch/source/SoundTouch/BPMDetect.cpp',
  'soundtouch/source/SoundTouch/FIFOSampleBuffer.cpp',
  'soundtouch/source/SoundTouch/FIRFilter.cpp',
  'soundtouch/source/SoundTouch/FIRFilter.h',
  'soundtouch/source/SoundTouch/InterpolateCubic.cpp',
  'soundtouch/source/SoundTouch/InterpolateCubic.h',
  'soundtouch/source/SoundTouch/InterpolateLinear.cpp',
  'soundtouch/source/SoundTouch/InterpolateLinear.h',
  'soundtouch/source/SoundTouch/InterpolateShannon.cpp',
  'soundtouch/source/SoundTouch/InterpolateShannon.h',
  'soundtouch/source/SoundTouch/PeakFinder.cpp',
  'soundtouch/source/SoundTouch/PeakFinder.h',
  'soundtouch/source/SoundTouch/RateTransposer.cpp',
  'soundtouch/source/SoundTouch/RateTransposer.h',
  'soundtouch/source/SoundTouch/SoundTouch.cpp',
  'soundtouch/source/SoundTouch/TDStretch.cpp',
  'soundtouch/source/SoundTouch/TDStretch.h',
  'soundtouch/source/SoundTouch/cpu_detect.h',
  'soundtouch/source/SoundTouch/cpu_detect_x86.cpp',
  'soundtouch/source/SoundTouch/mmx_optimized.cpp',
  'soundtouch/source/SoundTouch/sse_optimized.cpp'
]

has_soundtouch = not get_option('plugin-soundtouch').disabled()

if has_soundtouch
  plugin_soundtouch = shared_library('ddb_soundtouch', soundtouch_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: include_directories('soundtouch/include'),
  )
endif

summary({'soundtouch': has_soundtouch}, bool_yn: true, section: 'Plugins')
