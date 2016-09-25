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
			return a->F >= b->F;
		}
	};
	void Amul(cell* start, vector<cell*> dots, vector< vector<cell*> >& Maze);
	int MDistance(cell* a, cell* b);
	int GetHeuristic(cell * current,vector<cell*>  goallist);
	Amul::goal * setGoal(goal* current,cell* next,vector<cell*> goallist, vector< vector<cell*> >& Maze);

	// void Amul_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* curr, cell* new_cell);

		struct greaterEvaluation
	{
		bool operator() ( const cell* lhs, const cell* rhs ) const {
			return lhs->manhattan_dist + lhs->total_cost > rhs->manhattan_dist + rhs->total_cost;
		}
	};

	int astar_single(vector< vector<cell*> > &Maze, cell* start, cell*goal);

	void astar_checkFrontier(priority_queue <cell*, vector<cell*>, greaterEvaluation> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell);

	void astar_printResult(vector< vector<cell*> >  &Maze, cell* start, cell* goal);

	void astar_generatePath(cell* goal);
	
}

#endif