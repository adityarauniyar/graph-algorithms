#pragma once

#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\Clustering.h"
#include"InputFromStream.h"

// PROBLEM STATEMENT
// Task.Given 𝑛 points on a plane and an integer 𝑘, compute the largest possible value of 𝑑 such that the
// given points can be partitioned into 𝑘 non - empty subsets in such a way that the distance between any
// two points from different subsets is at least 𝑑.
// Input Format.The first line contains the number 𝑛 of points.Each of the following 𝑛 lines defines a point
// (𝑥𝑖
// 	, 𝑦𝑖).The last line contains the number 𝑘 of clusters.
// 	Constraints. 2 ≤ 𝑘 ≤ 𝑛 ≤ 200; −1e3 ≤ 𝑥𝑖
// 	, 𝑦𝑖 ≤ 1e3 are integers.All points are pairwise different.
// 	Output Format.Output the largest value of 𝑑.The absolute value of the difference between the answer of
// 	your program and the optimal value should be at most 1e−6
// 	.To ensure this, output your answer with
// 	at least seven digits after the decimal point(otherwise your answer, while being computed correctly,
// 		can turn out to be wrong because of rounding issues).
// --------------------- UNIT TESTS --------------------- //


TEST(ClusteringTests, CASE_1) {
	int n, d;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("12 7 6 4 3 5 1 1 7 2 7 5 7 3 3 7 8 2 8 4 4 6 7 2 6 3");
	inputToVars(inputStrm, n, CoordinateList, d);

	Adv::Clustering t(n, CoordinateList, d);

	double ActualResult = t.getMinClusterDistance();
	double ExpectedResult = 2.828427124746;

	EXPECT_TRUE(abs(ActualResult - ExpectedResult) <= 1e-6);
}

TEST(ClusteringTests, CASE_2) {
	int n, d;
	std::vector<std::pair<int, int>> CoordinateList;
	std::istringstream inputStrm("8 3 1 1 2 4 6 9 8 9 9 8 9 3 11 4 12 4");
	inputToVars(inputStrm, n, CoordinateList, d);

	Adv::Clustering t(n, CoordinateList, d);

	double ActualResult = t.getMinClusterDistance();
	double ExpectedResult = 5;

	EXPECT_TRUE(abs(ActualResult - ExpectedResult) <= 1e-6);
}