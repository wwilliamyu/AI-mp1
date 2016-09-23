#ifndef BFS_H
#define BFS_H
<<<<<<< HEAD
#include "cell.h"
using namespace std;

// This is the content of the .h file, which is where the declarations go
int BFS(vector< vector<cell*> > & Maze);
 
=======

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
#include "cell.h"

using namespace std;
// This is the content of the .h file, which is where the declarations go

namespace BreadthFS {

	void BFS(cell* start, cell* end, vector< vector<cell*> >& Maze);

	void BFS_expand(vector< vector<cell*> >& Maze, queue<cell*>& q, cell* parent, int new_x, int new_y);
	
}
>>>>>>> d5e66327629a3389a4697a6018524d9afaf9be4c

#endif