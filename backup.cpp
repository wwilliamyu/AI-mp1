#include "amul.h"
	

using namespace std;

void Amul::Amul(cell* start, vector<cell*>&goallist, vector< vector<cell*> >& Maze){
	//First we caculate the path cost for every possible connections in between the dots
	//Second we try every combinations of the dots using a heuristic approach
	//Heuristic approach:
	//F=(traveled+A*(interconnection in the remaining goals))


	// if we have 5 dots, a,b,c,d
	// Our starting point is a
	//Then for b: F=A*(a,b)+H(b)=A*(a,b)+min{ [A*(b,c)+A*(c,d)] , [A*(b,d)+A*(d,c)]}
	//evaluate
	// 

	/*while(!goallist.empty())
	{
		pop the next dot cell with least F in the queue,
		then push its connections
	}
	*/
	//
	//

	// cell *curCell;
	// priority_queue <cell*, vector<cell*>, greaterEvaluation> frontier;
	
	// start->visited = true;
	// start->total_cost = 0;



	// cell * curCell;
	// priority_queue <cell*, vector<cell*>, greaterEvaluation> frontier;
	// start->visited = true;
	// start->total_cost = 0;
	// frontier.push(start);
	// while (!frontier.empty()){
	// 	curCell = frontier.top();
	// 	frontier.pop();
	// 	if (curCell->x + 1 < Maze[0].size()) //if not at the right border, go right
	// 		AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x + 1]);
	// 	if (curCell->y + 1 < Maze.size()) //if not at the bottom border, the go down
	// 		AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y + 1][curCell->x]);
	// 	if (curCell->x -1 >= 0) //if not at the left border, go left
	// 		AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x - 1]);
	// 	if (curCell->y - 1 >= 0) //if not at the top border, the go up
	// 		AStar::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y - 1][curCell->x]);

	// 	//reached a dot, then remove from the goal list
	// 	if (curCell == goal)
	// 	{

	// 	}
			
	// }
	// AStar::astar_generatePath(goal);
	// AStar::astar_printResult(Maze, start, goal);
}


// void Amulti::amul_checkFrontier(priority_queue <cell*, vector<cell*>, greaterEvaluation> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell) {
// 	if (curCell->wall)
// 		return;
// 	// cout << "curCell to push to <frontier></frontier> is [" << curCell->y << ',' << curCell->x << "]\n";
// 	curCell->preCell = preCell;
// 	curCell->visited = true;
// 	curCell->curChar = '.';
// 	curCell->total_cost = preCell->total_cost + 1;
// 	frontier.push(curCell);
// }

// void Amulti::amul_printResult(vector< vector<cell*> > &Maze, cell* start, cell* goal) {
// 	cout << "printing the output maze of A* search with path: \n";
// 	goal->curChar = '*';
// 	int pathCost = 0;
// 	for (int i = 0; i<Maze.size(); i++){
// 		for(int j=0; j<Maze[0].size(); j++) {
// 			cell * curCell = Maze[i][j];
// 			cout << curCell->curChar;
// 			// cout << curCell->total_cost <<'\n';
// 			if (curCell->curChar == '*')
// 				pathCost++;
// 		}
// 		cout << '\n';
// 	}
// 	cout << "The total path cost from the starting point to reach the goal is " << pathCost << '\n';
// }

// void Amulti::amul_generatePath(cell* goal) {
// 	cell * curCell = goal;
// 	while (curCell->preCell != NULL) {
// 		curCell->curChar = '*';
// 		curCell = curCell->preCell;
// 	}
// }