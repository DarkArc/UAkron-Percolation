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
