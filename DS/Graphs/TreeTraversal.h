#pragma once
<<<<<<< HEAD
#ifndef BFS_H_
#define BFS_H_
=======
#ifndef _TREE_TRAVERSAL_H_
#define _TREE_TRAVERSAL_H_
>>>>>>> BFS Tree Traversal

#include<iostream>
#include<vector>
#include<queue>


void BFS(std::vector<std::vector<int>> graph, int start, int n) {

	int i = start, j;
	int visited[n] = { 0 };
	std::queue<int> q;

	std::cout << i << " ";
	visited[i] = 1;

	q.push(i);

	while (!q.empty()) {
		i = q.front();
		q.pop();
		for (j = 1; j < n; j++) {
			if (graph[i][j] == 1 && visited[j] == 0) {
				std::cout << j << " ";
				visited[j] = 1;
				q.push(j);
			}
		}
	}
}

<<<<<<< HEAD
#endif // !BFS_H_
=======
void DFS(std::vector<std::vector<int>> graph, int start, const int n) {

	static std::vector<int> visited (n, 0);
	int j;

	if (visited[start] == 0) {
		std::cout << start << " ";
		visited[start] = 1;

		for (j = 1; j < n; j++) {
			if (graph[start][j] == 1 && visited[j] == 0)
				DFS(graph, j, n);
		}
	}
}

#endif // !_TREE_TRAVERSAL_H_
>>>>>>> BFS Tree Traversal

