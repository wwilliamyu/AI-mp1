#include "bfs.h"

using namespace std;

void BreadthFS::BFS(cell* start, cell* end, vector< vector<cell*> >& Maze)
{
	queue< cell* > q;
	cell* curr;
	q.push(start);

	//int count = 0;
	while (!q.empty()) {
		curr = q.front();
		q.pop();

		if (curr == end) {
			break;
			// at goal
		}

        
		if (!curr->visited) {

            curr->visited = true;
            if (curr->x + 1 < Maze[0].size() && Maze[curr->y][curr->x + 1]->wall != true) {
                BFS_expand(Maze, q, curr, Maze[curr->y][curr->x + 1]); // RIGHT
            }
            if (curr->y + 1 < Maze.size() && Maze[curr->y + 1][curr->x]->wall != true) {
                BFS_expand(Maze, q, curr, Maze[curr->y + 1][curr->x]); // DOWN
            }
            if (curr->x - 1 >= 0 && Maze[curr->y][curr->x - 1]->wall != true) {
                BFS_expand(Maze, q, curr, Maze[curr->y][curr->x - 1]); // LEFT
            }
            if (curr->y - 1 >= 0 && Maze[curr->y - 1][curr->x]->wall != true) {
                BFS_expand(Maze, q, curr, Maze[curr->y - 1][curr->x]); // UP
            }
        }
        
	}

	// generate path
	cell * curCell = end;
	while (curCell->preCell != NULL) {
		curCell->curChar = '.';
		curCell = curCell->preCell;
	}
}

void BreadthFS::BFS_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* curr, cell* new_cell) {

	// FOUR NODES ONLY

	if (!new_cell->wall && !new_cell->visited) {
		new_cell->preCell = curr;
		// expanded nodes
		if (curr->start == true) {
			curr->curChar = 'P';
		}
		else {
			curr->curChar = '*';
		}
		q.push(new_cell);
	}
	return;
}