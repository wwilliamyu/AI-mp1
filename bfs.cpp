#include "bfs.h"
<<<<<<< HEAD
#include "dfs.h"
	


int BFS(vector<vector<cell*> > & Maze)
{
	Maze[0][0]->curChar='S';
	printf("%s\n", "bfs started");
    return 0;
=======

using namespace std;

void BreadthFS::BFS(cell* start, cell* end, vector< vector<cell*> >& Maze)
{
	queue< cell* > q;

	q.push(start);

	while (!q.empty()) {
		cell* curr = q.front();
		q.pop();
		curr->visited = true;
		if (curr == end) {
			break;
			// at goal
		}
		
		BFS_expand(Maze, q, curr, curr->x + 1, curr->y); // RIGHT
		BFS_expand(Maze, q, curr, curr->x, curr->y + 1); // DOWN
		BFS_expand(Maze, q, curr, curr->x - 1, curr-> y); // LEFT
		BFS_expand(Maze, q, curr, curr->x, curr->y - 1); // UP

	}
}

void BreadthFS::BFS_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* parent, int new_x, int new_y) {

	// FOUR NODES ONLY

	// if outside of the maze
	if (new_x < 0 || new_y < 0 || new_x > Maze[0].size() || new_y > Maze.size()) {

	}
	cell* k = Maze[new_x][new_y];
	
	if (k->visited == true || k->wall == true) {
		return;
	}
	else {
		q.push(k);
		k->preCell = parent;
		return;
	}
>>>>>>> d5e66327629a3389a4697a6018524d9afaf9be4c
}