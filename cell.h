#ifndef _CELL_H_
#define _CELL_H_

class cell {
	
	public:
		bool wall;
		bool visited;

		// start point, end point
		bool start;
		bool end;
		cell* previous;
		
		// do we need this
		int x;
		int y;
	
		double manhattan_dist;
		cell* nearest_goal;
		int step_cost;
		int total_cost;
		int goal_order;
		char curChar; 

		cell() : 
			visited(false),
			start(false),
			end(false),
			previous(NULL), 
			manhattan_dist(0), 
			step_cost(0), 
			goal_order(-1){}
};


#endif