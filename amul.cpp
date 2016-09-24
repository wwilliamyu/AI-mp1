#include "amul.h"
#include <limits>
	

using namespace std;
// we need a goal list, but at the same time we need all of current goals children being in the PQ(Children list) ordered by F=G+H
// G is the A* distance, H is the minmum connection distance, depending on the Goal_remaining_list
struct goal
{
	cell * the_cell;
	int H;
};


void Amul::Amul(cell* start,vector<goal*> children, vector<goal*>&Goal_remained, vector< vector<cell*> >& Maze){
	//
	int vertices_num=goallist.size();
	// int** interconnection = new int*[vertices_num];
	int big_H=0;// this is the Heuristic function for the rest nodes
	// H(j)=min_connection_distance_between_the_untraveled_nodes;
	// for(int i = 0; i < vertices_num; ++i){
 //    	interconnection[i] = new int[vertices_num];
 //    	for(int j=0;j<vertices_num;j++)
 //    	{
 //    		interconnection[i][j]=MDistance(goallist[i],goallist[j]);
 //    		interconnection[j][i]=MDistance(goallist[i],goallist[j]);
 //    	}
	// }
	cell * cur=start;
	//G is the BFS distance traveled
	//G(i,j)
	//we try to find min(G+H)
	while(!children.empty()){
		for (int j = 0; j < goallist.size(); ++i)
		{
			cell * next=goallist[j];
			int H=GetHeuristic(next);
			// get a vector of distance from current goal to the next goals G(i,j) using BFS/Then AStar
			// choose the least F=G+H
			// Go for it (pop the goal from the PQueue)
			// Then we have arrived at a new one, push its children to the goalist, 
		}
		if(goallist.empty())
		BreadthFS::BFS(start,)

	}
int Amul::GetHeuristic(cell * next,vector<cell*>&goallist){
	// H(next)=min_connection_distance_between_the_untraveled_nodes;
	// closest contains  
	int Heuristic;
	std::vector<int> distances;
	distances.push_back(0);
	for (int i = 0; i < goallist.size(); ++i)
	{
		Heuristic=std::numeric_limits<int>::max();
		for (int j = 0; i < goallist.size(); ++i)
		{
			int distance=MDistance(goallist[i],goallist[j]);
			if(distance<Heuristic)
				Heuristic=distance;
		}
		distances.push_back(Heuristic);
	}	
	int rest_connection_distance=0;
	for(std::vector<int>::iterator it = distances.begin(); it != distances.end(); ++it)
    rest_connection_distance += *it;
}

void Amul::MDistance(cell* a, cell* b){
	sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2))
}
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