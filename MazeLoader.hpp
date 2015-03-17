#ifndef MAZELOADER_HPP
#define MAZELOADER_HPP

#include <string>

#include "Util/Grid.hpp"

Grid<bool> loadMazeFromFile(const std::string&);
#endif
