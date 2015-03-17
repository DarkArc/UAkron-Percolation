#ifndef PIXELVALUE_HPP
#define PIXELVALUE_HPP

class PixelValue {
  const int r, g, b;
public:
  PixelValue(const int&, const int&, const int&);

  int getR() const;
  int getG() const;
  int getB() const;

  int asGreyScale() const;
};
#endif
