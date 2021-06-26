#pragma once
#include "pch.h"
#include"..\graph-algorithms\ExploreConnectedGraphs.h"
#include<vector>
#include"InputFromStream.h"
#include<sstream>

TEST(ExploreConnectedGraphsTests, ConnectedGraphs_be_one_for_densely_linked_vertices) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 3 2 4 3 1 4");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::ExploreConnectedGraphs t(n, m, EdgeList);

	EXPECT_EQ(1, t.numConnectedGraphgs);
}

TEST(ExploreConnectedGraphsTests, ConnectedGraphs_be_two_for_sparsely_unlinked_vertices) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::ExploreConnectedGraphs t(n, m, EdgeList);

	EXPECT_EQ(2, t.numConnectedGraphgs);
}

TEST(ExploreConnectedGraphsTests, ConnectedGraphs_be_four_for_totaly_sparsed_unlinked_vertices) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 0");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::ExploreConnectedGraphs t(n, m, EdgeList);

	EXPECT_EQ(4, t.numConnectedGraphgs);
}