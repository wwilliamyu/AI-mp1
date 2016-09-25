#include "amul.h"
#include <limits>
	

using namespace std;
// we need a goal list, but at the same time we need all of current goals children being in the PQ(Children list) ordered by F=G+H
// G is the A* distance, H is the minmum connection distance, depending on the Goal_remaining_list

Amul::goal* Amul::setGoal(goal* current,goal* next,vector<cell*> goallist, vector< vector<cell*> >& Maze)
{
	//remove current from the goallist
	for (int i = 0; i < goallist.size(); ++i)
	{
		if(current->the_cell==goallist[i])
			goallist.erase(goallist.begin()+i);
	}

	goal * newone=new goal;
	newone->remaining=goallist;
	newone->H=GetHeuristic(next,newone->remaining);
	newone->G=AStar::astar_single(Maze, current->the_cell, next->the_cell);
	newone->F=newone->H+newone->G;
	return newone;
}
//
void Amul::Amul(cell* start, vector<cell*> dots, vector< vector<cell*> >& Maze){

	priority_queue <goal*,vector<goal*>, greater> children;
	vector<goal*> goalist;
	goal * current;
	current->the_cell=start;
	current=setGoal(current,current,dots,Maze);
	children.push(current);
	while(!children.empty()){
		// Pop the children with the lowest F, then push all of it's child with new updated Heuristic function and path cost.
		// continue to pop until the one of them have a zero remaining goal list and the 
		current=children.pop();

		if(current->remaining.empty())
			break;
		//remove current from the goallist

		for (int i = 0; i < current->remaining.size(); ++i)
		{
			if(current->the_cell==current->remaining[i])
				current.remaining.erase(current->remaining.begin()+i);
		}
		//push next goals to the list
		for (int i = 0; i < dots.size(); ++i)
		{
			children.push(setGoal(current,dots,Maze));
		}

	}

int Amul::GetHeuristic(goal * current,vector<goal*>&goallist){
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
			int distance=Heuristic;
			if(goallist[i]!=current)
				distance=MDistance(goallist[i]->the_cell,goallist[j]->the_cell);
			if(distance<Heuristic)
				Heuristic=distance;
		}
		distances.push_back(Heuristic);
	}	
	int rest_connection_distance=0;
	sort(distances);
	for(std::vector<int>::iterator it = distances.begin(); it != distances.end()-1; ++it)
    rest_connection_distance += *it;

	return rest_connection_distance;
}

void Amul::MDistance(cell* a, cell* b){
	sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2))
}
