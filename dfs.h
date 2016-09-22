#ifndef DFS_H
#define DFS_H

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
int DFS(cell * start, cell * end, vector< vector<cell*> > Maze);

#endif