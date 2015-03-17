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

bool percolates(const Grid<bool>& g, std::vector<Optional<unsigned int>>& table) {
 std::set<unsigned int> top;
 for (unsigned int i = 0; i < g.getWidth(); ++i) {
   auto index = uFind(i, table);
   if (g[index]) {
     top.insert(index);
   }
 }
 for (unsigned int i = 0; i < g.getWidth(); ++i) {
   if (top.find(uFind(g.calcIndex(i, g.getHeight() - 1), table)) != top.end()) {
     return true;
   }
 }
 return false;
}
