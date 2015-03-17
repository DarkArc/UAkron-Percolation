#ifndef MAZEFACTORY_HPP
#define MAZEFACTORY_HPP

#include <random>

#include "Util/Grid.hpp"

class MazeFactory {
  std::minstd_rand rand;
public:
  MazeFactory(const std::minstd_rand&);

  Grid<bool> generate(double rate, unsigned int width, unsigned int height);
};
#endif
