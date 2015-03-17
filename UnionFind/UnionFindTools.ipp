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

/** Finds all clusters in the given grid.

    Working by row by row, from left column, to right most column,
    goes through the provided grid, checking to see if the value
    to the left of the current node, and/or the value above the
    current node is equal to the value at the current node.

    If these nodes are equivalent, they are then joined into a
    tree representing the cluster relationships.

    @param grid
    The Grid<T> to work with.

    @return the resulting vector representing the tree of
    cluster relationships.
 */
template <typename T>
  std::vector<Optional<unsigned int>> findCluster(const Grid<T>& grid) {
    // Initialize a vector of root nodes, with the same length
    // as the grid
    std::vector<Optional<unsigned int>> indexTable(grid.len());
    for (unsigned int h = 0; h < grid.getHeight(); ++h) {
      for (unsigned int w = 0; w < grid.getWidth(); ++w) {
        // Get the value of the current node
        unsigned int curI = grid.calcIndex(w, h);
        T&& curV = grid[curI];

        // Check the value of the left node
        if (w > 0) {
          unsigned int leftI = grid.calcIndex(w - 1, h);
          T&& leftV = grid[leftI];
          // Join if equal
          if (curV == leftV) {
            uJoin(curI, leftI, indexTable);
          }
        }

        // Check the vaue of the above node
        if (h > 0) {
          unsigned int aboveI = grid.calcIndex(w, h - 1);
          T&& aboveV = grid[aboveI];
          // Join if equal
          if (curV == aboveV) {
            uJoin(curI, aboveI, indexTable);
          }
        }
      }
    }
    return indexTable;
  }
