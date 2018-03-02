import py_compile 
fileName = raw_input('Please input the file name:')
py_compile.compile(fileName + '.py')