#ifndef AMUL_H
#define AMUL_H
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

namespace Amul {

	void Amul(cell* start, vector<cell*>&goallist, vector< vector<cell*> >& Maze);
	void MDistance(cell* a, cell* b);
	// void Amul_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* curr, cell* new_cell);
	
}

#endif