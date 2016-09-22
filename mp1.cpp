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
// our own header files
#include "bfs.h"
#include "dfs.h"
#include "cell.h"

using namespace std;

/**
* Main function to run all three algorithms
* args[1] = character for what search you want
* args[2] = the file we want to operate on
*/
int main(int argc, char** args) {
	
	ifstream mazefile(args[2]);
	vector< vector<cell*> > Maze;
	cell * P;
	cell * dot;
	string line;
	int row = 0;
	while (getline(mazefile, line)) {
		vector <cell*> curLineofCells;
		// for each element in the line
		for (int col = 0; col < line.size(); col++) {
			cell* curCell = new cell;
			curCell->x = col;
			curCell->y = row;
			switch (line[col]) {
				case '%':
					curCell->curChar = '%';
					curCell->wall = true; 
					curLineofCells.push_back(curCell);
					break;
				case ' ':
					curCell->curChar = ' ';
					curLineofCells.push_back(curCell);
					break;
				case '.': 
					curCell->curChar = '.';
					curCell->end = true;
					dot = curCell;
					curLineofCells.push_back(curCell);
					break;
				case 'P':
					curCell->curChar = 'P';
					curCell->start = true;
					P = curCell;
					curLineofCells.push_back(curCell);
					break;
				default:
					break;
			}
		}
		row++;
		Maze.push_back(curLineofCells);
	}
	cout << "the size of the maze is width x height: "<< Maze[0].size() << 'x' << Maze.size()<<'\n';
	cout << "the maze constructed is: \n";
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			cout << Maze[i][j]->curChar;
		}
		cout << '\n';
	}
	mazefile.close();
	switch(args[1][0]){
		case 'd':
			
		case 'b':
			cout<<"Calling Breadth-First Search\n";
			BFS(P, dot, Maze);

		
	}
	cout << "The starting coordinate is [" <<P->y<<','<<P->x<<"]\n";
	cout << "The ending coordinate is [" <<dot->y<<','<<dot->x<<"]\n";
	// Greedy::calculate_manhattan_distance(dot, P);
	cout << dot->manhattan_dist<<'\n';
	return 0;
}