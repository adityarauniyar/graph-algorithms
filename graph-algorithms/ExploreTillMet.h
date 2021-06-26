#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<map>
#include"StdGraphDimensions.h"


// ---------- Problem Description -----------------
// Task. Given an undirected graph and two distinct vertices 𝑢 and 𝑣, check if there is a path between 𝑢 and 𝑣.
// Input Format. An undirected graph with 𝑛 vertices and 𝑚 edges.The next line contains two vertices 𝑢
//	and 𝑣 of the graph.
// Constraints. 2 ≤ 𝑛 ≤ 103
//  ; 1 ≤ 𝑚 ≤ 103
//  ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 𝑢 ̸ = 𝑣.
// Output Format. Output 1 if there is a path between 𝑢 and 𝑣 and 0 otherwise.
// Memory Limit. 512MB

namespace Adv {

	class ExploreTillMet : public StandardGraphClass
	{
		private:
			int u, v;
			std::vector<bool> VisitedList;
		public:
			bool isReachable = false;
			void Explore(int);
			ExploreTillMet(int, int, std::vector<std::pair<int, int>>, int, int);
			void Display();
			ExploreTillMet static Input();

	};

}

void Adv::ExploreTillMet::Explore(int u) {
	VisitedList[u] = true;
	if (u == v) isReachable = true;
	int itr = 0;
	while (itr < AdjacencyList[u].size() && !isReachable) {
		if (false == VisitedList[AdjacencyList[u][itr]])
			Explore((int)AdjacencyList[u][itr]);
		++itr;
	}
}

Adv::ExploreTillMet::ExploreTillMet(int n, int m, std::vector<std::pair<int, int>> EdgeList, int u, int v) : StandardGraphClass(n,m), u(u), v(v) {
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

void Adv::ExploreTillMet::Display() {
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

Adv::ExploreTillMet Adv::ExploreTillMet::Input() {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	
	StandardGraphClass::StdGraphInputs(n, m, EdgeList);

	int u, v;

	// Vertices to determince if they meet.
	std::cout << std::endl << "Enter vertices to determince if they meet (u v): ";
	std::cin >> u >> v;

	return Adv::ExploreTillMet(n, m, EdgeList, u, v);
}
