#ifndef DFS_H
#define DFS_H

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

namespace DepthFS {

	void DFS(cell* start, cell* end, vector< vector<cell*> >& Maze);

	void DFS_expand(vector< vector<cell*> >& Maze, stack<cell*>& s, cell* parent, int new_x, int new_y);
	
}

#endif