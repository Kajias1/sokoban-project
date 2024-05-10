
### SOKOBAN PROJECT
#### REFACTORING CHANGES
* Game level variables and related functions were converted into a `level` class. Level managing functions are located in `levels.h` header file. 
* Player-related variables and functions were converted into a `player` class.
#### NEW FEATURE
Implemented functionality to parse and load levels dynamically from the `level.sl` file located in `data` directory.
Levels are encoded using the run-length encoding scheme.
#### SETUP GUIDE
0. Ensure that you have installed Raylib C++ graphics library on your machine.
1. Clone the project and ensure that the working directory is set properly.
2. Build the project using CMake and `CMakeLists.txt` to create an executable file.
3. Run the `sokoban.exe`.