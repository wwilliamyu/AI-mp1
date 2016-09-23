#ifndef BFS_H
#define BFS_H
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cell.h"

using namespace std;
// This is the content of the .h file, which is where the declarations go

namespace BreadthFS {

	void BFS(cell* start, cell* end, vector< vector<cell*> >& Maze);

	void BFS_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* curr, cell* new_cell);
	
}

#endif