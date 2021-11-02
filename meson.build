project('deadbeef', ['c' ],
  version : 'devel',
  license : [ 'GPL-2.0-only' ],
  meson_version : '>= 0.54.0',
  default_options : [ 'warning_level=0',
                      'c_std=c99',
                      'b_pie=true',
                      'libdir=lib',
                      'buildtype=debugoptimized' ])

deadbeef_version = meson.project_version()

cc = meson.get_compiler('c')

if cc.get_id() != 'clang'
    error('This project requires the clang compiler! Hint: use --native=native-clang.txt')
endif

cc_flags = [
  '-fblocks',
  '-D_GNU_SOURCE',
  '-DDDB_WARN_DEPRECATED=1',
  '-DHAVE_CONFIG_H=1'
]
add_project_arguments(cc.get_supported_arguments(cc_flags), language: 'c')

i18n = import('i18n')

gettext_package = 'deadbeef'
add_project_arguments('-DGETTEXT_PACKAGE=' + gettext_package, language: 'c')


cdata = configuration_data()
prefix = get_option('prefix')
cdata.set_quoted('PREFIX', prefix)
cdata.set_quoted('LOCALEDIR', join_paths(prefix, get_option('localedir')))
cdata.set_quoted('LIBDIR', join_paths(prefix, get_option('libdir')))
cdata.set_quoted('DOCDIR', join_paths(prefix, get_option('datadir'), 'doc', 'deadbeef'))
cdata.set_quoted('PACKAGE_BUGREPORT', '')
cdata.set_quoted('PACKAGE_NAME', 'deadbeef')
cdata.set_quoted('PACKAGE_STRING', 'deadbeef devel')
cdata.set_quoted('PACKAGE_TARNAME', 'deadbeef')
cdata.set_quoted('PACKAGE_URL', '')
cdata.set_quoted('PACKAGE_VERSION', deadbeef_version)
cdata.set_quoted('VERSION', deadbeef_version)
cdata.set_quoted('PACKAGE', gettext_package)
cdata.set('ENABLE_NLS', 1)

summary({
  'prefix': get_option('prefix'),
  'libdir': get_option('libdir'),
  'localedir': get_option('localedir'),
  'bindir': get_option('bindir'),
  'docdir': join_paths(get_option('datadir'), 'doc', 'deadbeef'),
  }, section: 'Directories')

check_headers = [['dlfcn.h','HAVE_DLFCN_H'],
  ['inttypes.h', 'HAVE_INTTYPES_H'],
  ['memory.h', 'HAVE_MEMORY_H'],
  ['poll.h', 'HAVE_POLL_H'],
  ['stddef.h', 'HAVE_STDDEF_H'],
  ['stdint.h', 'HAVE_STDINT_H'],
  ['stdio_ext.h', 'HAVE_STDIO_EXT_H'],
  ['strings.h', 'HAVE_STRINGS_H'],
  ['string.h', 'HAVE_STRING_H'],
  ['sys/mount.h', 'HAVE_SYS_MOUNT_H'],
  ['sys/param.h', 'HAVE_SYS_PARAM_H'],
  ['sys/poll.h', 'HAVE_SYS_POLL_H'],
  ['sys/prctl.h', 'HAVE_SYS_PRCTL_H'],
  ['sys/random.h', 'HAVE_SYS_RANDOM_H'],
  ['sys/socket.h', 'HAVE_SYS_SOCKET_H'],
  ['sys/stat.h', 'HAVE_SYS_STAT_H'],
  ['sys/times.h', 'HAVE_SYS_TIMES_H'],
  ['sys/time.h', 'HAVE_SYS_TIME_H'],
  ['sys/types.h', 'HAVE_SYS_TYPES_H'],
  ['sys/utsname.h', 'HAVE_SYS_UTSNAME_H'],
  ['sys/vfs.h', 'HAVE_SYS_VFS_H'],
  ['sys/wait.h', 'HAVE_SYS_WAIT_H'],
  ['pwd.h', 'HAVE_PWD_H'],
  ['ucontext.h', 'HAVE_UCONTEXT_H'],
  ['unistd.h', 'HAVE_UNISTD_H'],
  ['alloca.h', 'HAVE_ALLOCA_H'],
]

