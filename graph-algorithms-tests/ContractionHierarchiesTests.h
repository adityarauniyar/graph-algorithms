#pragma once
#include "pch.h"
#include <chrono>
#include "../graph-algorithms/ContractionHierarchies.h"
#include "InputFromStream.h"
#include "..\graph-algorithms\Dijkstra.h"
#include "GenerateGraphs.h"

// Problem Description

// Task. Compute the distance between several pairs of nodes in the network.

// Input Format.You will be given the input for this problem in two parts.The first part contains the
// description of a road network, the second part contains the queries.You have a separate time limit for
// preprocessing the graph.Under this time limit, you need to read the graph and preprocess it.After
// you’ve preprocessed the graph, you need to output the string “Ready”(without quotes) and flush the
// output buffer(the starter files for C++, Java and Python3 do that for you; if you use another language,
// you will have to find out how to do this).Only after you output the string “Ready” you will be given
// the queries.You will have a time limit for the querying part, and under this time limit you will need
// to input all the queries and output the results for each of the quires.
// The first line of the road network description contains two integers 𝑛 and 𝑚 — the number of nodes
// and edges in the network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following
// 𝑚 lines contains three integers 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node
// number 𝑢 to the node number 𝑣.
// The first line of the queries description contains an integer 𝑞 — the number of queries for computing
// the distance.Each of the following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers of the two
// nodes to compute the distance from 𝑢 to 𝑣.

// Constraints. 1 ≤ 𝑛 ≤ 110 000; 1 ≤ 𝑚 ≤ 250 000; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 1 ≤ 𝑙 ≤ 200 000; 1 ≤ 𝑞 ≤ 10 000. It is
// guaranteed that the correct distances are less than 1 000 000 000. For Python2, Python3, Ruby
// and Javascript, 1 ≤ 𝑛 ≤ 11 000, 1 ≤ 𝑚 ≤ 25 000, 1 ≤ 𝑞 ≤ 1 000.

// Output Format.After you’ve read the description of the road network and done your preprocessing,
// output one string “Ready”(without quotes) on a separate line and flush the output buffer.Then read
// the queries, and for each query, output one integer on a separate line.If there is no path from 𝑢 to 𝑣,
// output −1.Otherwise, output the distance from 𝑢 to 𝑣.


// Stress Test with Dijkstra
TEST(DISABLED_ContractionHierarchiesTests, Stress_Test) {

	const std::pair<int, int> numVertex_MinMax = { 1, 1.1e5 };
	const std::pair<int, int> numEdges_MinMax = { 1 , 2.5e5 };
	const std::pair<int, int> wt_MinMax = { 0 , 2e5 };
	//const std::pair<int, int> numVertex_MinMax = { 1, 10 };
	//const std::pair<int, int> numEdges_MinMax = { 1 , 10};
	//const std::pair<int, int> wt_MinMax = { 0 , 10 };

	for (llong test = 0; test < 1e4; test++) {
		int n, m, u, v;
		Adj AdjListWithCost;
		DoubleAdjMapList mapAdj;
		std::vector<std::vector<int>> EdgeListWithWt;

		GenerateGraphs(numVertex_MinMax, numEdges_MinMax, wt_MinMax, n, m, EdgeListWithWt, u, v);
		AdjListWithCost = GenerateAdjList(n, EdgeListWithWt);
		convertAdjToDoubleMapAdj(AdjListWithCost, mapAdj);

		Adv::Dijkstra Dj(n, m, EdgeListWithWt, true, u, v);
		llong DijkstraResult = Dj.GetDijkstraDistance();

		Adv::ContractionHierarchies CH(n, mapAdj);
		auto start = chrono::high_resolution_clock::now();
		llong ContractionHierarchiesResult = CH.query(u, v);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

		// EXPECT_EQ(DijkstraResult, ContractionHierarchiesResult);

		if (DijkstraResult != ContractionHierarchiesResult) {
			std::cout << std::endl << "Failing test case caught";
			convertAdjToDoubleMapAdj(AdjListWithCost, mapAdj);
			Adv::ContractionHierarchies CH(n, mapAdj);
			CH.query(u, v);
		}
	}

}

// --------------------- UNIT TESTS --------------------- //
TEST(ContractionHierarchiesTests, CASE_1) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("2 1 1 2 1 4 1 1 2 2 1 2 2 1");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("0 0 1 -1", ActualResult);
}

TEST(ContractionHierarchiesTests, CASE_2) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("4 4 1 2 1 4 1 2 2 3 2 1 3 5 1 1 3");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("3", ActualResult);
}

TEST(ContractionHierarchiesTests, CASE_3) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("5 20 1 2 667 1 3 677 1 4 700 1 5 622 2 1 118 2 3 325 2 4 784 2 5 11 3 1 585 3 2 956 3 4 551 3 5 559 4 1 503 4 2 722 4 3 331 4 5 366 5 1 880 5 2 883 5 3 461 5 4 228 10 1 1 1 2 1 3 1 4 1 5 2 1 2 2 2 3 2 4 2 5");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("0 667 677 700 622 118 0 325 239 11", ActualResult);
}

TEST(ContractionHierarchiesTests, CASE_4) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("6 5 2 6 2 6 1 3 1 4 2 4 3 1 3 5 2 1 2 3");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("8", ActualResult);
}

// Testing the loop exit when loop stage > hopsLimit
TEST(ContractionHierarchiesTests, CASE_5) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("6 6 2 1 2 1 3 2 2 4 1 4 5 1 5 6 1 6 3 1 1 2 3");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("4", ActualResult);
}

// Testing the loop exit when loop dist > len(1,2) + len(1,3) - minEdgefrom "3"
TEST(ContractionHierarchiesTests, CASE_6) {
	int n;
	DoubleAdjMapList adj;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("6 6 2 1 2 1 3 2 2 4 2 4 5 2 5 6 2 6 3 2 1 2 3");
	inputToVars(inputStrm, n, adj, Queries);

	Adv::ContractionHierarchies CH(n, adj);
	string ActualResult = CH.query(Queries);

	EXPECT_EQ("4", ActualResult);
}
