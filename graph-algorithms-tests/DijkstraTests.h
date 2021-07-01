#pragma once
#include<vector>
#include<sstream>

#include "pch.h"
#include "..\graph-algorithms\Dijkstra.h"
#include"InputFromStream.h"
#include "GenerateGraphs.h"

// ---------- Problem Description -----------------
//  Task.Given an directed graph with positive edge weights and with 𝑛 vertices and 𝑚 edges as well as two
//  vertices 𝑢 and 𝑣, compute the weight of a shortest path between 𝑢 and 𝑣(that is, the minimum total
//	weight of a path from 𝑢 to 𝑣).
//	Input Format.A graph is given in the standard format.The next line contains two vertices 𝑢 and 𝑣.
//	Constraints. 1 ≤ 𝑛 ≤ 1e4
//	, 0 ≤ 𝑚 ≤ 1e5
//	, 𝑢 ̸ = 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛, edge weights are non - negative integers not exceeding 1e8.
//	.
//	Output Format.Output the minimum weight of a path from 𝑢 to 𝑣, or −1 if there is no path.

// --------------------- UNIT TESTS --------------------- //


TEST(DijkstraTests, CASE_1) {
	int n, m, u, v;
	std::vector<std::vector<int>> EdgeList;
	std::istringstream inputStrm("4 4 1 2 1 4 1 2 2 3 2 1 3 5 1 3");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::Dijkstra t(n, m, EdgeList, true, u, v);

	EXPECT_EQ( 3, t.GetDijkstraDistance());
}

TEST(DijkstraTests, CASE_2) {
	int n, m, u, v;
	std::vector<std::vector<int>> EdgeList;
	std::istringstream inputStrm("5 9 1 2 4 1 3 2 2 3 2 3 2 1 2 4 2 3 5 4 5 4 1 2 5 3 3 4 4 1 5");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::Dijkstra t(n, m, EdgeList, true, u, v);

	EXPECT_EQ( 6, t.GetDijkstraDistance());
}

TEST(DijkstraTests, CASE_3) {
	int n, m, u, v;
	std::vector<std::vector<int>> EdgeList;
	std::istringstream inputStrm("3 3 1 2 7 1 3 5 2 3 2 3 2");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::Dijkstra t(n, m, EdgeList, true, u, v);

	EXPECT_EQ( -1, t.GetDijkstraDistance());
}

TEST(DijkstraTests, CASE_4) {
	int n, m, u, v;
	std::vector<std::vector<int>> EdgeList;
	std::istringstream inputStrm("10 9 1 2 1 5 6 1 6 7 1 8 9 1 9 10 1 3 4 1 7 8 1 4 5 1 2 3 1 1 10");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::Dijkstra t(n, m, EdgeList, true, u, v);

	EXPECT_EQ( 9, t.GetDijkstraDistance());
}

TEST(DijkstraTests, CASE_5) {
	int n, m, u, v;
	std::vector<std::vector<int>> EdgeList;
	std::istringstream inputStrm("5 10 3 5 49438153 2 3 78072041 3 4 12409612 1 3 88526216 5 2 6876525 1 4 28703032 4 1 24629785 4 5 96300300 4 3 317823 2 5 22632987 4 2");
	inputToVars(inputStrm, n, m, EdgeList, u, v);

	Adv::Dijkstra t(n, m, EdgeList, true, u, v);

	EXPECT_EQ(56632501, t.GetDijkstraDistance());
}

