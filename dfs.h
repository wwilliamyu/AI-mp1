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

	//actual function
	void DFS(cell* start, cell* end, vector< vector<cell*> >& Maze);

	// helper function for expansion
	void DFS_expand(vector< vector<cell*> >& Maze, stack<cell*>& s, cell* curr, cell* new_cell);
	
}

#endif