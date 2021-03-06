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
#include "cell.h"
#include "bfs.h"
#include "dfs.h"
#include "greedy_search.h"
#include "astar.h"
#include "amul.h"



using namespace std;

/**
* Main function to run all three algorithms
* args[1] = character for what search you want
* args[2] = the file we want to operate on
*/
int main(int argc, char** args) {

	// error if bad command
	if (argc != 3) {
 		cout << "Wrong input format. ./mp1 [algorithm] [input file path]. algorithm options are d,b,g,a, A\n";
		return 1; 
	}
	ifstream mazefile(args[2]);
	vector< vector<cell*> > Maze;
	vector<cell*> multidots;
	cell * P;
	cell * dot;
	string line;
	int row = 0;

	// the code that is responsible for constructing the maze properly
	while (getline(mazefile, line)) {
		if (line.size() == 1)
			continue;
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
					curCell->wall = false;
					curLineofCells.push_back(curCell);
					break;
				case '.': 
					curCell->curChar = '.';
					curCell->end = true;
					dot = curCell;
					multidots.push_back(dot);
					cout<<"pushing in the current dot position"<<curCell->x<<"\r\n";
					curLineofCells.push_back(curCell);
					break;
				case 'P':
					curCell->curChar = 'P';
					curCell->start = true;
					P = curCell;
					curLineofCells.push_back(curCell);
					multidots.push_back(P);
					break;
				default:
					break;
			}
		}
		row++;
		Maze.push_back(curLineofCells);
	}
	cout << "The size of the maze is width x height: "<< Maze[0].size() << 'x' << Maze.size()<<'\n';
	// cout << "the maze constructed is: \n";
	// for (int i = 0; i<Maze.size(); i++){
	// 	for(int j=0; j<Maze[0].size(); j++) {
	// 		cout << Maze[i][j]->curChar;
	// 	}
	// 	cout << '\n';
	// }
	mazefile.close();
	cout << "The starting coordinate is [" <<P->y<<','<<P->x<<"]\n";
	cout << "The ending coordinate is [" <<dot->y<<','<<dot->x<<"]\n";

	switch(args[1][0]){
		case 'd':
			cout<<"Calling Depth-First Search\n";
			DepthFS::DFS(P, dot, Maze);
			GreedySearch::greedy_printResult(Maze, P, dot);
			break;
		case 'b':
			cout<<"Calling Breadth-First Search\n";
			BreadthFS::BFS(P, dot, Maze);
			GreedySearch::greedy_printResult(Maze, P, dot);
			break;
		case 'g':
			cout<<"Running Greedy Best-First Algorithm for single dot\n";
			GreedySearch::calculate_manhattan_distance(Maze, dot);
			GreedySearch::greedy_single(Maze, P, dot);
			GreedySearch::greedy_printResult(Maze, P, dot);
			break;
		case 'a':
			cout<<"Running A* Algorithm for single dot\n";
			GreedySearch::calculate_manhattan_distance(Maze, dot);
			AStar::astar_single(Maze, P, dot);
			AStar::astar_printResult(Maze, P, dot);
			break;
		case 'm':
			cout<<"Runing A* Algorithm for multi dots\n";
			cout<<"the starting position"<<P->x<<"\r\n";
			Amul::Amul(P,multidots,Maze);
			Amul::astar_printResult(Maze, P, dot);
		default:
			break;
	}

	cout << "Cleaning up the memory\n";
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			delete Maze[i][j];
		}
	}
	return 0;
}