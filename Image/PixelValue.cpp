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

#include "PixelValue.hpp"

#include <stdexcept>

PixelValue::PixelValue(const int& r = 0, const int& g = 0, const int& b = 0)
                      : r(r), g(g), b(b) {
  if (r < 0 || r > 255) {
    throw std::runtime_error("Red is out of bounds!");
  }
  if (g < 0 || g > 255) {
    throw std::runtime_error("Green is out of bounds!");
  }
  if (b < 0 || b > 255) {
    throw std::runtime_error("Blue is out of bounds!");
  }
}

int PixelValue::getR() const {
  return r;
}

int PixelValue::getG() const {
  return g;
}

int PixelValue::getB() const {
  return b;
}

int PixelValue::asGreyScale() const {
  return 0.299 * r + 0.587 * g + 0.114 * b;
}
