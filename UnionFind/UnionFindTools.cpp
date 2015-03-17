#include "UnionFindTools.hpp"

unsigned int uFind(unsigned int point, std::vector<Optional<unsigned int>>& table) {
  if (!table[point].hasVal()) {
    return point;
  }
  auto masterParent = uFind(table[point].getVal(), table);
  table[point].setVal(masterParent);
  return masterParent;
}

void uJoin(unsigned int a, unsigned int b, std::vector<Optional<unsigned int>>& table) {
  auto aParent = uFind(a, table);
  auto bParent = uFind(b, table);
  if (aParent != bParent) {
    table[aParent].setVal(bParent);
  }
}
