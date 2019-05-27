#include <iostream>
#include <vector>
#include <queue>

#ifndef SRC_QUEUE_BFSWALLSANDGATES_H_
#define SRC_QUEUE_BFSWALLSANDGATES_H_

class BfsWallsAndGates {
public:
    class Cell {
      public:
      Cell (int row, int col) : row(row),
                                col(col) {}
      int row;
      int col;
    };

    void wallsAndGates(std::vector< std::vector<int> >& rooms);
    void TestDriver();

  private:
  int minDistanceToGate(std::vector< std::vector<int> >& rooms, int row, int col, int dist);

  std::queue<Cell> bfsQ;
  int nRows, nCols;

};

#endif
