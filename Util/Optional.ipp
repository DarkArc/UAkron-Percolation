template <typename T>
  Optional<T>::Optional() : present(false) { }

template <typename T>
  Optional<T>::Optional(const T& val) : present(true), val(val) { }

template <typename T>
  bool Optional<T>::hasVal() const {
    return present;
  }

template <typename T>
  T Optional<T>::getVal() const {
    if (!hasVal()) {
      throw std::runtime_error("There is currently no held value!");
    }
    return val;
  }

template <typename T>
  void Optional<T>::clearVal() {
    present = false;
  }

template <typename T>
  void Optional<T>::setVal(const T& val) {
    this->val = val;
    this->present = true;
  }

template <typename T, typename K>
  bool operator == (const Optional<K>& a, const Optional<K>& b) {
    return a.hasVal() == b.hasVal() && a.getVal() == b.getVal();
  }

template <typename T, typename K>
  bool operator != (const Optional<K>& a, const Optional<K>& b) {
    return !(a == b);
  }
