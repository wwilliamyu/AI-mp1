#include "greedy.h"
#include "cell.h"

void calculate_manhattan_distance(cell * curCell, cell * dot) {
	curCell->manhattan_dist = sqrt(pow(dot->x - curCell->x,2) + pow(dot->y - curCell->y, 2));
}