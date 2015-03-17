Implementation
  The program is composed of 3 classes, and 6 header files, as well as a main:
    3 classes:
      * Grid - A wrapper for a 1D vector array which allows it to be worked with
               in both 1D, and 2D terms used for board representations
      * Optional - A data structure which stores an value which may or may not exists
                   used for part of the cluster tree implementation
      * MazeFactory - Takes a seeded random engine, and uses it to create maze boards
    General headers:
      * UnionFindTools - Functions for completing the union find operations
      * MazeLoader - Functions for loading the maze into memory from a txt file
      * PercolationTest - Test whether the maze board percolates
  The main:
    Coordinates interaction between the different elements, and handles user input

Compilation
  Requirements:
    * C++11 (Definitely works with GCC 4.9.2, may work with older versions)
    * CMake 2.8+

  Compilation Steps:
    1) Go to the project directory via command line
    2) mkdir build
    3) cd build/
    4) cmake ..
    5) make

Usage
  Steps:
    1) ./Percolation (command arguments here)
