#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "commands/marquee.cpp"
using namespace std;


int main(){
    // Clearout screen
    cout << "\033[H\033[2J" << flush;

    // Windows command to change utf encoding and change console color
    SetConsoleOutputCP(65001);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    // Welcome message
    cout << "    ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄   ▄▄▄▄ \n";
    cout << "    ███▓┌─ ███▓│ ▄██▓┌─ ███▓│ ▄▓█▓┌─ ███▓┐ ███▓┌─ ███▓┐ ███▓┌─ ███▓│ ▄██▓┌─ ███▓│ ███▓│  ███▓│\n";
    cout << "    ███▓│░  ───┘ ▀███▄▄▄▄▄ ─┘ ███▓│  ████│ ████▄▄▄██▀┌┘ ████▄▄  ───┘ ▀███▄▄▄▄▄ ─┘ ▀███▄▄▄████│\n";
    cout << "    ███▓│▒ ▄▄▄▄  ▄▄▄▄┌─ ███▓│ ███▓│  ███▓│ ███▓┌────┘ ▒ ███▓┌─┘▄▄▄▄  ▄▄▄▄┌─ ███▓│ ▄▄▄▄┌─ ███▓│\n";
    cout << "    ▀███▄▄▄███▓│ ▓███▄▄▄██▓┌┘ └▓██▄▄▄█▓┌─┘ ▓███│▀▀▀▀▀▀▀ ▀███▄▄▄███▓│ ▓███▄▄▄██▓┌┘ ▓███▄▄▄██▓┌┘\n";
    cout << "    ────────┘  ─────────┘    ───────┘    ───┘         ────────┘  ─────────┘   ─────────┘ \n";


    cout << "\n\nGroup developer:";
    cout << "\nCampos, Don Oswin";
    cout << "\nLim, Ethan Yuric";
    cout << "\nGutierrez, Hanz";
    cout << "\nCo, Stephen";
    cout << "\n\nVersion date: 2026-09-27";

    Marquee marquee("Welcome");

    bool exit = false;
    string prompt_line;
    string command;
    string next_word;
    string current_word;

    while(!exit){
        // Blank line reserved as padding between the marquee line and the prompt
        cout << "\n\nCommand> ";

        //Tokenization for the commands
        string value;
        getline(cin, prompt_line);
        stringstream ss(prompt_line);
        ss >> command;

        // loop for getting all of the value after command
        while(ss >> current_word){
            value += current_word;
            value += " ";
        }

        if(command == "help") {
            marquee.help();
        }
        else if (command == "start_marquee") {
            marquee.start_marquee();
        }
        else if (command == "stop_marquee") {
            marquee.stop_marquee();
        }
        else if (command == "set_text") {
            marquee.set_text(value);
        }
        else if (command == "set_speed") {
            try {
                marquee.set_speed(stoi(value));
            } catch (...) {
                cout << "Please provide a valid number of milliseconds";
            }
        }
        else if (command == "exit") {
            marquee.stop_marquee();
            cout << "Terminating console...";
            exit = true;
        }
        else {
            cout << "Please input a valid command";
        }

        cout << "\n";
    }


    return 0;
}