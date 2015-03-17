// Copyright (C) 2015 Wyatt Childers
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "MazeLoader.hpp"

#include <regex>
#include <vector>
#include <fstream>
#include <sstream>

/** Creates a Grid<bool> from a 2D-vector.

    Takes a 2D-vector of bools, representating a maze, and uses
    the data to create the respective Grid<bool>.

    @param vec
    The 2D-vector holding the data.

    @return the contructed Grid<bool>.
 */
Grid<bool> loadToGrid(std::vector<std::vector<bool>> vec) {
  // Grab the width and height
  unsigned int height = vec.size();
  unsigned int width = vec[0].size();

  // Initializes the grid with the given demensions
  Grid<bool> grid(width, height);
  for (unsigned int w = 0; w < width; ++w) {
    for (unsigned int h = 0; h < height; ++h) {
      // Move the data from the vector, to the respective
      // grid quard
      grid.setValAt(w, h, vec[h][w]);
    }
  }
  return grid;
}

/** Creates a Grid<bool> from a given maze file.

    Takes a file representing a maze, and parses it to
    create a Grid<bool> representing the maze.

    @param fileName
    The name of the maze file.

    @return the constructed Grid<bool>.
 */
Grid<bool> loadMazeFromFile(const std::string& fileName) {
  // Initialize reused regex variables
  std::regex pattern("(0|1)");
  std::regex_token_iterator<std::string::iterator> rend;

  // Open the file stream
  std::ifstream ifs(fileName);

  // Construct the initial vector to hold the data
  // temporarily
  std::vector<std::vector<bool>> mData;

  // Process the file, line by line while the file stream
  // hasn't reached the end of the file
  while (!ifs.eof()) {
    std::string line;
    std::getline(ifs, line);

    // Create a regex based tokenizer
    std::regex_token_iterator<std::string::iterator> match(
      line.begin(), line.end(), pattern
    );

    // Use the tokenizer to process the columns of the row
    std::vector<bool> rowVec;
    while(match != rend) {
      rowVec.push_back(static_cast<bool>(std::atoi((*(match++)).str().c_str())));
    }

    // Don't add the row if it contains no data
    if (!rowVec.empty()) {
      mData.push_back(rowVec);
    }
  }
  // Return the grid after processing its data into a Grid<bool>
  return loadToGrid(mData);
}
