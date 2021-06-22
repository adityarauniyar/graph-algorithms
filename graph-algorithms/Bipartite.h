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

	class Bipartite : public StandardGraphClass
	{
	private:
		std::vector<int> DistanceList;
	public:
		bool isBipartite = true;
		void Explore(int);
		Bipartite(int, int, std::vector<std::pair<int, int>>);
		Bipartite static Input();
	};

}

void Basic::Bipartite::Explore(int u) {
	// Breadth-First-Search of Time Complexity O(|n| + |m|)
	std::queue<int> BFSqueue;
	BFSqueue.push(u);
	DistanceList[u] = 0;

	while (!BFSqueue.empty() && isBipartite) {
		int tempU = BFSqueue.front();
		BFSqueue.pop();

		for (int i = 0; i < AdjacencyList[tempU].size() && isBipartite; i++) {
			if (DistanceList[AdjacencyList[tempU][i]] == -1) {
				BFSqueue.push(AdjacencyList[tempU][i]);
				DistanceList[AdjacencyList[tempU][i]] = DistanceList[tempU] + 1;
			}
			else if (DistanceList[AdjacencyList[tempU][i]] == DistanceList[tempU])
				isBipartite = false;
		}
	}
}

Basic::Bipartite::Bipartite(int n, int m, std::vector<std::pair<int, int>> EdgeList) 
	: StandardGraphClass(n, m){

	for (int i = 0; i <= n; i++) {
		DistanceList.push_back(-1);
	}

	for (int i = 0; i < EdgeList.size(); i++) {
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		AdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}

	Explore(1);
}

Basic::Bipartite Basic::Bipartite::Input() {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;

	StandardGraphClass::StdGraphInputs(n, m, EdgeList);

	int u, v;

	// Vertices to determince if they meet.
	std::cout << std::endl << "Enter vertices to determince if they meet (u v): ";
	std::cin >> u >> v;

	return Basic::Bipartite(n, m, EdgeList);
}
