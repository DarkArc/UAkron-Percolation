#ifndef PGMIMAGE_HPP
#define PGMIMAGE_HPP

#include "Image.hpp"

class PGMImage : public Image {
  std::string header;
  int maxGSV;
public:
  PGMImage(const std::string&, const std:string&, const int&);
  virtual ~PGMImage();
}
#endif
