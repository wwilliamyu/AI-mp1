#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

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


	
}