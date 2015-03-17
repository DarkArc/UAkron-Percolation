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
