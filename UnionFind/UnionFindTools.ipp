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
  std::vector<Optional<unsigned int>> findCluster(const Grid<T>& grid) {
    std::vector<Optional<unsigned int>> indexTable(grid.len());
    for (unsigned int h = 0; h < grid.getHeight(); ++h) {
      for (unsigned int w = 0; w < grid.getWidth(); ++w) {
        unsigned int curI = grid.calcIndex(w, h);
        T&& curV = grid[curI];

        if (w > 0) {
          unsigned int leftI = grid.calcIndex(w - 1, h);
          T&& leftV = grid[leftI];
          if (curV == leftV) {
            uJoin(curI, leftI, indexTable);
          }
        }

        if (h > 0) {
          unsigned int aboveI = grid.calcIndex(w, h - 1);
          T&& aboveV = grid[aboveI];
          if (curV == aboveV) {
            uJoin(curI, aboveI, indexTable);
          }
        }
      }
    }
    return indexTable;
  }
