#include "PGMImage.hpp"

PGMImage::PGMImage(
    const std::string& name,
    const std::string& header,
    const int& maxGSV
  ) : Image(name), header(header), maxGSV(maxGSV) {

}

PGMImage::~PGMImage() { }
