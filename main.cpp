#include "conio.h"
#include "termcolor.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <termios.h>
#include <thread>
#include <unistd.h>

#define CONSOLE_GREEN termcolor::color<0, 154, 0>

int getrand()
{
    std::srand(time(NULL));
    int _max = 5, _min = 1;
    return _min + rand() % (_max - _min);
}

void hack_music()
{
    system("mpg123 -q --loop 1000 /bin/_hackertyper_dir/hacking_music.mp3 ");
}

int main()
{
    std::cout << "\033c";    
    std::ifstream source_file("/bin/_hackertyper_dir/sample.c");
    std::string cur_string("It's hackin' time");

    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    std::thread music_thread(hack_music);

    int filled = 0;
    while (!source_file.eof()) {
        getch();
        if (filled == cur_string.size()) {
            std::cout << std::endl;
            std::getline(source_file, cur_string);
            filled = 0;
        }
        int a = getrand();
        for (int i = filled; i < std::min(filled + a, (int)cur_string.size()); ++i) {
            std::cout << CONSOLE_GREEN << cur_string[i];
        }
        std::cout.flush();
        filled = std::min(filled + a, (int)cur_string.size());
    }

    music_thread.join();

    source_file.close();
}
