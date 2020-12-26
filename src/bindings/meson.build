shiboken2 = find_program('shiboken2')
qmake = find_program('qmake-qt5','qmake')

python3_dep = python3.dependency(embed:true)
numpy_inc = run_command(python3, '-c', 'import numpy;print(numpy.get_include())').stdout().strip('\n')

qt5_modules = ['QtCore','QtGui','QtWidgets']

qt_headers_path = run_command(qmake, '-query', 'QT_INSTALL_HEADERS').stdout().strip('\n')
generated_srcs  = run_command(python3, 'src_list.py', 'meson').stdout().split(';')

modules_arg = '--modules=@0@'.format(','.join(qt5_modules))

shiboken2_build_flags = run_command(python3, 'shiboken-helper.py', '--includes', modules_arg).stdout().strip('\n').split(' ')
shiboken2_link_flags  = run_command(python3, 'shiboken-helper.py', '--libs', modules_arg).stdout().strip('\n').split(' ')
shiboken2_typesystem  = run_command(python3, 'shiboken-helper.py', '--typesystem').stdout().strip('\n')

socexplorer_bindings_incs = shiboken2_build_flags + [
    '-I'+meson.current_source_dir()+'/../',
    '-I'+meson.current_source_dir()+'/../../'+opaque_inc_dir,
    '-I'+python3.get_path('include'),
    '-I'+qt_headers_path
    ]

foreach mod:qt5_modules
    socexplorer_bindings_incs += ['-I'+qt_headers_path+'/'+mod]
endforeach

socexplorer_bindings_src = files('bindings.h', '../plugin/SocModule.hpp',
                                 '../plugin/SocModule.cpp','PySocModule.hpp',
                                 'PySocModule.cpp')

subdir('SocExplorerBindings')

shiboken_dep = declare_dependency(compile_args: shiboken2_build_flags,
                                  link_args: shiboken2_link_flags)

socexplorer_bindings_moc_files = qt5.preprocess(moc_headers : 'PySocModule.hpp',
                                                dependencies : [socexplorer_dep])


socexplorer_bindings = python3.extension_module('SocExplorerBindings',
            socexplorer_bindings_src,shiboken2_generator_out,
            socexplorer_bindings_moc_files,
            dependencies : [socexplorer_dep, python3_dep, shiboken_dep],
            include_directories : [numpy_inc]
)
