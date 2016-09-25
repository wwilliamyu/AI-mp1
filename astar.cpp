#include "astar.h"
	

using namespace std;

int AStar::astar_single(vector< vector<cell*> > &Maze, cell* start, cell*goal) {
	cell * curCell;
	int total=0;
	priority_queue <cell*, vector<cell*>, greaterEvaluation> frontier;
	start->visited = true;
	start->total_cost = 0;
	frontier.push(start);
	while (!frontier.empty()){
		curCell = frontier.top();
		frontier.pop();
		if (curCell->x + 1 < Maze[0].size()) //if not at the right border, go right
			AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x + 1]);
		if (curCell->y + 1 < Maze.size()) //if not at the bottom border, the go down
			AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y + 1][curCell->x]);
		if (curCell->x -1 >= 0) //if not at the left border, go left
			AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x - 1]);
		if (curCell->y - 1 >= 0) //if not at the top border, the go up
			AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y - 1][curCell->x]);
		if (curCell == goal)
		{
			break;
			total=curCell->total_cost;
		}
	}
	AStar::astar_generatePath(goal);
	AStar::astar_printResult(Maze, start, goal);
	return total;
}

void AStar::astar_checkFrontier(priority_queue <cell*, vector<cell*>, greaterEvaluation> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell) {
	if (curCell->visited || curCell->wall)
		return;
	// cout << "curCell to push to <frontier></frontier> is [" << curCell->y << ',' << curCell->x << "]\n";
	curCell->preCell = preCell;
	curCell->visited = true;
	curCell->curChar = '.';
	curCell->total_cost = preCell->total_cost + 1;
	frontier.push(curCell);
}

void AStar::astar_printResult(vector< vector<cell*> > &Maze, cell* start, cell* goal) {
	cout << "printing the output maze of A* search with path: \n";
	goal->curChar = '*';
	int pathCost = 0;
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			cell * curCell = Maze[i][j];
			cout << curCell->curChar;
			// cout << curCell->total_cost <<'\n';
			if (curCell->curChar == '*')
				pathCost++;
		}
		cout << '\n';
	}
	cout << "The total path cost from the starting point to reach the goal is " << pathCost << '\n';
}

void AStar::astar_generatePath(cell* goal) {
	cell * curCell = goal;
	while (curCell->preCell != NULL) {
		curCell->curChar = '*';
		curCell = curCell->preCell;
	}
}