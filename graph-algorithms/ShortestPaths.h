#pragma once
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<sstream>
#include"StdGraphDimensions.h"

// ---------- Problem Description -----------------
// Task.Given an directed graph with possibly negative edge weights and with 𝑛 vertices and 𝑚 edges as well
// as its vertex 𝑠, compute the length of shortest paths from 𝑠 to all other vertices of the graph.
// Input Format.A graph is given in the standard format.
// Constraints. 1 ≤ 𝑛 ≤ 1e3
// , e ≤ 𝑚 ≤ 1e4
// , 1 ≤ 𝑠 ≤ 𝑛, edge weights are integers of absolute value at most
// 1e9
// .
// Output Format.For all vertices 𝑖 from 1 to 𝑛 output the following on a separate line :
// ∙ “*”, if there is no path from 𝑠 to 𝑢;
// ∙ “ - ”, if there is a path from 𝑠 to 𝑢, but there is no shortest path from 𝑠 to 𝑢(that is, the distance
// 	from 𝑠 to 𝑢 is −∞);
// ∙ the length of a shortest path otherwise.

namespace Adv {

	class ShortestPaths : public StandardGraphClass
	{
	private:
		std::vector<llong> MinDistID;
		std::vector<char> ShortestPathList;
		int CycleStartVtx;
		std::vector<bool> vCallStack;
	public:
		void FindShortestPaths(int);
		ShortestPaths(int, int, std::vector<std::vector<llong>>, bool, int);
		std::string getShortestPathList();
		ShortestPaths static Input();
	};

}

void Adv::ShortestPaths::FindShortestPaths(const int iVertex) {
	// Detecting -ve cycles using DFS and assigning LLLONG_MIN for nodes within the detected cycle. 
	// Time Complexivity : O(|numVertics|+|numEdges|)

	vCallStack[iVertex] = true;
	
	for (int i = 0; i < AdjacencyListWithWeights[iVertex].size(); i++) {
		int AdjDist = AdjacencyListWithWeights[iVertex][i].second;
		int AdjVtx = AdjacencyListWithWeights[iVertex][i].first;
		int DistToBe = MinDistID[iVertex] <= INT_MIN ? INT_MIN : MinDistID[iVertex] + AdjDist;
		if (MinDistID[AdjVtx] > DistToBe) {
			if (vCallStack[AdjVtx]) {
				MinDistID[AdjVtx] = LLONG_MIN;
				CycleStartVtx = AdjVtx;
			}				
			else {
				MinDistID[AdjVtx] = DistToBe;
				FindShortestPaths(AdjVtx);
			}
			// update the minDistance till the start of the -ve Cycle.
			// iterate over the reachable nodes from the -ve cycle by resetting 'i'.
			if (MinDistID[AdjVtx] == LLONG_MIN && vCallStack[CycleStartVtx]) {
				MinDistID[iVertex] = LLONG_MIN;
				i = -1;
			}
		}
	}

	vCallStack[iVertex] = false;
}

Adv::ShortestPaths::ShortestPaths(int n, int m, std::vector<std::vector<llong>> EdgeListWithWeights, const bool isDirected, const int Start)
	: StandardGraphClass(n, m, EdgeListWithWeights, isDirected, Start) {

	for (int i = 0; i <= n; i++) {
		vCallStack.push_back(false);
		if (i == StartVertex)
			MinDistID.push_back(0);
		else
			MinDistID.push_back(LLONG_MAX);
	}

	// Start Visiting nodes from the Start Vertex

	FindShortestPaths(StartVertex);
	
}

std::string Adv::ShortestPaths::getShortestPathList() {
	std::string Str;
	for (int i = 1; i <= n; i++) {
		if (MinDistID[i] <= INT_MIN)
			Str.push_back('-');
		else if (MinDistID[i] == LLONG_MAX)
			Str.push_back('*');
		else 
			Str += std::to_string(MinDistID[i]);
			
		if (i < n)
			Str += " ";
	}
	return Str;
}

Adv::ShortestPaths Adv::ShortestPaths::Input() {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;

	StdGraphInputsWithWts(n, m, EdgeList, Start);

	return Adv::ShortestPaths(n, m, EdgeList, true, Start);
}
