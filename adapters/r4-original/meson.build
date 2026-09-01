custom_target(
  'steel-r4-original',
  input: steel_nds,
  output: 'steel-r4-original.nds',
  command: [
    'python',
    meson.project_source_root() / 'tools' / 'dldi.py',
    '@INPUT@',
    '@OUTPUT@',
    meson.current_source_dir() / 'r4-original.dldi',
  ],
  build_by_default: true,
)
