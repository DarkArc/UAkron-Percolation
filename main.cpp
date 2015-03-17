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
    double chance = std::atof(argv[1]);
    unsigned int runs = std::atoi(argv[2]);
    unsigned int boardSize = std::atoi(argv[3]);

    simulate(runs, chance, boardSize);
  } else if (argc == 2) {
    readFile(argv[1]);
  } else {
    throw std::runtime_error("Illegal number of arguments!");
  }
  return 0;
}

void simulate(unsigned int runs, double chance, unsigned int boardSize) {
  MazeFactory factory(std::minstd_rand(8));
  unsigned int percolations = 0;
  for (unsigned int i = 0; i < runs; ++i) {
    Grid<bool> grid = factory.generate(chance, boardSize, boardSize);
    auto res = findCluster(grid);
    if (percolates(grid, res)) {
      ++percolations;
    }
  }
  std::cout << "Rate: " << percolations << " / " << runs
            << " (" << percolations / static_cast<double>(runs) << "%)"
            << std::endl;
}

void readFile(std::string fileName) {
  auto grid = loadMazeFromFile(fileName);
  auto res = findCluster(grid);
  unsigned int clusters = 0;
  for (unsigned int i = 0; i < res.size(); ++ i) {
    if (!res[i].hasVal() && grid[i]) {
      ++clusters;
    }
  }
  std::cout << "Clusters: " << clusters << std::endl;
}

template <typename T>
  void printBoard(Grid<T> grid) {
    for (unsigned int h = 0; h < grid.getHeight(); ++h) {
      for (unsigned int w = 0; w < grid.getWidth(); ++w) {
        std::cout << grid.getValAt(w, h) << " ";
      }
      std::cout << std::endl;
    }
  }
