#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>

// ---------- Problem Description -----------------
// Task. Given an undirected graph and two distinct vertices 𝑢 and 𝑣, check if there is a path between 𝑢 and 𝑣.
// Input Format. An undirected graph with 𝑛 vertices and 𝑚 edges.The next line contains two vertices 𝑢
//	and 𝑣 of the graph.
// Constraints. 2 ≤ 𝑛 ≤ 103
//  ; 1 ≤ 𝑚 ≤ 103
//  ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 𝑢 ̸ = 𝑣.
// Output Format. Output 1 if there is a path between 𝑢 and 𝑣 and 0 otherwise.
// Memory Limit. 512MB

namespace Basic {

	class ExploreTillMet
	{
	private:
		int n;
		int m;
		int u;
		int v;
		std::map<int, std::vector<int>> AdjacencyList;
		std::vector<bool> VisitedList;

	public:
		bool isReachable = false;
		void Explore(int);
		ExploreTillMet(int, int, std::vector<std::pair<int, int>>, int, int);
		void Display();
		ExploreTillMet static Input();

	};

}
void Basic::ExploreTillMet::Explore(int u) {
	VisitedList[u] = true;
	if (u == v) isReachable = true;
	int itr = 0;
	while (itr < AdjacencyList[u].size() && !isReachable) {
		if (false == VisitedList[AdjacencyList[u][itr]])
			Explore((int)AdjacencyList[u][itr]);
		++itr;
	}
}

Basic::ExploreTillMet::ExploreTillMet(int n, int m, std::vector<std::pair<int, int>> EdgeList, int u, int v) : n(n), m(m), u(u), v(v) {
	for (int i = 0; i <= n; i++)
	{
		VisitedList.push_back(false);
	}

	for (int i = 0; i < EdgeList.size(); i++)
	{
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		AdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}

	Explore(this->u);
}

void Basic::ExploreTillMet::Display() {
	std::cout << std::endl << " ------- OUTPUT -------" << std::endl;
	std::cout << "Vertices: " << n << std::endl;
	std::cout << "Edges: " << m << std::endl;

	std::cout << "Links: " << std::endl;

	for (int i = 1; i < n + 1; i++)
	{
		std::cout << " Vertex " << i << " is linked with: ";
		for (int j = 0; j < AdjacencyList[i].size(); j++)
			std::cout << AdjacencyList[i][j] << ", ";
		std::cout << std::endl;
	}

	std::cout << std::endl << "STATUS: Vertex " << u << " meets Vertex " << v << "? A: ";
	if (isReachable) std::cout << "TRUE" << std::endl;
	else std::cout << "FALSE" << std::endl;
}

Basic::ExploreTillMet Basic::ExploreTillMet::Input() {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::cout << "Enter (numVertices'vc' numEdges'ec'): ";
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int v1, v2;
		std::cout << std::endl << "Enter #" << i << " edge by vertex pair (v1 v2): ";
		std::cin >> v1 >> v2;
		EdgeList.push_back(std::make_pair(v1, v2));
	}

	// Vertices to determince if they meet.
	std::cout << std::endl << "Enter vertices to determince if they meet (u v): ";
	std::cin >> u >> v;

	return Basic::ExploreTillMet(n, m, EdgeList, u, v);
}
