libtrkpropertiesutil = static_library('trkpropertiesutil', 'trkproperties_shared.c')
libeqpreset = static_library('eqpreset', 'eqpreset.c')
libmp4tagutil = static_library('mp4tagutil', 'mp4tagutil.c', include_directories: include_directories('../external/mp4p/include'))
libctmap = static_library('ctmap', 'ctmap.c')
libdeletefromdisk = static_library('deletefromdisk', 'deletefromdisk.c')
libtftintutil = static_library('tftintutil', 'tftintutil.c')

libmp4tagutil_dep = declare_dependency(link_with: libmp4tagutil, include_directories: include_directories('../external/mp4p/include'))
