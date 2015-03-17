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
