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

#ifndef MAZEFACTORY_HPP
#define MAZEFACTORY_HPP

#include <random>

#include "Util/Grid.hpp"

class MazeFactory {
  std::minstd_rand rand;
public:
  MazeFactory(const std::minstd_rand&);

  Grid<bool> generate(
    const double& rate,
    const unsigned int& width,
    const unsigned int& height
  );
};
#endif
