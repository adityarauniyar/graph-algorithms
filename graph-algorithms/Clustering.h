#pragma once
#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "DataStructures.h"

// PROBLEM STATEMENT
// Task.Given 𝑛 points on a plane and an integer 𝑘, compute the largest possible value of 𝑑 such that the
// given points can be partitioned into 𝑘 non - empty subsets in such a way that the distance between any
// two points from different subsets is at least 𝑑.
// Input Format.The first line contains the number 𝑛 of points.Each of the following 𝑛 lines defines a point
// (𝑥𝑖
// 	, 𝑦𝑖).The last line contains the number 𝑘 of clusters.
// 	Constraints. 2 ≤ 𝑘 ≤ 𝑛 ≤ 200; −1e3 ≤ 𝑥𝑖
// 	, 𝑦𝑖 ≤ 1e3 are integers.All points are pairwise different.
// 	Output Format.Output the largest value of 𝑑.The absolute value of the difference between the answer of
// 	your program and the optimal value should be at most 1e−6
// 	.To ensure this, output your answer with
// 	at least seven digits after the decimal point(otherwise your answer, while being computed correctly,
// 		can turn out to be wrong because of rounding issues).

namespace Adv {

	class Clustering
	{
	private:
		int numCluster;
		int numCoordinates;
		double MinClusterDistance;
		std::vector<std::pair<int, int>> CoordinatePairs;
		// [0] <- weight; [1] <- First Vertex; [2] <- Second Vertex
		std::vector<std::vector<double>> EdgeListWithWeights;
		void ComputeEdgeListFromCoordinates(void);
		double FindEucludianDistance(const int &x1, const int &y1, const int &x2, const int &y2);
		void FindMinClusterDistance();
	public:
		static bool CompareEdgeWtsAsc(const std::vector<double> &e1, const std::vector<double> &e2) {
			return e1[0] < e2[0];
		}
		Clustering(int, std::vector<std::pair<int, int>>, int);
		double getMinClusterDistance() { return MinClusterDistance; }
	};

}

double Adv::Clustering::FindEucludianDistance(const int &x1, const int &y1, const int &x2, const int &y2) {
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

void Adv::Clustering::ComputeEdgeListFromCoordinates() {

	for (int i = 0; i < numCoordinates - 1; i++) {
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


void Adv::Clustering::FindMinClusterDistance() {

	std::sort(EdgeListWithWeights.begin(), EdgeListWithWeights.end(), CompareEdgeWtsAsc);
	CustDS::DisjointSets DjS(numCoordinates);

	int EdgesAdded = 0;

	for (int i = 0; i < EdgeListWithWeights.size(); i++) {
		int v1 = EdgeListWithWeights[i][1],
			v2 = EdgeListWithWeights[i][2];
		double EdgeCost = EdgeListWithWeights[i][0];
		if (DjS.Find(v1) != DjS.Find(v2)) {
			// To make 1 cluster, we had E = V-1; hence, for 'n' Clusters we have E = V - n
			if (EdgesAdded == numCoordinates - numCluster) {
				MinClusterDistance = EdgeCost;
				break;
			}
			DjS.Union(v1, v2);
			++EdgesAdded;
			
		}
	}
}

Adv::Clustering::Clustering(int n, std::vector<std::pair<int, int>> CoordinatePairs, int numCluster)
	: numCoordinates(n), CoordinatePairs(CoordinatePairs), numCluster(numCluster) {
	ComputeEdgeListFromCoordinates();
	FindMinClusterDistance();
}
