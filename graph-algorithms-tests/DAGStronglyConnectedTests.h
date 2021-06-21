#pragma once
#include "pch.h"
#include"..\graph-algorithms\DAGStronglyConnected.h"
#include<vector>
#include"InputFromStream.h"
#include<sstream>

TEST(DAGStronglyConnectedTests, CASE_1) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 3 2 4 3 1 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(4, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_2) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(4, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_3) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 0");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(4, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_4) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 4 1 2 3 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(2, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_5) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 7 2 1 3 2 3 1 4 3 4 1 5 2 5 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(5, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_6) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 10 5 4 4 5 3 1 1 4 2 3 4 2 3 4 5 2 4 1 3 5");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(1, t.getNumStronglyConnected());
}

TEST(DAGStronglyConnectedTests, CASE_7) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("10000 1 1595 7210");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(10000, t.getNumStronglyConnected());
}
TEST(DAGStronglyConnectedTests, CASE_8) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 10 5 4 4 5 3 1 1 4 2 3 4 2 3 4 5 2 4 1 3 5");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(1, t.getNumStronglyConnected());
}
TEST(DAGStronglyConnectedTests, CASE_9) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("10 20 5 3 4 10 3 2 1 3 4 9 2 6 8 3 8 2 6 1 6 10 10 6 1 4 3 8 1 5 8 9 5 1 8 5 7 8 3 4 8 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGStronglyConnected t(n, m, EdgeList);

	EXPECT_EQ(3, t.getNumStronglyConnected());
}



