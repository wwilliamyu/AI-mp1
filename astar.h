#ifndef ASTAR_H
#define ASTAR_H
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

namespace AStar {
	struct greaterEvaluation
	{
		bool operator() ( const cell* lhs, const cell* rhs ) const {
			return lhs->manhattan_dist + lhs->total_cost > rhs->manhattan_dist + rhs->total_cost;
		}
	};

	void astar_single(vector< vector<cell*> > &Maze, cell* start, cell*goal);

	void astar_checkFrontier(priority_queue <cell*, vector<cell*>, greaterEvaluation> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell);

	void astar_printResult(vector< vector<cell*> >  &Maze, cell* start, cell* goal);

	void astar_generatePath(cell* goal);
}

#endif