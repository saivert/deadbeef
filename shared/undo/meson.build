undo_sources = [
    'undobuffer.c',
    'undobuffer.h',
    'undomanager.c',
    'undomanager.h'
]

libundo = static_library('undo', undo_sources)

libundo_dep = declare_dependency(link_with: libundo, include_directories: ['../../shared'])
