#include "bfs.h"
#include "cell.h"

int BFS(cell * start, cell * end, vector< vector<cell*> > Maze)
{
	printf("%s\n", "BFS has started.");

	for (int i = 0; i < Maze.size(); i++) {
		for (int j = 0; j < Maze[i].size(); j++) {
			// set distance to infinity
			Maze[i][j]->distance = numeric_limits<int>::max();
			Maze[i][j]-> parent = NULL;
		}

		queue<cell*> q;

		start->distance = 0;
		q.enqueue(start);

		while (!q.empty) {
			cell * curr = q.dequeue();

		}
	}

	printf("%s\n", "BFS has ended.");
    return 0;
}