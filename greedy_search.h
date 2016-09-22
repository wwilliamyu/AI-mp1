#ifndef GREEDY_H
#define GREEDY_H

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
namespace GreedySearch {

	void calculate_manhattan_distance(vector< vector<cell*> >  &Maze, cell * goalCell);

	void greedy_single(vector< vector<cell*> > &Maze, cell* start, cell*goal);

	struct shorterMantthanDist {
		bool operator() ( const cell* lhs, const cell* rhs ) const {
			return lhs->manhattan_dist > rhs->manhattan_dist;
		}
	};

	void greedy_checkFrontier(priority_queue <cell*, vector<cell*>, shorterMantthanDist> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell);

	void greedy_printResult(vector< vector<cell*> >  &Maze, cell* start, cell* goal);

	void greedy_generatePath(cell* goal);
}

#endif