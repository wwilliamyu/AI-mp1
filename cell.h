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

		cell* preCell; //previous cell expanded where the current cell reached from
		int distance;

		int x;
		int y; 
	
		double manhattan_dist; //the manhattan distance between this cell and the goal
		char curChar; //the character of this cell

		cell* nearest_goal;
		int total_cost; //the total cost from the starting cell to the current cell
		int step_cost;
		int goal_order;

		cell() : 
			visited(false),
			start(false),
			end(false),
			preCell(NULL), 
			distance(std::numeric_limits<int>::max()),
			manhattan_dist(0), 
			total_cost(0),
			step_cost(0), 
			goal_order(-1){}

};

#endif