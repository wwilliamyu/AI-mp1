#ifndef ASTAR_H
#define ASTAR_H
#include "cell.h"
using namespace std;

void astar(cell* start, cell* end, vector< vector<cell*> >& Maze);
bool astar_recursive(cell* cur,vector<cell*> nodes,vector< vector<cell*> >& Maze)
#endif