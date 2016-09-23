
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
	


void astar(cell* start, cell* end, vector< vector<cell*> >& Maze)
{
	//f(n)=g(n)+h(n)
	std::vector<cell*> v;
	cell * cur=start;
	
}

bool astar_recursive(cell* cur,vector<cell*> &nodes,vector< vector<cell*> >& Maze)
{
	//TODO
	// if outside or a loop, then 
	int x=cur->x,y=cur->y;
	if (x < 0 || y < 0 || x >= Maze[0].size() || y >= Maze.size()) {
		return false;
	}
	//check if arrived destination
	if(cur->total_cost<=nodes[0]&&cur->end==true)
	{
		return true;
	}
	//check if bounced on the wall
	if(cur->curChar=='%') 
		return false;
	


	if(astar_recursive(Maze[x-1][y-1],nodes,Maze)||astar_recursive(Maze[x][y-1],nodes,Maze)||astar_recursive(Maze[x+1][y],nodes,Maze)||astar_recursive(Maze[x+1][y+1],nodes,Maze))
	{
		cur->curChar='.';
		return true;
	}




}