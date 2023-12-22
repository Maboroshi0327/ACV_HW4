#include <cstdlib>

#include <string>
#include <iostream>

#include "hw.hpp"

static void pauseScreen();
static void clearScreen();

int main()
{
    std::string cmdInput;

    do
    {
        std::cout
            << "1: HW4-1\n"
            << "2: HW4-2\n"
            << "q: quit\n"
            << "Enter the question number to select output result: ";
        std::cin >> cmdInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (cmdInput.size() != 1)
        {
            clearScreen();
            continue;
        }

        switch (cmdInput.c_str()[0])
        {
        case '1':
            HW4_1();
            break;

        case '2':
            HW4_2();
            break;

        default:
            clearScreen();
            continue;
        }

        pauseScreen();
        clearScreen();

    } while (cmdInput.size() != 1 || cmdInput[0] != 'q');
}

static void pauseScreen()
{
    std::cout << "Press Enter to Continue...";
    std::cin.get();
}

static void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#elif __linux__
    std::system("clear");
#endif
}