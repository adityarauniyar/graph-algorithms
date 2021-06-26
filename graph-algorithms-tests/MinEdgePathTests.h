#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\MinEdgePath.h"
#include"InputFromStream.h"
#include "GenerateGraphs.h"


// ---------- Problem Description -----------------
 //  Task.Given an undirected graph with 𝑛 vertices and 𝑚 edges and two vertices 𝑢 and 𝑣, compute the length
 //  of a shortest path between 𝑢 and 𝑣(that is, the minimum number of edges in a path from 𝑢 to 𝑣).
 //  Input Format.A graph is given in the standard format.The next line contains two vertices 𝑢 and 𝑣.
 //  Constraints. 2 ≤ 𝑛 ≤ 105
 //  , 0 ≤ 𝑚 ≤ 105
 //  , 𝑢 ̸ = 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛.
 //  Output Format.Output the minimum number of edges in a path from 𝑢 to 𝑣, or −1 if there is no path.
// Memory Limit. 512MB



// Stress testing with Floyd Warshall Algorithm algorithm with Time Complexity O(n^3)

TEST(MinEdgePathTests, Stress_Test) {
	const std::pair<int, int> numVertex_MinMax = { 2, 105 };
	const std::pair<int, int> numEdges_MinMax = { 0 ,105 };

	for (int test = 0; test < 1e3; test++) {
		int n, m, u, v;
		std::vector<std::pair<int, int>> EdgeList;

		GenerateGraphs(numVertex_MinMax, numEdges_MinMax, n, m, EdgeList, u, v);
		std::vector<std::vector<int>> AdjacencyMatrix = GenerateAdjacencyMatrix(EdgeList, n);

		std::vector<std::vector<int>> FloydsMatrix = GenerateFloydWarshallMatrix(AdjacencyMatrix);
		Adv::MinEdgePath t(n, m, EdgeList, u, v);
		int ExpectedResult = FloydsMatrix[u][v] > EdgeList.size() ? -1 : FloydsMatrix[u][v];
		int actualResult = t.getMinEdge(v);

		EXPECT_EQ(ExpectedResult, actualResult);


		//if (ExpectedResult != actualResult) {
		//	std::cout << std::endl << "Failing test case caught";
		//	FloydsMatrix = GenerateFloydWarshallMatrix(AdjacencyMatrix);
		//}
	}

}


// --------------------- UNIT TESTS --------------------- //


TEST(MinEdgePathTests, CASE_1) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 4 1 2 3 3 1 2 4");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(2, t.getMinEdge(v));
}

TEST(MinEdgePathTests, CASE_2) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 4 5 2 1 3 3 4 1 4 3 5");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(-1, t.getMinEdge(v));
}

TEST(MinEdgePathTests, CASE_3) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 2 1 4");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(-1, t.getMinEdge(v));
}

TEST(MinEdgePathTests, CASE_4) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 8 4 1 4 1 1 1 3 5 1 4 5 2 4 2 4 2 4 3");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(3, t.getMinEdge(v));
}

TEST(MinEdgePathTests, CASE_5) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("6 4 1 2 2 3 3 4 4 5 6 3");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(-1, t.getMinEdge(v));
}

TEST(MinEdgePathTests, CASE_6) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("6 4 1 2 2 3 3 4 4 5 6 3");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::MinEdgePath t(n, m, EdgeList, u, v);

	EXPECT_EQ(-1, t.getMinEdge(v));
}

