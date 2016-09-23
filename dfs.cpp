#include "dfs.h"

using namespace std;

void DepthFS::DFS(cell* start, cell* end, vector< vector<cell*> >& Maze) {
    stack< cell* > s;
    cell* curr;
    s.push(start);

    while (!s.empty()) {
        curr = s.top();
        s.pop();

        if (curr == end) {
            break;
            // at goal
        }

        if (!curr->visited) {
            //cout << "iteration" << endl;
            curr->visited = true;

            if (curr->x + 1 < Maze[0].size()) {
                DFS_expand(Maze, s, curr, curr->x + 1, curr->y); // RIGHT
            }
            if (curr->y + 1 < Maze.size()) {
                DFS_expand(Maze, s, curr, curr->x, curr->y + 1); // DOWN
            }
            if (curr->x - 1 >= 0) {
                DFS_expand(Maze, s, curr, curr->x - 1, curr-> y); // LEFT
            }
            if (curr->y - 1 >= 0) {
                DFS_expand(Maze, s, curr, curr->x, curr->y - 1); // UP
            }
            
        }
    }
}

void DepthFS::DFS_expand(vector< vector<cell*> >& Maze, stack<cell*>& s, cell* parent, int new_x, int new_y) {
    // FOUR NODES ONLY

    // if outside of the maze

    cell* k = Maze[new_x][new_y];
    if (k->visited == true || k->wall == true) {
        return;
    }
    else {
        s.push(k);
        k->preCell = parent;
        return;
    }
}