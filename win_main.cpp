#include <conio.h>
#include "termcolor.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>

#define CONSOLE_GREEN termcolor::color<0, 154, 0>

const std::string PATH_SAMPLE = std::string(std::getenv( "userprofile")) + "\\.hackertyper\\sample.c";

size_t getrand()
{
    std::srand(time(NULL));
    size_t _max = 5, _min = 1;
    return _min + std::rand() % (_max - _min);
}

int main()
{
    std::cout << "\033c";
    std::ifstream source_file (PATH_SAMPLE);
    if (!source_file.is_open()) {
        std::cerr << "Could not open source file: " << PATH_SAMPLE << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string cur_string = "//It's hackin' time";
    std::cerr << PATH_SAMPLE << std::endl;
    /* 
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    */

    size_t filled = 0;
    while (!source_file.eof()) {
        getch();
        if (filled == cur_string.size()) {
            std::cout << std::endl;
            std::getline(source_file, cur_string);
            filled = 0;
        }
        size_t a = getrand();
        for (size_t i = filled; i < std::min(filled + a, cur_string.size()); ++i) {
            std::cout << CONSOLE_GREEN << cur_string[i];
        }
        std::cout.flush();
        filled = std::min(filled + a, cur_string.size());
    }

    source_file.close();
}
