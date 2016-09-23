#ifndef _CELL_H_
#define _CELL_H_
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

class cell {
	
	public:
		bool wall;
		bool visited;

		// start point, end point
		bool start;
		bool end;
		cell* previous;
		
		// do we need this
		// yes, to caculate the mahattan distance// Guangzhe

		cell* preCell;
		int distance;

		int x;
		int y;
	
		double manhattan_dist;
		char curChar; 

		cell* nearest_goal;
		int step_cost;
		int total_cost;
		int goal_order;

		cell() : 
			visited(false),
			start(false),
			end(false),
			preCell(NULL), 
			distance(std::numeric_limits<int>::max()),
			manhattan_dist(0), 
			step_cost(0), 
			goal_order(-1){}
};

#endif