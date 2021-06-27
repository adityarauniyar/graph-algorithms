#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\ConnectNodesWithMinCost.h"
#include"InputFromStream.h"

// ---------- Problem Description -----------------
// Task.Given 𝑛 points on a plane, connect them with segments of minimum total length such that there is a
// path between any two points.Recall that the length of a segment with endpoints(𝑥1, 𝑦1) and (𝑥2, 𝑦2)
// is equal to √︀((𝑥1 − 𝑥2)^2 + (𝑦1 − 𝑦2)^2)
// Input Format.The first line contains the number 𝑛 of points.Each of the following 𝑛 lines defines a point
// (𝑥𝑖, 𝑦𝑖).
// 	Constraints. 1 ≤ 𝑛 ≤ 200; −1e3 ≤ 𝑥𝑖, 𝑦𝑖 ≤ 1e3 are integers. All points are pairwise different, no three
// 	points lie on the same line.
// 	Output Format.Output the minimum total length of segments.The absolute value of the difference
// 	between the answer of your program and the optimal value should be at most 1e−6
// 	.To ensure this,
// 	output your answer with at least seven digits after the decimal point(otherwise your answer, while
// 		being computed correctly, can turn out to be wrong because of rounding issues).

// --------------------- UNIT TESTS --------------------- //


TEST(ConnectNodesWithMinCostTests, CASE_1) {
	int n;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("4 0 0 0 1 1 0 1 1");
	inputToVars(inputStrm, n, CoordinateList);

	Adv::ConnectNodesWithMinCost t(n, CoordinateList);

	double ActualResult = t.getMinSpanTreeCost();
	double ExpectedResult = 3;

	EXPECT_TRUE(abs(ActualResult - ExpectedResult) <= 1e-6);
}

TEST(ConnectNodesWithMinCostTests, CASE_2) {
	int n;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("5 0 0 0 2 1 1 3 0 3 2");
	inputToVars(inputStrm, n, CoordinateList);

	Adv::ConnectNodesWithMinCost t(n, CoordinateList);

	double ActualResult = t.getMinSpanTreeCost();
	double ExpectedResult = 7.064495102;

	EXPECT_TRUE(abs(ActualResult-ExpectedResult)<=1e-6);
}

TEST(ConnectNodesWithMinCostTests, CASE_3) {
	int n;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("13 1 58 28 80 42 84 89 54 44 28 36 64 54 39 20 14 66 41 36 84 24 84 16 64 9 80");
	inputToVars(inputStrm, n, CoordinateList);

	Adv::ConnectNodesWithMinCost t(n, CoordinateList);

	double ActualResult = t.getMinSpanTreeCost();
	double ExpectedResult = 199.675603309;

	EXPECT_TRUE(abs(ActualResult-ExpectedResult)<=1e-6);
}

TEST(ConnectNodesWithMinCostTests, CASE_4) {
	int n;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("8 3 1 1 2 4 6 9 8 9 9 8 9 3 11 4 12");
	inputToVars(inputStrm, n, CoordinateList);

	Adv::ConnectNodesWithMinCost t(n, CoordinateList);

	double ActualResult = t.getMinSpanTreeCost();
	double ExpectedResult = 20.6502815399;

	EXPECT_TRUE(abs(ActualResult-ExpectedResult)<=1e-6);
}