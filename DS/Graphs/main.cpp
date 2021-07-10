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

	std::cout << "BFS Traversal : " << std::endl;
	BFS(graph, 1, 7);

	std::cout << std::endl;

	std::cout << "DFS Traversal : " << std::endl;
	DFS(graph, 4, 7);

	return 0;
}