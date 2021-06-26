#pragma once
#include"StdGraphDimensions.h"
#include<vector>
#include<set>


namespace Adv {

	class DirectedAcyclicGraph : public StandardGraphClass {
	private:
		std::vector<bool> VisitedList;
		std::set<int> recurStack;
	public:
		bool containsCycles = false;
		void ExploreCyclic(int);
		DirectedAcyclicGraph(int, int, std::vector<std::pair<int, int>>);
	};
}

Adv::DirectedAcyclicGraph::DirectedAcyclicGraph(int n, int m, std::vector<std::pair<int, int>> EdgeList)
	: StandardGraphClass(n, m) {
	for (int i = 0; i <= n; i++)
	{
		VisitedList.push_back(false);
	}

	for (int i = 0; i < EdgeList.size(); i++)
	{
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
	}

	if (n > 0)
		for (int i = 1; i <= n; i++) {
			if (VisitedList[i] == true) continue;
			else {
				recurStack.insert(i);
				ExploreCyclic(i);
				recurStack.erase(recurStack.find(i));
			}
		}

}

void Adv::DirectedAcyclicGraph::ExploreCyclic(int i) {
	VisitedList[i] = true;
	int itr = 0;
	while (itr < AdjacencyList[i].size() && !containsCycles) {
		
		if (false == VisitedList[AdjacencyList[i][itr]]) {
			recurStack.insert(AdjacencyList[i][itr]);
			ExploreCyclic((int)AdjacencyList[i][itr]);
			recurStack.erase(recurStack.find(AdjacencyList[i][itr]));
		}
		else 
			if (recurStack.end() != recurStack.find(AdjacencyList[i][itr])) containsCycles = true;

		++itr;
	}
}