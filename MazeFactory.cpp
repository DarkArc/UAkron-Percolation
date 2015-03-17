#include "MazeFactory.hpp"

MazeFactory::MazeFactory(const std::minstd_rand& rand) : rand(rand) { }

Grid<bool> MazeFactory::generate(double rate, unsigned int width, unsigned int height) {
  Grid<bool> g(width, height);
  for (unsigned int i = 0; i < g.len(); ++i) {
    if ((static_cast<double>(rand()) / rand.max()) <= rate) {
      g.setValAt(i, true);
    }
  }
  return g;
}
