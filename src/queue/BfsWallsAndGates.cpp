#include "BfsWallsAndGates.h"

static int INFINITY = ((1U << 31) - 1);

static int min_value(int v1, int v2) {
  if (v1 < v2) return v1;
  return v2;
}


void
BfsWallsAndGates::wallsAndGates(std::vector< std::vector<int> >& rooms) {
	nRows = rooms.size();
	if (nRows) {
		nCols = rooms[0].size();
	}

	for (int i = 0; i < nRows; ++i) {
		for (int j = 0; j < nCols; ++j) {
			if (rooms[i][j] == INFINITY) {
				rooms[i][j] = minDistanceToGate(rooms, i, j, 1);
			}
		}
	}
}

int
BfsWallsAndGates::minDistanceToGate(std::vector<std::vector<int>>& rooms, int row, int col, int dist) {
	int nRows = rooms.size();
	int nCols = rooms[0].size();
	if (row < 0 || col < 0 || row >= nRows || col >= nCols || (rooms[row][col] == -1)) {
		return INFINITY;
	} else if (rooms[row][col] == 0) {
		return dist;
	} else if (rooms[row][col] > 0 && rooms[row][col] < INFINITY) {
		return rooms[row][col];
	}

	int curMinDist = INFINITY;

	for (int i = row - 1; i <= row + 1; ++i) {
		for (int j = col - 1; j <= col + 1; ++j) {
			Cell nbr(i, j);
			bfsQ.push(nbr);
		}
	}

	while (!bfsQ.empty()) {
		Cell seed = bfsQ.front();
		bfsQ.pop();
		curMinDist = min_value(curMinDist, minDistanceToGate(rooms, seed.row, seed.col, dist++));
	}
	return curMinDist;
}

void
BfsWallsAndGates::TestDriver() {
	std::vector< std::vector<int> > rooms = { { INFINITY, -1, 0, 1 }, { 2, 2, 1, -1 } }; //, { 1, -1, 2, -1 }, { 0, -1, 3, 4 } };
	wallsAndGates(rooms);
}
