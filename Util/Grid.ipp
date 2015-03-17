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

#include <stdexcept>

template <typename T>
  Grid<T>::Grid(unsigned int width, unsigned int height) :
    width(width), height(height),
    grid(std::vector<T>(width * height)) { }

template <typename T>
  unsigned int Grid<T>::calcIndex(unsigned int x, unsigned int y) const {
    return y * width + x;
  }

template <typename T>
  T Grid<T>::getValAt(unsigned int x, unsigned int y) const {
    // Check bounds
    if (x >= width || x < 0) {
      throw std::runtime_error("Given x is not within bounds!");
    }
    if (y >= height || y < 0) {
      throw std::runtime_error("Given y is not within bounds!");
    }

    return grid[calcIndex(x, y)];
  }

template <typename T>
  void Grid<T>::setValAt(const unsigned int& index, const T& val) {
    if (index < 0 || index >= len()) {
      throw std::runtime_error("Given index is not within bounds!");
    }

    grid[index] = val;
  }

template <typename T>
  void Grid<T>::setValAt(const unsigned int& x, const unsigned int& y, const T& val) {
    if (x >= width || x < 0) {
      throw std::runtime_error("Given x is not within bounds!");
    }
    if (y >= height || y < 0) {
      throw std::runtime_error("Given y is not within bounds!");
    }

    grid[calcIndex(x, y)] = val;
  }

template <typename T>
  T Grid<T>::operator [] (const unsigned int& index) const {
    if (index < 0 || index >= len()) {
      throw std::runtime_error("Given index is not within bounds!");
    }
    return grid[index];
  }

template <typename T>
  unsigned int Grid<T>::len() const {
    return grid.size();
  }

template <typename T>
  unsigned int Grid<T>::getWidth() const {
    return width;
  }

template <typename T>
  unsigned int Grid<T>::getHeight() const {
    return height;
  }
