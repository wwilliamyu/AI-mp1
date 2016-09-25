#include "greedy_search.h"

using namespace std;

void GreedySearch::calculate_manhattan_distance(vector< vector<cell*> > &Maze, cell * goalCell) {
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			cell * curCell = Maze[i][j];
			curCell->manhattan_dist = sqrt(pow(curCell->x - goalCell->x, 2) + pow(curCell->y - goalCell->y, 2));
		}
	}
	cout << "Calculate Manhattan Distance finish\n";
}


void GreedySearch::greedy_single(vector< vector<cell*> > &Maze, cell* start, cell*goal) {
	cell * curCell;
	priority_queue <cell*, vector<cell*>, greaterManhattanDist> frontier;
	start->visited = true;
	frontier.push(start);

	while (!frontier.empty()){
		curCell = frontier.top();
		frontier.pop();
		if (curCell->x + 1 < Maze[0].size()) //if not at the right border, go right
			GreedySearch::greedy_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x + 1]);
		if (curCell->y + 1 < Maze.size()) //if not at the bottom border, the go down
			GreedySearch::greedy_checkFrontier(frontier, Maze, curCell, Maze[curCell->y + 1][curCell->x]);
		if (curCell->x -1 >= 0) //if not at the left border, go left
			GreedySearch::greedy_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x - 1]);
		if (curCell->y - 1 >= 0) //if not at the top border, the go up
			GreedySearch::greedy_checkFrontier(frontier, Maze, curCell, Maze[curCell->y - 1][curCell->x]);
		if (curCell == goal)
			break;
	}
	GreedySearch::greedy_generatePath(goal);
}

void GreedySearch::greedy_checkFrontier(priority_queue <cell*, vector<cell*>, greaterManhattanDist> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell) {
	if (curCell->visited || curCell->wall)
		return;
	// cout << "curCell to push to <frontier></frontier> is [" << curCell->y << ',' << curCell->x << "]\n";
	curCell->preCell = preCell;
	curCell->visited = true;
	curCell->curChar = '.';
	frontier.push(curCell);
}

int GreedySearch::greedy_printResult(vector< vector<cell*> > &Maze, cell* start, cell* goal) {
	// ofstream myfile ("example.txt");
 //  if (myfile.is_open())
 //  {
 //    myfile << "This is a line.\n";
 //    myfile << "This is another line.\n";
 //    myfile.close();
 //  }else{
 //  	cout << "Unable to open file";
 //  	return;
 //  } 
	cout << "Printing the output maze with path and expanded nodes: \n";
	goal->curChar = '*';
	int pathCost = 0;
	int expanded = 0;
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			cell * curCell = Maze[i][j];
			cout << curCell->curChar;
			if (curCell->curChar == '*')
				pathCost++;
			if (curCell->curChar == '.')
				expanded++;
		}
		cout << '\n';
	}
	cout << "The total path cost from the starting point to reach the goal is " << pathCost << ".\n";
	cout << "The number of expanded nodes is " << expanded << ".\n";
	return pathCost;
}

void GreedySearch::greedy_generatePath(cell* goal) {
	cell * curCell = goal;
	while (curCell->preCell != NULL) {
		curCell->curChar = '*';
		curCell = curCell->preCell;
	}
}