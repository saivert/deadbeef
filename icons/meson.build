foreach s: [16, 22, 24, 32, 36, 48, 64, 72, 96, 128, 192, 256]
  subdir = '@0@x@0@'.format(s.to_string())
  install_data('@0@/deadbeef.png'.format(subdir),
    install_dir: join_paths(get_option('datadir'), 'icons', 'hicolor', subdir, 'apps'))
endforeach


install_data('scalable/deadbeef.svg'.format(subdir),
  install_dir: join_paths(get_option('datadir'), 'icons', 'hicolor', 'scalable', 'apps'))
