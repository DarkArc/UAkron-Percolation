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

#include <cstdlib>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>

#include "MazeFactory.hpp"
#include "MazeLoader.hpp"
#include "PercolationTest.hpp"
#include "Util/Grid.hpp"
#include "UnionFind/UnionFindTools.hpp"

void simulate(unsigned int, double, unsigned int);
void readFile(std::string);

template <typename T>
  void printBoard(Grid<T> grid);

int main(int argc, char* argv[]) {
  if (argc == 4) {
    // Trigger a simulation based on arguments
    double chance = std::atof(argv[1]);
    unsigned int runs = std::atoi(argv[2]);
    unsigned int boardSize = std::atoi(argv[3]);

    simulate(runs, chance, boardSize);
  } else if (argc == 2) {
    // Count the clusters in the specified file
    readFile(argv[1]);
  } else {
    throw std::runtime_error("Illegal number of arguments!");
  }
  return 0;
}

/** Generate grids, and test their percolation.

    Generates the specified amount of mazes, with a specified size,
    and specified percolation chance for each grid entry.

    After running the simulation, the funtion prints the overall
    percolation rate -- the number of percolating mazes / the number
    of generated mazes -- in both ratio and percent format.

    @param runs
    The number of mazes to generate and test.

    @param chance
    The per-grid entry chance of percolation.

    @param boardSize
    The size of the maze board to generate, this is used for
    both width, and height.
 */
void simulate(unsigned int runs, double chance, unsigned int boardSize) {
  // Initialize a maze fatory with the std::minstd_rand random engine
  // seeded by the number 8.
  MazeFactory factory(std::minstd_rand(8));

  // Count the number of percolating maze boards
  unsigned int percolations = 0;
  for (unsigned int i = 0; i < runs; ++i) {
    // Generate a maze board, using the maze factory
    Grid<bool> grid = factory.generate(chance, boardSize, boardSize);

    //Find the clusters in the generated maze board's grid
    auto res = findCluster(grid);
    // Check to see if the maze percolates
    if (percolates(grid, res)) {
      ++percolations;
    }
  }
  std::cout << "Rate: " << percolations << " / " << runs
            << " (" << ((percolations / static_cast<double>(runs)) * 100) << "%)"
            << std::endl;
}

/** Read a maze file and count the clusters which percolate.

    Takes the given maze file, loads in into memory,
    and counts the number of clusters it contains which
    percolate. The function then prints this number.

    @param fileName
    The name of the file to load.
 */
void readFile(std::string fileName) {
  // Load the maze file into a Grid<bool>
  auto grid = loadMazeFromFile(fileName);

  // Find clusters in the maze board's grid
  auto res = findCluster(grid);

  // Count the number of root nodes, checking the grid
  // to see if the cluster percolates, or is solid
  unsigned int clusters = 0;
  for (unsigned int i = 0; i < res.size(); ++ i) {
    // if (!res[i].hasVal()) - the node is a root node
    // if (grid[i]) - the node percolates
    if (!res[i].hasVal() && grid[i]) {
      ++clusters;
    }
  }
  std::cout << "Clusters: " << clusters << std::endl;
}

/** Prints the given Grid<T>.

    Takes the given grid, and prints the values row by row
    in grid format, columns seperated by spaces.

    @param grid
    The grid to print.
 */
template <typename T>
  void printBoard(Grid<T> grid) {
    for (unsigned int h = 0; h < grid.getHeight(); ++h) {
      for (unsigned int w = 0; w < grid.getWidth(); ++w) {
        std::cout << grid.getValAt(w, h) << " ";
      }
      std::cout << std::endl;
    }
  }
