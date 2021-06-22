#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include"StdGraphDimensions.h"


// ---------- Problem Description -----------------
 //  Task.Given an undirected graph with 𝑛 vertices and 𝑚 edges and two vertices 𝑢 and 𝑣, compute the length
 //  of a shortest path between 𝑢 and 𝑣(that is, the minimum number of edges in a path from 𝑢 to 𝑣).
 //  Input Format.A graph is given in the standard format.The next line contains two vertices 𝑢 and 𝑣.
 //  Constraints. 2 ≤ 𝑛 ≤ 105
 //  , 0 ≤ 𝑚 ≤ 105
 //  , 𝑢 ̸ = 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛.
 //  Output Format.Output the minimum number of edges in a path from 𝑢 to 𝑣, or −1 if there is no path.
// Memory Limit. 512MB

namespace Basic {

	class MinEdgePath : public StandardGraphClass
	{
	private:
		int u, v;
		std::vector<int> minEdgeList;
	public:
		void Explore(int);
		MinEdgePath(int, int, std::vector<std::pair<int, int>>, int, int);
		MinEdgePath static Input();
		int getMinEdge(int);
	};

}

void Basic::MinEdgePath::Explore(int u) {
	// Breadth-First-Search of Time Complexity O(|n| + |m|)
	std::queue<int> BFSqueue;
	BFSqueue.push(u);
	minEdgeList[u] = 0;

	while (!BFSqueue.empty()) {
		int tempU = BFSqueue.front();
		BFSqueue.pop();

		for (int i = 0; i < AdjacencyList[tempU].size(); i++) {
			if (minEdgeList[AdjacencyList[tempU][i]] == -1) {
				BFSqueue.push(AdjacencyList[tempU][i]);
				minEdgeList[AdjacencyList[tempU][i]] = minEdgeList[tempU]+1;
			}

			if (minEdgeList[v] != -1) break;
		}

		if (minEdgeList[v] != -1) break;
	}
}

int Basic::MinEdgePath::getMinEdge(int dest) {
	return minEdgeList[dest];
}

Basic::MinEdgePath::MinEdgePath(int n, int m, std::vector<std::pair<int, int>> EdgeList, int u, int v) : StandardGraphClass(n, m), u(u), v(v) {
	
	for (int i = 0; i <= n; i++){
		minEdgeList.push_back(-1);
	}

	for (int i = 0; i < EdgeList.size(); i++){
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		AdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}

	Explore(this->u);
}

Basic::MinEdgePath Basic::MinEdgePath::Input() {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;

	StandardGraphClass::StdGraphInputs(n, m, EdgeList);

	int u, v;

	// Vertices to determince if they meet.
	std::cout << std::endl << "Enter vertices to determince if they meet (u v): ";
	std::cin >> u >> v;

	return Basic::MinEdgePath(n, m, EdgeList, u, v);
}
