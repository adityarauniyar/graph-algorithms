#pragma once
#include"StdGraphDimensions.h"
#include<vector>

namespace Adv {
	class ExploreConnectedGraphs : public StandardGraphClass {
	private:
		std::vector<bool> VisitedList;
	public:
		int numConnectedGraphgs = 0;
		void ExploreConnected(int);
		ExploreConnectedGraphs(int, int, std::vector<std::pair<int, int>>);
	};
}

Adv::ExploreConnectedGraphs::ExploreConnectedGraphs(int n, int m, std::vector<std::pair<int, int>> EdgeList) 
	: StandardGraphClass(n, m){
	for (int i = 0; i <= n; i++)
	{
		VisitedList.push_back(false);
	}

	for (int i = 0; i < EdgeList.size(); i++)
	{
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		AdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}

	if (n > 0)
		for (int i = 1; i <= n ; i++) {
			if (VisitedList[i] == true) continue;
			++numConnectedGraphgs;
			ExploreConnected(i);
		}
	 
}

void Adv::ExploreConnectedGraphs::ExploreConnected(int u) {
	VisitedList[u] = true;
	int itr = 0;
	while (itr < AdjacencyList[u].size()) {
		if (false == VisitedList[AdjacencyList[u][itr]])
			ExploreConnected((int)AdjacencyList[u][itr]);
		++itr;
	}
}
