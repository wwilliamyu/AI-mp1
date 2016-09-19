#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>

using namespace std;

struct cell {
	
	public:
		bool wall;
		bool visited;
		cell* previous;
		
		int x;
		int y;
	
		int manhattan_dist;
		cell* nearest_goal;
		int step_cost;
		int total_cost;
		int goal_order;

		cell() : 
			visited(false), 
			previous(NULL), 
			manhattan_dist(0), 
			step_cost(0), 
			goal_order(-1) {}
};

// struct node {
// 	node* parent;

// 	node* childA;
// 	node* childB;
// 	node* childC;
// 	node* childD;
// };

int main(int argc, char** args) {

	// args[1] = character for what search you want
	// args[2] = the file we want to operate on

	ofstream myfile;
	myfile.open(args[2]);

	string line;
	int num_rows = 0;
	int num_cols = 0;

	// get maze dimensions
	while (getline(myfile, line)) {
		num_rows = line.size();
		num_cols++;
	}
	
	// declare the Maze
	cell Maze[num_rows][num_cols];



	myfile.close();
	return 0;

	
}