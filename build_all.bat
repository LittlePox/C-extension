:loop
del build\lib.win-amd64-3.8\*.pyd
python setup.py build
pause
goto loop