#pragma once
#include<iostream>
#include<vector>

namespace CustDS {
	class DisjointSets {
	private:
		std::vector<int> Parent;
		std::vector<int> Rank;
	public:
		DisjointSets(int);
		int Find(const int&);
		void Union(const int&, const int&);
	};
}

CustDS::DisjointSets::DisjointSets(int numElements) {
	for (int i = 0; i < numElements; i++) {
		Parent.push_back(i);
		Rank.push_back(0);
	}
}

int CustDS::DisjointSets::Find(const int& node) {
	if (node != Parent[node])
		Parent[node] = Find(Parent[node]);
	
	// Not updating Rank of the node coz we dont want to mode heavy disjoint set to liter one.
	// Reason: the leaf nodes in th set would again need to undergo Find() operation for heuristically updating 
	//		its parent node. Hence better do it for the lighter one as it would mostly contain lesser nodes.
	return Parent[node];
}

void CustDS::DisjointSets::Union(const int& node1, const int& node2) {
	int Parent1 = Find(node1);
	int Parent2 = Find(node2);

	if (Parent1 == Parent2)
		return;

	if (Rank[Parent1] > Rank[Parent2])
		Parent[Parent2] = Parent[Parent1];
	else {
		Parent[Parent1] = Parent[Parent2];
		if (Rank[Parent1] == Rank[Parent2])
			Rank[Parent2]++;
	}
}

