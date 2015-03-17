#ifndef PERCOLATIONTEST_HPP
#define PERCOLATIONTEST_HPP

#include <vector>
#include <set>

#include "Util/Grid.hpp"
#include "Util/Optional.hpp"

bool percolates(const Grid<bool>&, std::vector<Optional<unsigned int>>&);
#endif
