from setuptools import setup, Extension

functions_module = Extension(
    name='example',
    sources=['example.cpp'],
    extra_compile_args=["-O3","-fPIC"]
)

setup(ext_modules=[functions_module])