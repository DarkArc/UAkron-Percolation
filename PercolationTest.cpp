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

#include "PercolationTest.hpp"

#include "UnionFind/UnionFindTools.hpp"

/** Test the percolation of a grid

    Takes two arguments, a grid, and a table. The table specifies
    the item clusters on the grid.

    @param g
    The given grid to test.

    @param table
    The table holding the cluster relationships.

    @return true if the grid percolates.
 */
bool percolates(const Grid<bool>& g, std::vector<Optional<unsigned int>>& table) {
  // Create a set containing all clusters which exist in the first row of the grid
  std::set<unsigned int> top;
  for (unsigned int i = 0; i < g.getWidth(); ++i) {
    // Use uFind to find the root of the cluster
    auto index = uFind(i, table);
    if (g[index]) {
      top.insert(index);
    }
  }

  // Check to see if any clusters which exist in the first row of the grid
  // also exists in the last row of the grid
  for (unsigned int i = 0; i < g.getWidth(); ++i) {
    // Use uFind to find the root of the cluster
    if (top.find(uFind(g.calcIndex(i, g.getHeight() - 1), table)) != top.end()) {
      return true;
    }
  }
  return false;
}
