#pragma once
#include"StdGraphDimensions.h"
#include<vector>
#include<set>


namespace Basic {

	class DAGStronglyConnected : public StandardGraphClass {
	private:
		std::vector<bool> VisitedList;
		std::map<int, std::vector<int>> ReverseAdjacencyList;
		int numConnectedGraphgs = 0;
	public:
		void ExploreDAG(int);
		void ExploreReverseDAG(int);
		DAGStronglyConnected(int, int, std::vector<std::pair<int, int>>);
		int getNumStronglyConnected();
	};
}

Basic::DAGStronglyConnected::DAGStronglyConnected(int n, int m, std::vector<std::pair<int, int>> EdgeList)
	: StandardGraphClass(n, m) {

	for (int i = 0; i <= n; i++)
		VisitedList.push_back(false);

	for (int i = 0; i < EdgeList.size(); i++)
	{
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		ReverseAdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}

	if (n > 0)
		for (int i = 1; i <= n; i++) {
			if (VisitedList[i] == true) continue;
			else {
				ExploreReverseDAG(i);
			}
		}

}

void Basic::DAGStronglyConnected::ExploreDAG(int i) {
	VisitedList[i] = true;
	int itr = 0;
	while (itr < AdjacencyList[i].size()) {

		if (false == VisitedList[AdjacencyList[i][itr]])
			ExploreDAG((int)AdjacencyList[i][itr]);

		++itr;
	}
}

void Basic::DAGStronglyConnected::ExploreReverseDAG(int i) {
	VisitedList[i] = true;
	int itr = 0;
	while (itr < ReverseAdjacencyList[i].size()) {

		if (false == VisitedList[ReverseAdjacencyList[i][itr]])
			ExploreDAG((int)ReverseAdjacencyList[i][itr]);

		++itr;
	}
}


int Basic::DAGStronglyConnected::getNumStronglyConnected() {
	return numConnectedGraphgs;
}