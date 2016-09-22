#include "bfs.h"
#include "cell.h"

using namespace std;

int BFS(cell * start, cell * end, vector< vector<cell*> > Maze)
{
	printf("%s\n", "BFS has started.");

	queue<cell*> q;

	start->distance = 0;
	q.push(start);

	while (!q.empty()) {
		cell * curr = q.front();
		q.pop();

		cell * k = curr; //placeholder
		//for each node k that is adjacent to curr: {
			if (k->distance == numeric_limits<int>::max()) {
				k->distance = curr->distance + 1;
				k->parent = curr;
				q.push(k);
			}
		//}

	}
    return 0;
}