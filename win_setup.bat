set SETUP_PATH=%userprofile%\.hackertyper
mkdir %SETUP_PATH%
g++ -o %SETUP_PATH%\hackertyper src/win_main.cpp
copy data/sample.c %SETUP_PATH%\sample.c
