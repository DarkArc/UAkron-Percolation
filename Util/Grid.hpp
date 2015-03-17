#ifndef GRID_HPP
#define GRID_HPP

#include <vector>

template <typename T>
class Grid {
  const unsigned int width;
  const unsigned int height;
  std::vector<T> grid;
public:
  Grid(unsigned int, unsigned int);

  unsigned int calcIndex(unsigned int, unsigned int) const;

  T getValAt(unsigned int, unsigned int) const;
  void setValAt(const unsigned int&, const T&);
  void setValAt(const unsigned int&, const unsigned int&, const T&);

  T operator [] (const unsigned int&) const;

  unsigned int len() const;
  unsigned int getWidth() const;
  unsigned int getHeight() const;
};

#include "Grid.ipp"

#endif
