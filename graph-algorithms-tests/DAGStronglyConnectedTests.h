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