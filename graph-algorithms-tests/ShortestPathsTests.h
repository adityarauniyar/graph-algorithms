#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\ShortestPaths.h"
#include"InputFromStream.h"
#include "GenerateGraphs.h"

// ---------- Problem Description -----------------
// Task.Given an directed graph with possibly negative edge weights and with 𝑛 vertices and 𝑚 edges as well
// as its vertex 𝑠, compute the length of shortest paths from 𝑠 to all other vertices of the graph.
// Input Format.A graph is given in the standard format.
// Constraints. 1 ≤ 𝑛 ≤ 1e3
// , e ≤ 𝑚 ≤ 1e4
// , 1 ≤ 𝑠 ≤ 𝑛, edge weights are integers of absolute value at most
// 1e9
// .
// Output Format.For all vertices 𝑖 from 1 to 𝑛 output the following on a separate line :
// ∙ “*”, if there is no path from 𝑠 to 𝑢;
// ∙ “ - ”, if there is a path from 𝑠 to 𝑢, but there is no shortest path from 𝑠 to 𝑢(that is, the distance
// 	from 𝑠 to 𝑢 is −∞);
// ∙ the length of a shortest path otherwise.

// --------------------- UNIT TESTS --------------------- //

TEST(ShortestPathsTests, CASE_1) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 7 1 2 10 2 3 5 1 3 100 3 5 7 5 4 10 4 3 -18 6 1 -1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 10 - - - *", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_2) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 4 1 2 1 4 1 2 2 3 2 3 1 -5 4");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("- - - 0 *", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_3) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 6 1 2 1 2 3 1 3 4 1 4 5 1 5 3 -2 5 2 -4 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_4) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 6 1 2 1 2 3 1 3 4 1 4 5 1 5 3 -3 5 2 -3 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_5) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 7 1 2 1 2 3 1 3 4 1 4 5 1 5 6 1 6 2 -6 5 3 -2 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 - - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_6) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 0 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 * * * * *", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_7) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 6 1 2 1 2 3 1 3 4 1 4 5 1 5 3 1 5 6 1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 1 2 3 4 5", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_8) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 8 2 3 -1 3 2 -1 1 4 1 1 5 1 1 6 1 2 4 1 2 5 1 2 6 1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 * * 1 1 1", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_9) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("3 2 1 2 -1 2 3 1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 -1 0", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_10) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 7 1 2 10 2 3 5 1 3 100 3 5 7 5 4 10 4 3 -18 6 1 -1 3");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("* * - - - *", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_11) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("9 10 4 5 1 4 1 2 1 2 1 2 3 2 3 1 -5 4 6 2 6 7 1 7 8 2 8 6 -5 8 9 1 4");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("- - - 0 1 - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_12) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("4 5 1 2 1 2 3 1 3 1 -3 3 4 1 4 3 1 4");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("- - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_13) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("10 11 6 1 -1 1 2 10 1 3 100 2 3 5 3 5 7 3 7 2 5 4 10 5 8 3 8 10 2 4 3 -18 4 9 5 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 10 - - - * - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_14) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("10 11 6 1 -1 1 2 10 1 3 100 2 3 5 3 5 7 3 7 2 5 4 10 5 8 3 8 10 2 4 3 -18 4 9 5 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 10 - - - * - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_15) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 8 2 3 -1 3 2 -1 1 4 1 1 5 1 1 6 1 2 4 1 2 5 1 2 6 1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 * * 1 1 1", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_16) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 4 1 2 1 4 1 2 2 3 2 3 1 -5 5");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("* * * * 0", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_17) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("3 2 2 3 -1 3 2 -1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("0 * *", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_18) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 7 1 2 10 2 3 5 1 3 100 3 5 7 5 4 10 4 3 -18 5 1 -1 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("- - - - -", t.getShortestPathList());
}

TEST(ShortestPathsTests, CASE_19) {
	int n, m, Start;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 7 1 2 10 2 3 5 1 3 100 3 5 7 4 3 -18 5 1 -1 5 4 10 1");
	inputToVars(inputStrm, n, m, EdgeList, Start);

	Adv::ShortestPaths t(n, m, EdgeList, true, Start);

	EXPECT_EQ("- - - - -", t.getShortestPathList());
}