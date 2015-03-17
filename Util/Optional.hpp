#ifndef OPTIONAL_HPP
#define OPTIONAL_HPP

template <typename T>
class Optional {
  bool present;
  T val;
public:
  Optional();
  Optional(const T& val);

  bool hasVal() const;
  T getVal() const;

  void clearVal();
  void setVal(const T& val);
};

template <typename K>
  bool operator == (const Optional<K>&, const Optional<K>&);
template <typename K>
  bool operator != (const Optional<K>&, const Optional<K>&);

#include "Optional.ipp"

#endif
