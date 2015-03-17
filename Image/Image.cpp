#include "Image.hpp"

Image::Image(const std::string& name) : name(name) { }

Image::~Image() { }

std::string Image::getName() const {
  return name;
}

Grid<PixelValue>& Image::getPixelMap() {
  return pixelMap;
}

const Grid<PixelValue>& Image::getPixelMap() const {
  return pixelMap;
}
