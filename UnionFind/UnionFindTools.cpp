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

#include "UnionFindTools.hpp"

/** Search for the root of the specified index.

    Starts at the given index, and works its way up the "tree" of values
    until it finds the index of the root node of the "tree". Then
    updates all nodes inbetween the starting index, and the root
    to point directly to the root.

    @param point
    The index to start at.

    @param table
    The vector representing the tree of cluster relationships.

    @return the index of the root node.
 */
unsigned int uFind(unsigned int point, std::vector<Optional<unsigned int>>& table) {
  // The recursive base case, if the current index holds a root node
  // return the root node
  if (!table[point].hasVal()) {
    return point;
  }

  // Recursively call until the root node is found, then update
  // the parent of the current index's node to be the root node
  // before returning the root node as the result
  auto masterParent = uFind(table[point].getVal(), table);
  table[point].setVal(masterParent);
  return masterParent;
}

/** Joins two indexes to point to the same root.

    Utalizes the uFind function to search for the root node of both
    provided indexes, and then set the parent of one to be the other
    if they are not already the same.

    @param a
    One of the indexes to start at.

    @param b
    One of the indexes to start at.

    @param table
    The vector representing the tree of cluster relationships.
 */
void uJoin(unsigned int a, unsigned int b, std::vector<Optional<unsigned int>>& table) {
  auto aParent = uFind(a, table); // Find the root of a
  auto bParent = uFind(b, table); // Find the root of b

  // If they are not the same, set the root of a to be the root of b
  if (aParent != bParent) {
    table[aParent].setVal(bParent);
  }
}
