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

#include "MazeFactory.hpp"

/** Construct a new Maze Factory object.

    @param rand
    A minstd_rand to use for random grid value assignment.
 */
MazeFactory::MazeFactory(const std::minstd_rand& rand) : rand(rand) { }

/** Generate a new Grid<bool>.

    Takes in the demensions, and percolation rate as arguments,
    for a new randomly generated grid. If the randomly generated ratio
    is less than or equal to the provided percolation rate,
    the value will be passible.

    @param rate
    The percolation rate to determine whether a position
    is passible, or inpassible.

    @param width
    The width of the Grid<bool>.

    @param height
    The height of the Grid<bool>.

    @return the generated Grid<bool>.
 */
Grid<bool> MazeFactory::generate(const double& rate,
                                 const unsigned int& width,
                                 const unsigned int& height) {
  // Initializes the grid with the given demensions
  Grid<bool> g(width, height);

  // Populate the grid with randomly percolating points
  // as defined by the supplied probability
  for (unsigned int i = 0; i < g.len(); ++i) {
    if ((static_cast<double>(rand()) / rand.max()) <= rate) {
      g.setValAt(i, true);
    }
  }
  return g;
}
