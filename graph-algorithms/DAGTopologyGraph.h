#pragma once
#include"StdGraphDimensions.h"
#include<vector>
#include<list>


namespace Basic {

	class DAGTopologyGraph : public StandardGraphClass {
	private:
		std::vector<bool> VisitedList;
		std::list<int> TopologyOrder;
	public:
		void CreateTopologyGraph(int);
		DAGTopologyGraph(int, int, std::vector<std::pair<int, int>>);
		std::list<int> getTopologyOrder();
	};
}

Basic::DAGTopologyGraph::DAGTopologyGraph(int n, int m, std::vector<std::pair<int, int>> EdgeList)
	: StandardGraphClass(n, m) {

	for (int i = 0; i <= n; i++)
		VisitedList.push_back(false);
	

	for (int i = 0; i < EdgeList.size(); i++)
		AdjacencyList[EdgeList[i].first].push_back(EdgeList[i].second);
	

	if (n > 0)
		for (int i = 1; i <= n; i++) {
			if (VisitedList[i] == true) continue;
			else {
				CreateTopologyGraph(i);
				TopologyOrder.push_front(i);
			}
		}

}

void Basic::DAGTopologyGraph::CreateTopologyGraph(int i) {
	VisitedList[i] = true;
	int itr = 0;
	while (itr < AdjacencyList[i].size()) {

		if (false == VisitedList[AdjacencyList[i][itr]]) {
			CreateTopologyGraph((int)AdjacencyList[i][itr]);
			TopologyOrder.push_front(AdjacencyList[i][itr]);
		}

		++itr;
	}
}

std::list<int> Basic::DAGTopologyGraph::getTopologyOrder() {
	return TopologyOrder;
}