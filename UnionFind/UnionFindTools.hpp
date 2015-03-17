#ifndef UNIONFINDTOOLS_HPP
#define UNIONFINDTOOLS_HPP

#include <vector>

#include "../Util/Grid.hpp"
#include "../Util/Optional.hpp"

unsigned int uFind(unsigned int, std::vector<Optional<unsigned int>>&);

void uJoin(unsigned int, unsigned int, std::vector<Optional<unsigned int>>&);

template <typename T>
  std::vector<Optional<unsigned int>> findCluster(const Grid<T>& grid);

#include "UnionFindTools.ipp"

#endif
