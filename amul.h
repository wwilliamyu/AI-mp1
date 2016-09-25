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
#include "astar.h"

using namespace std;
// This is the content of the .h file, which is where the declarations go

namespace Amul {
	struct goal
	{
	cell * the_cell;
	int H;
	int G;//A* or BFS
	int F;
	goal* pre;
	vector<cell*> remaining;
	};
	struct greater
	{
		bool operator() ( const goal* a, const goal* b ) const {
			return a->F > b->F;
		}
	};
	void Amul(cell* start, vector<cell*> dots, vector< vector<cell*> >& Maze);
	void MDistance(cell* a, cell* b);
	int GetHeuristic(goal * current,vector<cell*>&goallist);
	Amul::goal * setGoal(goal* current,goal* next,vector<cell*> goallist, vector< vector<cell*> >& Maze);
	void MDistance(cell* a, cell* b);

	// void Amul_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* curr, cell* new_cell);
	
}

#endif