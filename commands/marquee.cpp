#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <atomic>
#include <mutex>
#include <chrono>
using namespace std;


class Marquee {
    //Attributes
    private:
        string message;
        mutex message_mutex; // mutex to protect access to the message string
        thread marquee_thread; // thread that runs the marquee animation
        atomic<bool> running{false}; // flag indicating whether the marquee is running
        atomic<int> speed_ms{160}; // marquee animation refresh speed in milliseconds (default: 160)
        int spacing = 5;

        void animate(){
            size_t offset = 0;

            //manipulation of padding space for teh animation
            string padding_space(spacing, ' ');

            while(running){
                string padded;
                { // lock the message mutex to safely access the message string
                    lock_guard<mutex> lock(message_mutex);
                    padded = message.empty() ? string(" ") : message + padding_space;
                }
                offset %= padded.size(); // ensure the offset wraps around the length of the padded message
                string display = padded.substr(offset) + padded.substr(0, offset); // display string built by rotating padded message based on offset

                ostringstream seq; // an output string stream to build the escape sequence for marquee display
                seq << "\x1b[s" << "\x1b[2A\r\x1b[K" << display << "   " << "\x1b[u"; // escape sequence for display
                cout << seq.str() << flush;

                offset++;
                this_thread::sleep_for(chrono::milliseconds(speed_ms.load())); // sleep for duration of marquee text speed
            }
        }

    //Methods
    public:
        Marquee(string marq_text, int speed, int pad_spaces){
            message = marq_text;
            speed_ms = speed;
        }

        // destructor that will automatically stop the marquee if it's running
        ~Marquee(){
            stop_marquee();
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
            lock_guard<mutex> lock(message_mutex); // lock message mutex for safe access to message string
            message = text;
            cout << "Text saved for marquee: " + message;
        }

        void start_marquee(){
            if(running){
                cout << "Marquee is already running";
                return;
            }
            running = true;
            marquee_thread = thread(&Marquee::animate, this); // start marquee animation in seperate thread
        }

        void stop_marquee(){
            if(!running){
                cout << "Marquee is not running";
                return;
            }
            running = false;
            if(marquee_thread.joinable()){  // join the marquee thread if it is joinable
                marquee_thread.join(); // wait for the marquee thread to finish execution
            }
            cout << "\nMarquee stopped";
        }

        void set_speed(int ms){
            speed_ms = ms;
            cout << "Marquee speed set to " << ms << "ms";
        }
};