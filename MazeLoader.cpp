#include "MazeLoader.hpp"

#include <regex>
#include <vector>
#include <fstream>
#include <sstream>

Grid<bool> loadToGrid(std::vector<std::vector<bool>> vec) {
  unsigned int height = vec.size();
  unsigned int width = vec[0].size();
  Grid<bool> grid(width, height);
  for (unsigned int w = 0; w < width; ++w) {
    for (unsigned int h = 0; h < height; ++h) {
      grid.setValAt(w, h, vec[h][w]);
    }
  }
  return grid;
}

Grid<bool> loadMazeFromFile(const std::string& fileName) {
  std::regex pattern("(0|1)");
  std::regex_token_iterator<std::string::iterator> rend;

  std::ifstream ifs(fileName);
  std::vector<std::vector<bool>> mData;
  while (!ifs.eof()) {
    std::string line;
    std::getline(ifs, line);

    std::regex_token_iterator<std::string::iterator> match(
      line.begin(), line.end(), pattern
    );

    std::vector<bool> rowVec;
    while(match != rend) {
      rowVec.push_back(static_cast<bool>(std::atoi((*(match++)).str().c_str())));
    }
    if (!rowVec.empty()) {
      mData.push_back(rowVec);
    }
  }
  return loadToGrid(mData);
}