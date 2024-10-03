#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <print>
#include <string>
#include <thread>

#include "conio.h"
#include "termcolor.hpp"

#define CONSOLE_GREEN termcolor::color<0, 154, 0>

const std::string PATH_MUSIC = "mpg123 -q --loop 1000 /bin/_hackertyper_dir/hacking_music.mp3";
const std::string PATH_SAMPLE = "/bin/_hackertyper_dir/sample.c";

int
getrand()
{
    std::srand(time(NULL));
    int _max = 5, _min = 1;
    return _min + rand() % (_max - _min);
}

void
hack_music()
{
    std::system(PATH_MUSIC.c_str());
}

int
main(int argc, char **argv)
{
    std::print("\033c");
    std::ifstream source_file(PATH_SAMPLE);
    std::string cur_string = "// It's hackin' time";

    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::jthread music_thread(hack_music);

    size_t filled = 0;
    while (!source_file.eof()) {
        getch();
        if (filled == cur_string.size()) {
            std::print("\n");
            std::getline(source_file, cur_string);
            filled = 0;
        }
        int a = getrand();
        for (int i = filled; i < std::min(filled + a, cur_string.size()); ++i) {
            std::cout << CONSOLE_GREEN;
            std::print("{}", cur_string[i]);
        }
        std::cout.flush();
        filled = std::min(filled + a, cur_string.size());
    }
    source_file.close();
}
