scriptable_sources = [
    'scriptable_model.c',
    'scriptable_model.h',
    'scriptable.c',
    'scriptable.h'
]


scriptable_include_dirs = include_directories(
  '../../shared'
)

libscriptable = static_library('scriptable', scriptable_sources, include_directories: [scriptable_include_dirs, deadbeef_header_inc])

libscriptable_dep = declare_dependency(link_with: libscriptable, include_directories: [scriptable_include_dirs, deadbeef_header_inc])
