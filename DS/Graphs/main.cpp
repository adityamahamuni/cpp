#include<iostream>
#include<vector>
#include"TreeTraversal.h"

int main() {

	std::vector<std::vector<int>> graph = { {0, 0, 0, 0, 0, 0, 0},
								{0, 0, 1, 1, 0, 0, 0},
								{0, 1, 0, 0, 1, 0, 0},
								{0, 1, 0, 0, 1, 0, 0},
								{0, 0, 1, 1, 0, 1, 1},
								{0, 0, 0, 0, 1, 0, 0},
								{0, 0, 0, 0, 1, 0, 0} };

	BFS(graph, 3, 7);

	return 0;
}