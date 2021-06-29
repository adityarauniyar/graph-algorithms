#pragma once
#include "pch.h"
#include "../graph-algorithms/Bidijkstra.h"
#include "InputFromStream.h"

// Problem Description
// Task.Compute the distance between several pairs of nodes in the network. 
// 
// Input Format.The first line contains two integers 𝑛 and 𝑚 — the number of nodes and edges in the
// network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following 𝑚 lines contains
// three integers 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node number 𝑢to the
// node number 𝑣. (Note that some social networks are represented by directed graphs while some other
// correspond naturally to undirected graphs.For example, Twitter is a directed graph(with a directed
// 	edge(𝑢, 𝑣) meaning that 𝑢 follows 𝑣), while Facebook is an undirected graph(where an undirected
// 		edge{ 𝑢, 𝑣 } means that 𝑢 and 𝑣 are friends).In this problem, we work with directed graphs only for a
// simple reason.It is easy to turn an undirected graph into a directed one : just replace each undirected
// edge{ 𝑢, 𝑣 } with a pair of directed edges(𝑢, 𝑣) and (𝑣, 𝑢).)
// The next line contains an integer 𝑞 — the number of queries for computing the distance.Each of the
// following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers of the two nodes to compute the distance
// from 𝑢 to 𝑣.
// Constraints. 1 ≤ 𝑛 ≤ 1 000 000; 1 ≤ 𝑚 ≤ 6 000 000; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 1 ≤ 𝑙 ≤ 1 000; 1 ≤ 𝑞 ≤ 1 000. For
// Python2, Python3, Ruby and Javascript, 1 ≤ 𝑚 ≤ 2 000 000.
// Output Format.For each query, output one integer on a separate line.If there is no path from 𝑢 to 𝑣,
// output −1.Otherwise, output the distance from 𝑢 to 𝑣

// --------------------- UNIT TESTS --------------------- //

TEST(BidijkstraTests, CASE_1) {
	int n;
	Adj AdjListWithCost(2);
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("2 1 1 2 1 4 1 1 2 2 1 2 2 1");
	inputToVars(inputStrm, n, AdjListWithCost, Queries);

	Adv::Bidijkstra Bd(n, AdjListWithCost);
	string ActualResult = Bd.query(Queries);

	EXPECT_EQ("0 0 1 -1", ActualResult);
}

TEST(BidijkstraTests, CASE_2) {
	int n;
	Adj AdjListWithCost(2);
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("4 4 1 2 1 4 1 2 2 3 2 1 3 5 1 1 3");
	inputToVars(inputStrm, n, AdjListWithCost, Queries);

	Adv::Bidijkstra Bd(n, AdjListWithCost);
	string ActualResult = Bd.query(Queries);

	EXPECT_EQ("3", ActualResult);
}

TEST(BidijkstraTests, CASE_3) {
	int n;
	Adj AdjListWithCost(2);
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("5 20 1 2 667 1 3 677 1 4 700 1 5 622 2 1 118 2 3 325 2 4 784 2 5 11 3 1 585 3 2 956 3 4 551 3 5 559 4 1 503 4 2 722 4 3 331 4 5 366 5 1 880 5 2 883 5 3 461 5 4 228 10 1 1 1 2 1 3 1 4 1 5 2 1 2 2 2 3 2 4 2 5");
	inputToVars(inputStrm, n, AdjListWithCost, Queries);

	Adv::Bidijkstra Bd(n, AdjListWithCost);
	string ActualResult = Bd.query(Queries);

	EXPECT_EQ("0 667 677 700 622 118 0 325 239 11", ActualResult);
}