filereader_sources = [
    'filereader.c',
    'filereader.h'
]

libfilereader = static_library('filereader', filereader_sources)

libfilereader_dep = declare_dependency(link_with: libfilereader, include_directories: ['../../shared'])