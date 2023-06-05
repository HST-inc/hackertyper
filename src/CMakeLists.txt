project (hackertyper)

if (WIN32)
    add_executable(hackertyper win_main.cpp termcolor.hpp)
endif (WIN32)
if (UNIX)
    add_executable(hackertyper unix_main.cpp conio.h termcolor.hpp)
endif(UNIX)