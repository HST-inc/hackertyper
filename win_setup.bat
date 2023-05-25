set SETUP_PATH=%userprofile%\.hackertyper
mkdir %SETUP_PATH%
g++ -o %SETUP_PATH%\hackertyper win_main.cpp
copy sample.c %SETUP_PATH%\sample.c
