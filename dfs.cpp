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

            curr->visited = true;
            if (curr->x + 1 < Maze[0].size() && Maze[curr->y][curr->x + 1]->wall != true) {
                DFS_expand(Maze, s, curr, Maze[curr->y][curr->x + 1]); // RIGHT
            }
            if (curr->y + 1 < Maze.size() && Maze[curr->y + 1][curr->x]->wall != true) {
                DFS_expand(Maze, s, curr, Maze[curr->y + 1][curr->x]); // DOWN
            }
            if (curr->x - 1 >= 0 && Maze[curr->y][curr->x - 1]->wall != true) {
                DFS_expand(Maze, s, curr, Maze[curr->y][curr->x - 1]); // LEFT
            }
            if (curr->y - 1 >= 0 && Maze[curr->y - 1][curr->x]->wall != true) {
                DFS_expand(Maze, s, curr, Maze[curr->y - 1][curr->x]); // UP
            }
        }
    }
    cell * curCell = end;
    while (curCell->preCell != NULL) {
        curCell->curChar = '.';
        curCell = curCell->preCell;
    }
}

void DepthFS::DFS_expand(vector< vector<cell*> >& Maze, stack<cell*>& s, cell* curr, cell* new_cell) {

    // FOUR NODES ONLY
    if (!new_cell->wall && !new_cell->visited) {
        new_cell->preCell = curr;
        if (curr->start == true) {
            curr->curChar = 'P';
        }
        else {
            curr->curChar = '*';
        }
        s.push(new_cell);
    }
    return;
}