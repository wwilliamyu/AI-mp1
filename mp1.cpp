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

// our own header files
#include "bfs.h"
#include "dfs.h"

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


/**
* Main function to run all three algorithms
// args[1] = character for what search you want
// args[2] = the file we want to operate on
*/
int main(int argc, char** args) {
	
	ifstream mazefile(args[2]);


	int i = 0;
	// get maze dimensions
	while (getline(mazefile, line)) {
		cout << line <<'\n';
		// for each element in the line
		for (size_t j = 0; j < line.size(); j++) {

			switch (line[j]) {
				case '%':
					// Maze[i][j].wall = true;
					break;

				case ' ':
					// Maze[i][j].wall = false;
					break;
				case '.': 
					// Maze[i][j].start = true;
					break;
				case 'P':
					// Maze[i][j].end = true;
					break;
				default:
					break;
			}
		}
		i++;

	}

	myfile.close();
	return 0;

	
}