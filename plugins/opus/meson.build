
opus_sources = [
    'opus.c'
]

opus_dep = dependency('opus', required: get_option('plugin-opus'))
opusfile_dep = dependency('opusfile', required: get_option('plugin-opus'))

has_opus = opus_dep.found() and opusfile_dep.found() and liboggedit_dep.found()

if has_opus
plugin_opus = shared_library('opus', opus_sources,
name_prefix: '',
install : true,
install_dir: plugindir,
dependencies : [m_dep, opus_dep, opusfile_dep, liboggedit_dep],
)
endif

summary({'OPUS': has_opus}, bool_yn: true, section: 'Plugins')
