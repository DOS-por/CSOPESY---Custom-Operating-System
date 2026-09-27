#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;



class Marquee {
    //Attributes
    private:
        string message;

    //Methods
    public:
        Marquee(string marq_text){
            message = marq_text;
        }

        void help(){
            cout << "help - displays the commands and its description";
            cout << "\nstart_marquee - starts the marquee \"animation\"";
            cout << "\nstop_marquee - stops the marquee \"animation\"";
            cout << "\nset_text - accepts a text input and displays it as marquee";
            cout << "\nset_speed - sets the marquee animation refresh in milliseconds";
            cout << "\nexit - terminates the console";
        }
        
        void set_text(string text){
            message = text;
            cout << "Text saved for marquee: " + message;
        }

        void start_marquee(){
            cout << "work in progress";
        }

        void stop_marquee(){
            cout << "work in progress";
        }

        void set_speed(){
            cout << "work in progress";
        }
};