#pragma once
#include "pch.h"
#include "..\graph-algorithms\DirectedAcyclicGraphs.h"
#include<vector>
#include"InputFromStream.h"
#include<sstream>


TEST(DirectedAcyclicGraphsTests, Case_1) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 3 2 4 3 1 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_FALSE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_2) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 4 1 2 3 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_TRUE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_3) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_FALSE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_4) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 0");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_FALSE(t.containsCycles);
}


TEST(DirectedAcyclicGraphsTests, Case_5) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 7 1 2 2 3 1 3 3 4 1 4 2 5 3 5");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_FALSE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_6) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 2 3 3 4 4 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_TRUE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_7) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("3 3 1 2 2 3 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_TRUE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_8) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("100 100 27 96 23 51 42 10 40 22 30 41 80 40 13 70 21 94 88 35 38 86 53 83 71 84 64 26 4 46 76 43 24 76 26 83 18 75 42 98 36 39 47 63 33 96 89 54 47 80 95 8 34 41 91 45 78 1 12 74 2 37 98 81 30 32 93 30 45 71 38 44 85 18 89 10 71 35 73 52 28 42 98 20 22 69 56 79 78 63 53 58 77 13 6 11 56 36 4 11 92 63 32 78 71 24 16 79 66 89 72 6 20 15 2 91 100 75 93 7 42 100 18 88 49 75 33 78 81 1 42 95 73 64 50 66 33 68 14 38 80 89 8 16 87 18 20 80 81 38 14 35 91 20 36 5 16 8 61 11 72 91 26 57 60 83 80 11 58 1 71 36 41 30 57 46 47 82 46 74 28 9 76 70 69 58 39 73 89 55 93 54 17 92 54 44 21 69 87 58 96 34");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_TRUE(t.containsCycles);
}

TEST(DirectedAcyclicGraphsTests, Case_9) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("8 9 1 2 2 3 3 4 3 6 6 5 5 4 6 7 7 8 8 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DirectedAcyclicGraph t(n, m, EdgeList);

	EXPECT_TRUE(t.containsCycles);
}




