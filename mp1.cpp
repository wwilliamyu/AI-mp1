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

using namespace std;

struct cell {
	
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
	
		int manhattan_dist;
		cell* nearest_goal;
		int step_cost;
		int total_cost;
		int goal_order;


		cell() : 
			visited(false),
			start(false),
			end(false),
			previous(NULL), 
			manhattan_dist(0), 
			step_cost(0), 
			goal_order(-1) {}
};

// struct node {
// 	node* parent;

// 	node* childA;
// 	node* childB;
// 	node* childC;
// 	node* childD;
// };

int main(int argc, char** args) {

	// args[1] = character for what search you want
	// args[2] = the file we want to operate on

	ifstream myfile(args[2]);

	string line;
	vector< vector<Cell> > Maze;
	int i = 0;
	// get maze dimensions
	while (getline(myfile, line)) {

		// for each element in the line
		for (int j = 0; j < line.size(); j++) {

			case (line[j]) {
				'%':
					Maze[i][j].wall = true;

				' ':
					Maze[i][j].wall = false;
				'.': 
					Maze[i][j].start = true;
				'P':
					Maze[i][j].end = true;
			}
		}
		i++;

	}

	myfile.close();
	return 0;

	
}