foreach h : check_headers
  if cc.has_header(h.get(0))
    cdata.set(h.get(1), 1)
  endif
endforeach

pthread_lib = dependency('threads')
dl_lib = cc.find_library('dl', required : false)
m_dep = cc.find_library('m', required : false)

if cc.has_function('log2', dependencies: [m_dep])
  cdata.set('HAVE_LOG2', 1)
endif

if host_machine.cpu() == 'x86_64' and host_machine.system() == 'linux'
  cdata.set('ARCH_X86_64', '1')
  YASM_FLAGS='-f elf -D ARCH_X86_64 -m amd64'
else
  error('Unsupported platform!')
endif

if cc.has_header_symbol('string.h', 'strndupa', args : [ '-D_GNU_SOURCE' ])
  cdata.set('HAVE_STRNDUPA', 1)
endif
if cc.has_function('poll', prefix : '#include<poll.h>')
  cdata.set('HAVE_POLL', 1)
endif
if cc.has_function('pselect', prefix : '#include<sys/select.h>')
  cdata.set('HAVE_PSELECT', 1)
endif
cdata.set('HAVE_MMAP', 1)

cdata.set('HAVE_POSIX_PRINTF', 1)

configure_file(output : 'config.h',
               configuration : cdata)

deadbeef_inc = include_directories(
  'external/mp4p/include',
  'plugins/libparser',
  'scope',
  'analyzer',
  '.'
)

# Shared static libraries
subdir('shared')

# Plugins
plugindir = 'lib/deadbeef'

jansson_dep = cc.find_library('jansson')

# Output plugins
subdir('plugins/alsa')
subdir('plugins/pulse')

# Input plugins
subdir('plugins/mp3')
subdir('external')
subdir('plugins/aac')
subdir('plugins/liboggedit')
subdir('plugins/opus')
subdir('plugins/vorbis')

# GUI plugins
subdir('plugins/gtkui')

## Main binary

deadbeef_sources = [
  'main.c',
  'plugins.c',
  'cueutil.c',
  'playlist.c',
  'plmeta.c',
  'pltmeta.c',
  'streamer.c',
  'dsp.c',
  'streamreader.c',
  'premix.c',
  'messagepump.c',
  'conf.c',
  'threading_pthread.c',
  'volume.c',
  'junklib.c',
  'utf8.c',
  'vfs.c',
  'vfs_stdio.c',
  'md5/md5.c',
  'metacache.c',
  'ringbuf.c',
  'dsppreset.c',
  'replaygain.c',
  'fft.c',
  'handler.c',
  'escape.c',
  'tf.c',
  'playqueue.c',
  'sort.c',
  'logger.c',
  'external/wcwidth/wcwidth.c',
  'playmodes.c',
  'viz.c',
  'decodedblock.c',
  'scope/scope.c',
  'analyzer/analyzer.c',
  'plugins/libparser/parser.c',
  'shared/ctmap.c'
]


deadbeef_headers = [
    'deadbeef.h'
]

install_headers(deadbeef_headers, subdir : 'deadbeef')

install_data(
  'README', 'help.txt', 'about.txt', 'translators.txt', 'ChangeLog',
  'COPYING.GPLv2', 'COPYING.LGPLv2.1', 'translation/help.ru.txt',
  install_dir: join_paths(get_option('datadir'), 'doc', meson.project_name()),
)

subdir('po')
subdir('pixmaps')

i18n.merge_file(
  input: 'deadbeef.desktop.in',
  output: 'deadbeef.desktop',
  type: 'desktop',
  po_dir: 'po',
  install: true,
  install_dir: get_option('datadir') / 'applications'
)

deadbeef_exec = executable('deadbeef',
  deadbeef_sources,
  install: true,
  #c_args : cc_flags,
  include_directories : [deadbeef_inc],
  dependencies : [pthread_lib, m_dep, dl_lib, dependency('blocks'), cc.find_library('dispatch')],
)
