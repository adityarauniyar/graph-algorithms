#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\Bipartite.h"
#include"InputFromStream.h"
#include "GenerateGraphs.h"


// ---------- Problem Description -----------------
// Task.Given an undirected graph with 𝑛 vertices and 𝑚 edges, check whether it is bipartite.
// Input Format.A graph is given in the standard format.
// Constraints. 1 ≤ 𝑛 ≤ 105
// , 0 ≤ 𝑚 ≤ 105
// 
// Output Format.Output 1 if the graph is bipartite and 0 otherwise.
// Memory Limit. 512MB


// Stress testing with Floyd Warshall Algorithm algorithm with Time Complexity O(n^3)

//TEST(BipartiteTests, Stress_Test) {
//
//	const std::pair<int, int> numVertex_MinMax = { 2, 105 };
//	const std::pair<int, int> numEdges_MinMax = { 0 ,105 };
//
//	for (int test = 0; test < 1e3; test++) {
//		int n, m, u, v;
//		std::vector<std::pair<int, int>> EdgeList;
//
//		GenerateGraphs(numVertex_MinMax, numEdges_MinMax, n, m, EdgeList, u, v);
//		std::vector<std::vector<int>> AdjacencyMatrix = GenerateAdjacencyMatrix(EdgeList, n);
//
//		std::vector<std::vector<int>> FloydsMatrix = GenerateFloydWarshallMatrix(AdjacencyMatrix);
//		Basic::Bipartite t(n, m, EdgeList, u, v);
//		int ExpectedResult = FloydsMatrix[u][v] > EdgeList.size ? -1 : FloydsMatrix[u][v];
//		int actualResult = t.isBipartite;
//
//		EXPECT_TRUE(t.isBipartite);
//
//
//		if (ExpectedResult != actualResult) {
//			std::cout << std::endl << "Failing test case caught";
//			FloydsMatrix = GenerateFloydWarshallMatrix(AdjacencyMatrix);
//		}
//	}
//
//}


// --------------------- UNIT TESTS --------------------- //


TEST(BipartiteTests, CASE_1) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 4 1 2 3 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_FALSE(t.isBipartite);
}

TEST(BipartiteTests, CASE_2) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 4 5 2 4 2 3 4 1 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_3) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("8 7 5 2 4 2 3 4 1 4 6 7 7 8 8 6");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_4) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("6 4 1 2 2 3 3 4 5 6");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_5) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}
TEST(BipartiteTests, CASE_6) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 1 1 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}