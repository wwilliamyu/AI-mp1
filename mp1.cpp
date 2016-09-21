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
	
		int manhattan_dist;
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
			goal_order(-1),
			curChar('?'){}
};


/**
* Main function to run all three algorithms
// args[1] = character for what search you want
// args[2] = the file we want to operate on
*/
int main(int argc, char** args) {
	
	ifstream mazefile(args[2]);
	vector< vector<cell> > Maze;
	string line;
	while (getline(mazefile, line)) {
		cout << line <<'\n';
		vector <cell> curLineofCells;
		// for each element in the line
		for (int i = 0; i < line.size(); i++) {
			cell curCell;
			switch (line[i]) {
				case '%':
					curCell.wall = true; 
					curCell.curChar = '%';
					curLineofCells.push_back(curCell);
					break;
				case ' ':
					curCell.curChar = ' ';
					curLineofCells.push_back(curCell);
					break;
				case '.': 
					curCell.curChar = '.';
					curLineofCells.push_back(curCell);
					break;
				case 'P':
					curCell.curChar = 'P';
					curLineofCells.push_back(curCell);
					break;
				default:
					break;
			}
		}
		Maze.push_back(curLineofCells);
	}
	cout << "the size of the maze is width x height: "<< Maze[0].size() << 'x' << Maze.size()<<'\n';
	cout << "the maze constructed is: \n";
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			cout << Maze[i][j].curChar;
		}
		cout << '\n';
	}


	mazefile.close();
	return 0;

	
}