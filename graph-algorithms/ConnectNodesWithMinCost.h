#pragma once
#include<iostream>
#include<vector>
#include"StdGraphDimensions.h"
#include<algorithm>
#include "DataStructures.h"

// ---------- Problem Description -----------------
// Task.Given 𝑛 points on a plane, connect them with segments of minimum total length such that there is a
// path between any two points.Recall that the length of a segment with endpoints(𝑥1, 𝑦1) and (𝑥2, 𝑦2)
// is equal to √︀((𝑥1 − 𝑥2)^2 + (𝑦1 − 𝑦2)^2)
// Input Format.The first line contains the number 𝑛 of points.Each of the following 𝑛 lines defines a point
// (𝑥𝑖, 𝑦𝑖).
// 	Constraints. 1 ≤ 𝑛 ≤ 200; −1e3 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 1e3 are integers. All points are pairwise different, no three
// 	points lie on the same line.
// 	Output Format.Output the minimum total length of segments.The absolute value of the difference
// 	between the answer of your program and the optimal value should be at most 1e−6
// 	.To ensure this,
// 	output your answer with at least seven digits after the decimal point(otherwise your answer, while
// 		being computed correctly, can turn out to be wrong because of rounding issues).

namespace Adv {

	class ConnectNodesWithMinCost
	{
	private:
		double MinSpanTreeCost = 0;
		int numCoordinates;
		std::vector<std::pair<int, int>> CoordinatePairs;
		// [0] <- weight; [1] <- First Vertex; [2] <- Second Vertex
		std::vector<std::vector<double>> EdgeListWithWeights;
		void ComputeEdgeListFromCoordinates(void);
		double FindEucludianDistance(const int &x1, const int &y1, const int &x2, const int &y2);
		void FindMinSpanTree();
	public:
		static bool CompareEdgeWtsAsc(const std::vector<double> &e1, const std::vector<double> &e2) {
			return e1[0] < e2[0];
		}
		ConnectNodesWithMinCost(int, std::vector<std::pair<int,int>>);
		double getMinSpanTreeCost() { return MinSpanTreeCost; }
	};

}

double Adv::ConnectNodesWithMinCost::FindEucludianDistance(const int &x1, const int &y1, const int &x2, const int &y2) {
	
	return std::sqrt(std::pow(x1-x2,2) + std::pow(y1 - y2, 2));
}

void Adv::ConnectNodesWithMinCost::ComputeEdgeListFromCoordinates() {

	for (int i = 0; i < numCoordinates-1; i++) {
		for (int j = i + 1; j < numCoordinates; j++) {
			int x1 = CoordinatePairs[i].first,
				y1 = CoordinatePairs[i].second,
				x2 = CoordinatePairs[j].first,
				y2 = CoordinatePairs[j].second;
			double eDist = FindEucludianDistance(x1, y1, x2, y2);
			EdgeListWithWeights.push_back({ eDist, (double)i, (double)j });
		}
	}
}


void Adv::ConnectNodesWithMinCost::FindMinSpanTree() {

	std::sort(EdgeListWithWeights.begin(), EdgeListWithWeights.end(), CompareEdgeWtsAsc);
	CustDS::DisjointSets DjS(numCoordinates);

	int EdgesAdded = 0;

	for (int i = 0; i < EdgeListWithWeights.size() && EdgesAdded < numCoordinates-1; i++) {
		int v1 = EdgeListWithWeights[i][1],
			v2 = EdgeListWithWeights[i][2];
		double EdgeCost = EdgeListWithWeights[i][0];
		if (DjS.Find(v1) != DjS.Find(v2)) {
			DjS.Union(v1, v2);
			MinSpanTreeCost += EdgeCost;
			++EdgesAdded;
		}
	}
}

Adv::ConnectNodesWithMinCost::ConnectNodesWithMinCost(int n, std::vector<std::pair<int,int>> CoordinatePairs)
	: numCoordinates(n), CoordinatePairs(CoordinatePairs) {
	ComputeEdgeListFromCoordinates();
	FindMinSpanTree();
}
