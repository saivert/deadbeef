converter_data = [
	'convpresets/AAC_VBR_192Kbps_(Nero_FAAC).txt',
	'convpresets/AAC_VBR_256Kbps_(Nero_FAAC).txt',
	'convpresets/AAC_VBR_320Kbps_(Nero_FAAC).txt',
	'convpresets/FLAC_(compression_level_5).txt',
	'convpresets/MP3_CBR_320_Kbps_(Lame).txt',
	'convpresets/MP3_VBR_192Kbps_(Lame).txt',
	'convpresets/MS_RIFF_WAV.txt',
	'convpresets/MusePack.txt',
	'convpresets/Ogg_FLAC.txt',
	'convpresets/Ogg_VBR_192Kbps.txt',
	'convpresets/Ogg_VBR_256Kbps.txt',
	'convpresets/Ogg_VBR_320Kbps.txt',
	'convpresets/Opus.txt',
	'convpresets/TTA.txt',
	'convpresets/WavPack.txt',
	'convpresets/ALAC.txt',
	'convpresets/File_Copy.txt',
	'convpresets/File_Move.txt'

]

converter_sources = [
  'converter.c',
  'converter.h'
]

convertergui_sources = [
  'convgui.c',
  'interface.c',
  'support.c',
  'callbacks.h',
  'converter.h',
  'interface.h',
  'support.h'
]

has_converter = not get_option('plugin-converter').disabled()

if has_converter
  install_data(
    converter_data,
    install_dir: join_paths(get_option('libdir'), 'deadbeef', 'convpresets'),
  )

  plugin_converter = shared_library('converter', converter_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [libmp4tagutil_dep, libmp4p_dep]
  )
endif

if has_converter and gtk2_dep.found()
  plugin_converterui_gtk2 = shared_library('converter_gtk2', convertergui_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk2_dep]
  )
endif

if has_converter and gtk3_dep.found()
  plugin_converterui_gtk3 = shared_library('converter_gtk3', convertergui_sources,
  name_prefix: '',
  install : true,
  install_dir: plugindir,
  include_directories: deadbeef_inc,
  dependencies: [gtk3_dep]
  )
endif

summary({'converter plugin': has_converter}, bool_yn: true, section: 'Plugins')
