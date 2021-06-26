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


// --------------------- UNIT TESTS --------------------- //


TEST(BipartiteTests, CASE_1) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 4 1 2 3 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_FALSE(t.isBipartite);
}

TEST(BipartiteTests, CASE_2) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 4 5 2 4 2 3 4 1 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_3) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("8 7 5 2 4 2 3 4 1 4 6 7 7 8 8 6");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_4) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("6 4 1 2 2 3 3 4 5 6");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_5) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}
TEST(BipartiteTests, CASE_6) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 1 1 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_TRUE(t.isBipartite);
}

TEST(BipartiteTests, CASE_7) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("11 13 1 2 1 3 1 4 2 5 3 6 7 7 5 6 5 8 5 9 6 9 6 10 7 10 7 11");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::Bipartite t(n, m, EdgeList);

	EXPECT_FALSE(t.isBipartite);
}