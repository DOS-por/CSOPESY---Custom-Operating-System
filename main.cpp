#include <iostream>
#include <string>
#include <sstream>
#include "commands/marquee.cpp"
using namespace std;


int main(){
    // Welcome message
    cout << R"(
    ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄    ▄▄▄▄▄▄▄▄▄▄   ▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄   ▄▄▄▄ 
    ███▓┌─ ███▓│ ▄██▓┌─ ███▓│ ▄▓█▓┌─ ███▓┐ ███▓┌─ ███▓┐ ███▓┌─ ███▓│ ▄██▓┌─ ███▓│ ███▓│  ███▓│
    ███▓│░  ───┘ ▀███▄▄▄▄▄ ─┘ ███▓│  ████│ ████▄▄▄██▀┌┘ ████▄▄  ───┘ ▀███▄▄▄▄▄ ─┘ ▀███▄▄▄████│
    ███▓│▒ ▄▄▄▄  ▄▄▄▄┌─ ███▓│ ███▓│  ███▓│ ███▓┌────┘ ▒ ███▓┌─┘▄▄▄▄  ▄▄▄▄┌─ ███▓│ ▄▄▄▄┌─ ███▓│
    ▀███▄▄▄███▓│ ▓███▄▄▄██▓┌┘ └▓██▄▄▄█▓┌─┘ ▓███│▀▀▀▀▀▀▀ ▀███▄▄▄███▓│ ▓███▄▄▄██▓┌┘ ▓███▄▄▄██▓┌┘
    ────────┘  ─────────┘    ───────┘    ───┘           ────────┘  ─────────┘   ─────────┘ 
    )";



    cout << "\n\nGroup developer:";
    cout << "\nCampos, Don Oswin";
    cout << "\nLim, Ethan Yuric";
    cout << "\nGutierrez, Hanz";
    cout << "\n\nVersion date: 2026-09-20";

    Marquee marquee("Welcome");

    bool exit = false;
    string prompt_line;
    string command;
    string next_word;
    string current_word;

    while(!exit){
        cout << "\nCommand> ";

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
            marquee.set_speed();
        }
        else if (command == "exit") {
            cout << "Treminating console...";
            exit = true;
        }
        else {
            cout << "Please input a valid command";
        }

        cout << "\n";
    }


    return 0;
}