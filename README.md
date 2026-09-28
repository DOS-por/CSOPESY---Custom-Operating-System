# CSOPESY---Custom-Operating-System

## Group Developers
* Campos, Don Oswin
* Lim, Ethan Yuric
* Gutierrez, Hanz
* Co, Stephen

### Project Structure
my_console_project/
├── main.cpp                       # Primary entry point (contains the main() function)
├── README.md                      # Project documentation & setup instructions
└── commands/                      # Folder containing command & animation logic
    └── marquee.cpp                # Implementation of marquee thread loop (start, set_text, set_speed, start_marquee, stop_marquee)

## Performance & Optimal Settings

Through hardware testing, the following animation speed bounds were identified:

| Range | Delay ($ms$) | Performance & Visual Behavior |
| :--- | :--- | :--- |
| **Optimal** | `100 ms - 160 ms` | Smooth scrolling motion with crisp text legibility. |
| **Too Fast** | `< 15 ms` | Motion blur makes text unreadable; causes terminal screen tearing. |
| **Too Slow** | `> 300 ms` | Choppy, stuttered text movement. |
