project('minishell', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

cc = meson.get_compiler('c')

add_project_arguments(cc.get_supported_arguments([
    '-Wundef',
    '-Wlogical-op',
    '-Wmissing-include-dirs',
    '-Wold-style-definition',
    '-Wpointer-arith',
    '-Winit-self',
    '-Wfloat-equal',
    '-Wstrict-prototypes',
    '-Wredundant-decls',
    '-Wimplicit-fallthrough=2',
    '-Wendif-labels',
    '-Wstrict-aliasing=2',
    '-Woverflow',
    '-Wformat=2',
    '-Wmissing-prototypes',

    '-Wno-missing-braces',
    '-Wno-missing-field-initializers',
    '-Wno-unused-parameter',
    '-Wno-unused-result', # fuck you glibc, and gcc, and the little dog, too
    '-Wno-format-overflow', # causes false positives with gcc
]), language: 'c')

# Check readline is installed
if get_option('readline-provider') == 'readline'
    readline = cc.find_library('readline', required: get_option('readline'))
    if readline.found()
        add_project_arguments('-DHAVE_READLINE', language: 'c')
    endif

    if cc.has_function('rl_replace_line', prefix: '#include <stdio.h>\n #include <readline/readline.h>', dependencies: [readline])
        add_project_arguments('-DHAVE_READLINE_REPLACE_LINE', language: 'c')
    endif
else # editline
    readline = dependency('libedit', required: get_option('readline'))
    if readline.found()
        add_project_arguments('-DHAVE_EDITLINE', language: 'c')
    endif
endif

# Define include directories
inc = include_directories('include')

shell_deps = []
shell_files = [
    'src/main.c'
]

if readline.found()
    shell_deps += [readline]
endif

exe = executable(
    'minishell',
    files(shell_files),
    dependencies: shell_deps,
    install: true,
)

status = [
    '',
    'Features:',
    '  readline: @0@'.format(readline.found())
]
message('\n'.join(status))
