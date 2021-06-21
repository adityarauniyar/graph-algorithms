#pragma once
#include"StdGraphDimensions.h"
#include<vector>


namespace Basic {

	class DAGStronglyConnected : public StandardGraphClass {
	private:
		enum vertexStatus {
			FWDVISITED,
			UNVISITED, 
			BKDVISITED,
		};

		std::vector<vertexStatus> VisitedList;
		std::map<int, std::vector<int>> ReverseAdjacencyList;
		std::list<int> postOrderList;;
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
		VisitedList.push_back(UNVISITED);

	for (int i = 0; i < EdgeList.size(); i++)
	{
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
		ReverseAdjacencyList[EdgeList[i].second].push_back(EdgeList[i].first);
	}
	

	// calculating SCC in DAG

	if (n > 0) {

		// Exploring Reverse DAG
		for (int i = 1; i <= n; i++) {
			if (VisitedList[i] == BKDVISITED) continue;
			else {
				ExploreReverseDAG(i);
				postOrderList.push_front(i);
			}
		}

		// Exploring DAG with SCC increaments
		for (int i = 1; i <= n; i++) {
			if (VisitedList[postOrderList.front()] == FWDVISITED) {
				postOrderList.pop_front();
				continue;
			}
			else {
				++numConnectedGraphgs;
				ExploreDAG(postOrderList.front());
				postOrderList.pop_front();
			}
		}
	}

}

void Basic::DAGStronglyConnected::ExploreDAG(int i) {
	VisitedList[i] = FWDVISITED;
	int itr = 0;
	while (itr < AdjacencyList[i].size()) {

		if (FWDVISITED != VisitedList[AdjacencyList[i][itr]])
			ExploreDAG((int)AdjacencyList[i][itr]);

		++itr;
	}
}

void Basic::DAGStronglyConnected::ExploreReverseDAG(int i) {
	VisitedList[i] = BKDVISITED;
	int itr = 0;
	while (itr < ReverseAdjacencyList[i].size()) {

		if (BKDVISITED != VisitedList[ReverseAdjacencyList[i][itr]]) {
			ExploreReverseDAG((int)ReverseAdjacencyList[i][itr]);
			postOrderList.push_front(ReverseAdjacencyList[i][itr]);
		}
		++itr;
	}
}


int Basic::DAGStronglyConnected::getNumStronglyConnected() {
	return numConnectedGraphgs;
}