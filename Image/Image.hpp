#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

#include "Util/Grid.hpp"
#include "PixelValue.hpp"

class Image {
  std::string name;
  std::string description;
  Grid<PixelValue> pixelMap;
public:
  Image(const std::string&);
  Image(const std::string&, const std::string&);
  virtual ~Image();

  std::string getName() const;

  Grid<PixelValue>& getPixelMap();
  const Grid<PixelValue>& getPixelMap() const;
};
#endif
