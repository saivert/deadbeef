mp4p_sources = [
    'mp4p/src/mp4p.c',
    'mp4p/src/mp4patomdata.c',
    'mp4p/src/mp4pfile.c',
]

libmp4p = static_library('mp4p', sources: mp4p_sources, include_directories: include_directories('mp4p/include'))

libmp4p_dep = declare_dependency(link_with: libmp4p, include_directories: include_directories('mp4p/include'))
