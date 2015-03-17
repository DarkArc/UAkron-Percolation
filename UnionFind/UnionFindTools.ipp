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
