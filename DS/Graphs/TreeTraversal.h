#pragma once
#ifndef BFS_H_
#define BFS_H_

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

#endif // !BFS_H_

