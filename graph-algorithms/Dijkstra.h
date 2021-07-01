#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include"StdGraphDimensions.h"
#include <queue>

// ---------- Problem Description -----------------
//  Task.Given an directed graph with positive edge weights and with 𝑛 vertices and 𝑚 edges as well as two
//  vertices 𝑢 and 𝑣, compute the weight of a shortest path between 𝑢 and 𝑣(that is, the minimum total
//	weight of a path from 𝑢 to 𝑣).
//	Input Format.A graph is given in the standard format.The next line contains two vertices 𝑢 and 𝑣.
//	Constraints. 1 ≤ 𝑛 ≤ 104
//	, 0 ≤ 𝑚 ≤ 105
//	, 𝑢 ̸ = 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛, edge weights are non - negative integers not
//	exceeding 108
//	.
//	Output Format.Output the minimum weight of a path from 𝑢 to 𝑣, or −1 if there is no path.

typedef std::pair<int, llong> pi;

namespace Adv {

	class Dijkstra : public StandardGraphClass
	{
	private:
		std::vector<llong> DijkstraDistance; 
	public:

		void ComputeDijkstra(void);
		Dijkstra(int, int, std::vector<std::vector<int>>, bool, int, int);
		llong GetDijkstraDistance() { return (DijkstraDistance[EndVertex]== LLONG_MAX) ? -1 : DijkstraDistance[EndVertex]; }
	};

}

void Adv::Dijkstra::ComputeDijkstra() {
	std::priority_queue<pi, std::vector<pi>, std::greater<pi> > pq;
	pq.push(std::make_pair(DijkstraDistance[StartVertex], StartVertex));

	while (!pq.empty() && pq.top().second != EndVertex) {
		pi tempVtx = pq.top();
		pq.pop();

		for (int ii = 0; ii < AdjacencyListWithWeights[tempVtx.second].size(); ii++) {
			int AdjVtx = AdjacencyListWithWeights[tempVtx.second][ii].first;
			llong AdjDistVal = AdjacencyListWithWeights[tempVtx.second][ii].second;

			if (DijkstraDistance[AdjVtx] > DijkstraDistance[tempVtx.second] + AdjDistVal) {
				DijkstraDistance[AdjVtx] = DijkstraDistance[tempVtx.second] + AdjDistVal;
				
				pq.push(std::make_pair(DijkstraDistance[AdjVtx], AdjVtx));

			}
		}
	}
}

Adv::Dijkstra::Dijkstra(int n, int m, std::vector<std::vector<int>> EdgeListWithWeights,const bool isDirected, int u, int v)
	: StandardGraphClass(n, m, EdgeListWithWeights, isDirected, u, v) {

	for (int i = 0; i <=n; i++) {
		if (i == u) DijkstraDistance.push_back(0);
		else
			DijkstraDistance.push_back(LLONG_MAX);
	}

	ComputeDijkstra();
}