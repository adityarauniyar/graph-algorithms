#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include"StdGraphDimensions.h"
#include <queue>

// ---------- Problem Description -----------------
// Task.Given an directed graph with possibly negative edge weights and with 𝑛 vertices and 𝑚 edges, check
// whether it contains a cycle of negative weight.
// Input Format.A graph is given in the standard format.
// Constraints. 1 ≤ 𝑛 ≤ 1e3
// , 0 ≤ 𝑚 ≤ 1e4
// , edge weights are integers of absolute value at most 1e3
// .
// Output Format.Output 1 if the graph contains a cycle of negative weight and 0 otherwise.

namespace Adv {

	class DetectingAnomalies : public StandardGraphClass
	{
	private:
		std::vector<llong> MinDistID;
		bool containsAnomoly = false;
		std::vector<bool> isVisited;
		std::vector<bool> vCallStack;
	public:
		void DetectAnomalies(int);
		DetectingAnomalies(int, int, std::vector<std::vector<llong>>, bool);
		bool checkForAnomoly() { return (containsAnomoly) ? 1 : 0; }
		DetectingAnomalies static Input();
	};

}

void Adv::DetectingAnomalies::DetectAnomalies(const int iVertex) {
	// Detecting -ve cycles using DFS and exiting as soon as -ve cycle is encountered. 
	// Time Complexivity : O(|numVertics|+|numEdges|)

	isVisited[iVertex] = true;
	
	for (int i = 0; i < AdjacencyListWithWeights[iVertex].size() && !containsAnomoly; i++) {
		int AdjDist = AdjacencyListWithWeights[iVertex][i].second;
		int AdjVtx = AdjacencyListWithWeights[iVertex][i].first;
		if (MinDistID[AdjVtx] > MinDistID[iVertex] + AdjDist) {
			if (vCallStack[AdjVtx]) {
				containsAnomoly = true;
				break;
			}
			MinDistID[AdjVtx] = MinDistID[iVertex] + AdjDist;
			vCallStack[AdjVtx] = true;
			DetectAnomalies(AdjVtx);
			vCallStack[AdjVtx] = false;
		}

	}


}

Adv::DetectingAnomalies::DetectingAnomalies(int n, int m, std::vector<std::vector<llong>> EdgeListWithWeights, const bool isDirected)
	: StandardGraphClass(n, m, EdgeListWithWeights, isDirected) {

	for (int i = 0; i <= n; i++) {
		vCallStack.push_back(false);
		isVisited.push_back(false);
		/*if (i == 1) 
			MinDistID.push_back(0);
		else */
			MinDistID.push_back(LLONG_MAX);
	}

	
	// Visiting all the unvisted nodes.
	for (int i = 1; i < n; i++) {
		if (!isVisited[i]) {
			MinDistID[i] = 0;
			vCallStack[i] = true;
			DetectAnomalies(i);
			vCallStack[i] = false;
		}
	}
	
}

Adv::DetectingAnomalies Adv::DetectingAnomalies::Input() {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;

	StdGraphInputsWithWts(n, m, EdgeList);

	return Adv::DetectingAnomalies(n, m, EdgeList, true);
}
