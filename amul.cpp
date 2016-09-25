#include "amul.h"
#include <limits>
	

using namespace std;
// we need a goal list, but at the same time we need all of current goals children being in the PQ(Children list) ordered by F=G+H
// G is the A* distance, H is the minmum connection distance, depending on the Goal_remaining_list

Amul::goal* Amul::setGoal(goal* current,cell* next,vector<cell*> goallist, vector< vector<cell*> >& Maze)
{
	//remove next from the goallist
	for (int i = 0; i < goallist.size(); ++i)
	{
		if(next==goallist[i])
			{
				goallist.erase(goallist.begin()+i);
				cout<<"removing the node at"<<next->y+1<<"\r\n";
				cout<<"removing the node at"<<current->the_cell->y+1<<"\r\n";
			}
	}
	for (int i = 0; i < goallist.size(); ++i)
	{
		if(current->the_cell==goallist[i])
			{
				goallist.erase(goallist.begin()+i);
				cout<<"removing the node at"<<next->y+1<<"\r\n";
				cout<<"removing the node at"<<current->the_cell->y+1<<"\r\n";
			}
	}

	cout<<"after removed\r\n";
	for (int i = 0; i < goallist.size(); ++i)
	{
		// cout<<goallist.size()<<"\r\n";
		cout<< goallist[i]->y+1<<"\r\n";
	}

	cout<<"line 29\r\n";
	goal * newone=new goal;
	newone->remaining=goallist;
	newone->the_cell=next;
	newone->pre=current;
	newone->H=GetHeuristic(next,newone->remaining);
	cout<<"The Heuristic value at y="<<newone->the_cell->y<<" is:" <<newone->H<<"\r\n";
	for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			Maze[i][j]->visited=false;
			Maze[i][j]->preCell=NULL;
			Maze[i][j]->total_cost=0;
			// if(Maze[i][j]->curChar=='*'||Maze[i][j]->curChar=='.')
			// 	Maze[i][j]->curChar=' ';
		}
	}
	newone->G=Amul::astar_single(Maze, current->the_cell, next);
	cout<<"line 34\r\n";

	newone->F=newone->H+newone->G;

	cout<<"line 34\r\n";
	return newone;
}
//
void Amul::Amul(cell* start, vector<cell*> dots, vector< vector<cell*> >& Maze){

	priority_queue <goal* ,vector<goal*>, greater> children;
	vector<goal*> goalist;
	goal * current=new goal;
	current->the_cell=start;
	current=setGoal(current,current->the_cell,dots,Maze);
	children.push(current);
	
	cout<<"The goal will be "<<current->the_cell->y+1<<"\r\n";
	goal * next=NULL;
	while(!children.empty()){
		// Pop the children with the lowest F, then push all of it's child with new updated Heuristic function and path cost.
		// continue to pop until the one of them have a zero remaining goal list and the 
		// string name;
		// std::getline (std::cin,name);
		current=children.top();
		children.pop();
		cout<<"the current height is "<<current->the_cell->y+1<<"\r\n";
		if(current->remaining.empty())
			break;
		//remove current from the goallist
		// for (int i = 0; i < current->remaining.size(); ++i)
		// {
		// 	if(current->the_cell==current->remaining[i])
		// 		current->remaining.erase(current->remaining.begin()+i);
		// }
		//push next goals to the list
		for (int i = 0; i < current->remaining.size(); ++i)
		{
			next=setGoal(current,current->remaining[i],current->remaining,Maze);
			for (int i = 0; i < current->remaining.size(); ++i)
			{
				cout<< current->remaining[i]->y+1<<"\r\n";
			}
			children.push(next);

		}

	}
		for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			Maze[i][j]->visited=false;
			Maze[i][j]->preCell=NULL;
			Maze[i][j]->total_cost=0;
			if(Maze[i][j]->curChar=='*'||Maze[i][j]->curChar=='.')
				Maze[i][j]->curChar=' ';
		}
	}
	while(next->the_cell!=start){
		for (int i = 0; i<Maze.size(); i++){
		for(int j=0; j<Maze[0].size(); j++) {
			Maze[i][j]->visited=false;
			Maze[i][j]->preCell=NULL;
			Maze[i][j]->total_cost=0;
			if(Maze[i][j]->curChar=='.')
				Maze[i][j]->curChar=' ';
			}
		}
		cout<<"from the last to the first"<<next->the_cell->y+1<<"\r\n";
		Amul::astar_single(Maze,next->pre->the_cell, next->the_cell);
		next=next->pre;
	}
}

int Amul::GetHeuristic(cell * current,vector<cell*> goallist){
	// H(next)=min_connection_distance_between_the_untraveled_nodes;
	// closest contains  
	int Heuristic;
	goallist.push_back(current);
	std::vector<int> distances;
	distances.push_back(0);
	cout<<"goal list size is"<<goallist.size()<<"\r\n";
	for (int i = 0; i < goallist.size(); ++i)
	{
		Heuristic=std::numeric_limits<int>::max();
		for (int j = 0; j < goallist.size(); ++j)
		{
			int distance=Heuristic;
			if(goallist[i]!=goallist[j])
				distance=MDistance(goallist[i],goallist[j]);
			if(distance<Heuristic)
				Heuristic=distance;
		}
		cout<<"distance is"<< Heuristic<<"\r\n";
		distances.push_back(Heuristic);
	}	
	int rest_connection_distance=0;
	sort(distances.begin(),distances.end());
	for(std::vector<int>::iterator it = distances.begin(); it != distances.end()-1; ++it)
    rest_connection_distance += *it;

	return rest_connection_distance;
}

int  Amul::MDistance(cell* a, cell* b){
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}



int Amul::astar_single(vector< vector<cell*> > &Maze, cell* start, cell*goal) {
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
			Amul::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x + 1]);
		if (curCell->y + 1 < Maze.size()) //if not at the bottom border, the go down
			Amul::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y + 1][curCell->x]);
		if (curCell->x -1 >= 0) //if not at the left border, go left
			Amul::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y][curCell->x - 1]);
		if (curCell->y - 1 >= 0) //if not at the top border, the go up
			Amul::astar_checkFrontier(frontier, Maze, curCell, Maze[curCell->y - 1][curCell->x]);
		if (curCell == goal)
		{
			break;
			total=curCell->total_cost;
		}
	}
	Amul::astar_generatePath(goal);
	// Amul::astar_printResult(Maze, start, goal);
	return total;
}

void Amul::astar_checkFrontier(priority_queue <cell*, vector<cell*>, greaterEvaluation> &frontier, vector< vector<cell*> > &Maze, cell* preCell, cell* curCell) {
	if (curCell->visited || curCell->wall)
		return;
	// cout << "curCell to push to <frontier></frontier> is [" << curCell->y << ',' << curCell->x << "]\n";
	curCell->preCell = preCell;
	curCell->visited = true;
	if(curCell->curChar!='*')
	curCell->curChar = '.';
	curCell->total_cost = preCell->total_cost + 1;
	frontier.push(curCell);
}

void Amul::astar_printResult(vector< vector<cell*> > &Maze, cell* start, cell* goal) {
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

void Amul::astar_generatePath(cell* goal) {
	cell * curCell = goal;
	while (curCell->preCell != NULL) {
		curCell->curChar = '*';
		curCell = curCell->preCell;
	}
}