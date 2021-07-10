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

	DFS(graph, 4, 7);

	return 0;
}