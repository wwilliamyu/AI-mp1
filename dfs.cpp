#include "dfs.h"
#include "cell.h"

using namespace std;

int DFS(cell * start, cell * end, vector< vector<cell*> > Maze)
{
    stack<cell *> s;
    s.push(start);
    while (!s.empty()) {
    	start = s.top();
    	s.pop();
    	//if start not labeled as discovered:
    		//label start as discovered
    		// for all edges from start to end in Maze.adjacentEdges do
    			s.push(start);
    }

    return 0;
}