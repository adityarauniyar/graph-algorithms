#pragma once
#include "pch.h"
#include "..\graph-algorithms\ExploreTillMet.h"
#include<vector>
#include"InputFromStream.h"
#include<sstream>


TEST(ExploreTillMetTests, isReachable_should_be_true_for_densely_linked_vertices) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 3 2 4 3 1 4 1 4");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::ExploreTillMet t(n, m, EdgeList, u, v);

	EXPECT_TRUE(t.isReachable);
}

TEST(ExploreTillMetTests, isReachable_should_be_true_for_large_dense_linked_vertices) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("100 100 27 96 6 9 81 98 21 94 22 68 76 100 8 50 38 86 71 75 32 93 16 50 71 84 6 72 22 58 7 19 19 76 44 75 24 76 31 35 11 89 42 98 63 92 37 38 20 98 45 91 23 53 37 91 76 93 67 90 12 22 43 52 23 56 67 68 1 21 17 83 63 72 30 32 7 91 50 69 38 44 55 89 15 23 11 72 28 42 22 69 56 79 5 83 55 73 13 72 7 93 20 54 21 55 66 89 2 91 18 88 26 64 11 61 28 59 12 86 42 95 17 82 50 66 66 99 40 71 20 40 5 66 92 95 32 46 7 36 44 94 6 31 19 67 26 57 53 84 10 68 28 74 34 94 25 61 71 88 10 89 28 52 72 79 39 73 11 80 44 79 13 77 30 96 30 53 10 39 1 90 40 91 62 71 44 54 15 17 69 74 13 67 24 69 34 96 21 50 20 91 42 46");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::ExploreTillMet t(n, m, EdgeList, u, v);

	EXPECT_TRUE(t.isReachable);
}

TEST(ExploreTillMetTests, isReachable_should_be_false_for_sparsely_unlinked_vertices) {
	int n, m, u, v;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 2 1 2 3 2 1 4");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::ExploreTillMet t(n, m, EdgeList, u, v);

	EXPECT_FALSE(t.isReachable);
}
