#pragma once
#include "pch.h"
#include "..\graph-algorithms\DAGTopologyGraph.h"
#include<vector>
#include"InputFromStream.h"
#include<sstream>
#include<list>
#include"AssertArray.h"


TEST(DAGTopologyGraphTests, Case_1) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 3 1 2 4 1 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGTopologyGraph t(n, m, EdgeList);

	std::istringstream expectedResultStrm("4 3 1 2");
	EXPECT_TRUE(ASSERT_ARRAY(expectedResultStrm, t.getTopologyOrder(), n)); 
}

TEST(DAGTopologyGraphTests, Case_2) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("4 1 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGTopologyGraph t(n, m, EdgeList);

	std::istringstream expectedResultStrm("4 3 2 1");
	EXPECT_TRUE(ASSERT_ARRAY(expectedResultStrm, t.getTopologyOrder(), n));
}

TEST(DAGTopologyGraphTests, Case_3) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("5 7 2 1 3 2 3 1 4 3 4 1 5 2 5 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGTopologyGraph t(n, m, EdgeList);

	std::istringstream expectedResultStrm("5 4 3 2 1");
	EXPECT_TRUE(ASSERT_ARRAY(expectedResultStrm, t.getTopologyOrder(), n));
}

TEST(DAGTopologyGraphTests, Case_4) {
	int n, m;
	std::vector<std::pair<int, int>> EdgeList;
	std::istringstream inputStrm("100 100 50 96 54 55 12 78 88 61 67 64 40 22 17 95 39 4 73 10 68 20 45 22 51 39 86 80 11 67 24 89 19 76 96 5 62 80 7 81 17 36 42 98 86 57 100 6 5 24 25 91 12 22 77 32 14 49 58 9 50 17 21 62 44 36 5 64 29 14 100 97 56 95 30 32 77 35 27 88 82 10 37 68 42 6 51 88 34 32 8 91 59 14 14 68 19 90 73 55 94 89 21 58 54 24 94 61 25 90 13 75 21 14 75 9 92 90 30 89 45 4 83 78 32 69 75 91 59 95 47 45 13 2 25 18 87 8 7 36 55 99 3 9 71 11 81 73 13 56 50 37 6 96 29 45 100 93 21 57 81 71 12 93 94 68 55 39 44 96 92 91 16 15 73 12 53 8 53 74 71 95 33 52 42 66 83 62 86 89 11 95 67 20 53 30 1 69 37 32 81 14");
	inputToVars(inputStrm, n, m, EdgeList);

	Basic::DAGTopologyGraph t(n, m, EdgeList);

	std::istringstream expectedResultStrm("100 97 94 92 87 86 85 84 83 82 79 77 72 70 65 63 60 59 54 53 74 51 50 48 47 46 44 43 42 66 98 41 40 38 37 35 34 33 52 31 30 32 29 45 28 27 88 61 26 25 23 21 57 58 62 80 19 90 76 18 17 16 15 13 56 75 8 91 7 36 81 14 68 49 71 11 95 67 20 73 12 93 22 78 55 39 99 10 6 96 5 64 24 89 4 3 9 2 1 69");
	EXPECT_TRUE(ASSERT_ARRAY(expectedResultStrm, t.getTopologyOrder(), n));
}



