from setuptools import setup, Extension

functions_module = Extension(
    name='example',
    sources=['example.cpp'],
    extra_compile_args=["-O3","-fPIC"],
    include_dirs=[r'C:\Users\user\AppData\Local\Programs\Python\Python38\Lib\site-packages\pybind11\include']
)

setup(ext_modules=[functions_module])