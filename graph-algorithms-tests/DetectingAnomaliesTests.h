#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\DetectingAnomalies.h"
#include"InputFromStream.h"
#include "GenerateGraphs.h"

// ---------- Problem Description -----------------
// Task.Given an directed graph with possibly negative edge weights and with 𝑛 vertices and 𝑚 edges, check
// whether it contains a cycle of negative weight.
// Input Format.A graph is given in the standard format.
// Constraints. 1 ≤ 𝑛 ≤ 1e3
// , 0 ≤ 𝑚 ≤ 1e4
// , edge weights are integers of absolute value at most 1e3
// .
// Output Format.Output 1 if the graph contains a cycle of negative weight and 0 otherwise.

// --------------------- UNIT TESTS --------------------- //


TEST(DetectingAnomaliesTests, CASE_1) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 -5 4 1 2 2 3 2 3 1 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_2) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 9 1 2 4 1 3 2 2 3 2 3 2 1 2 4 2 3 5 4 5 4 1 2 5 3 3 4 4 1 5");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_3) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 5 1 5 1 5 4 2 4 3 -4 3 5 1 2 3 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_4) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 5 1 5 10 5 4 2 4 3 -4 3 5 1 2 3 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_5) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 5 1 5 1 5 4 2 4 3 -2 3 5 1 2 3 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_6) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 6 1 4 2 4 3 -1 3 5 2 5 2 -4 1 2 1 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_7) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 6 1 4 2 4 3 -1 3 5 2 5 2 -5 1 2 1 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_8) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 4 1 4 2 2 3 2 3 5 2 5 2 -5");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_9) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 7 1 2 4 1 3 3 2 3 -2 3 4 -3 4 2 4 4 5 2 3 5 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_10) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("2 2 1 2 1 2 1 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_11) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("2 2 1 2 -1 2 1 3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_12) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("2 2 1 2 -1 2 1 -1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_13) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 11 1 6 -10 1 2 3 2 6 8 2 3 3 2 5 -5 3 5 1 3 6 3 3 4 2 5 4 0 6 5 5 6 2 2");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_14) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 11 1 2 -10 1 3 3 2 3 2 3 2 8 2 4 5 3 4 -5 3 5 3 5 4 1 5 2 3 5 6 2 4 6 0");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_15) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 9 1 3 1 1 5 1 5 3 1 4 1 1 3 4 1 4 6 1 3 2 -5 2 6 1 6 3 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_16) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("7 7 1 2 -1 2 3 -1 3 4 -1 4 1 1 5 6 1 6 7 1 7 5 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_17) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("6 7 1 2 2 2 3 3 3 1 1 4 2 3 5 4 1 4 6 -2 6 5 -5");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_18) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("4 3 1 2 -1 2 3 -2 3 4 -3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_19) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("5 5 1 2 1 3 1 1 3 4 -1 4 5 -1 5 3 -1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_20) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("4 3 1 2 -1 2 3 -2 3 4 -3");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(0, t.checkForAnomoly());
}

TEST(DetectingAnomaliesTests, CASE_21) {
	int n, m;
	std::vector<std::vector<llong>> EdgeList;
	std::istringstream inputStrm("4 3 2 3 -5 3 4 2 4 2 1");
	inputToVars(inputStrm, n, m, EdgeList);

	Adv::DetectingAnomalies t(n, m, EdgeList, true);

	EXPECT_EQ(1, t.checkForAnomoly());
}