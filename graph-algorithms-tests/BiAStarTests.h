#pragma once
#include "pch.h"
#include "../graph-algorithms/BiAStar.h"
#include "InputFromStream.h"
#include "BidijkstraTests.h"
#include "GenerateGraphs.h"

// DISCLAIMER : CODE CONTAINS SOME CORNER CASE BUG

// Problem Description
// Task.Compute the distance between several pairs of nodes in the network.
// Input Format.The first line contains two integers 𝑛 and 𝑚 — the number of nodes and edges in the
// network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following 𝑛 lines contains the
// coordinates 𝑥 and 𝑦 of the corresponding node.Each of the following 𝑚 lines contains three integers
// 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node number 𝑢 to the node number 𝑣.
// It is guaranteed that 𝑙 ≥
// √︀(𝑥(𝑢) − 𝑥(𝑣))2 + (𝑦(𝑢) − 𝑦(𝑣))2 where(𝑥(𝑢), 𝑦(𝑢)) are the coordinates of 𝑢
// and (𝑥(𝑣), 𝑦(𝑣)) are the coordinates of 𝑣.The next line contains an integer 𝑞 — the number of queries
// for computing the distance.Each of the following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers
// of the two nodes to compute the distance from 𝑢 to 𝑣.
// Constraints. 1 ≤ 𝑛 ≤ 110 000; 1 ≤ 𝑚 ≤ 250 000; −1e9 ≤ 𝑥, 𝑦 ≤ 1e9
// ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 0 ≤ 𝑙 ≤ 100 000;
// 1 ≤ 𝑞 ≤ 10 000. For Python2, Python3, Ruby and Javascript, 1 ≤ 𝑛 ≤ 11 000, 1 ≤ 𝑚 ≤ 30 000.
// Output Format.For each query, output one integer.If there is no path from 𝑢 to 𝑣, output −1.Otherwise,
// output the distance from 𝑢 to 𝑣.

// --------------------- UNIT TESTS --------------------- //


// Stress Test with Bidirectional Dijkstra
TEST(DISABLED_BiAStarTests, Stress_Test) {
	//const std::pair<int, int> numVertex_MinMax = { 1, 1.1e5 };
	//const std::pair<int, int> numEdges_MinMax = { 1 , 2.5e5 };
	//const std::pair<int, int> wt_MinMax = { 0 , 1e5 };
	//const std::pair<int, int> coordinates_MinMax= { -1e9 , 1e9};
	const std::pair<int, int> numVertex_MinMax = { 1, 6 };
	const std::pair<int, int> numEdges_MinMax = { 1 , 6 };
	const std::pair<int, int> wt_MinMax = { 0 , 6 };
	const std::pair<int, int> coordinates_MinMax = { -5 , 5 };

	for (llong test = 0; test < 1e4; test++) {
		int n, m, u, v;
		DoubleAdj AdjListWithCost;
		vector<pair<llong, llong>> xy;
		std::vector<std::vector<int>> EdgeListWithWt;

		GenerateGraphs(numVertex_MinMax, numEdges_MinMax, wt_MinMax, n, m, EdgeListWithWt, u, v);
		AdjListWithCost = GenerateBiDirectionAdjList(n, EdgeListWithWt);
		xy = GenerateCoordinates(n, coordinates_MinMax);

		Adv::Bidijkstra Bd(n, AdjListWithCost);
		llong BiDijkstraResult = Bd.query(u,v);

		Adv::BiAStar As(n, AdjListWithCost, xy);
		llong BiAStarResult = As.query(u,v);

		EXPECT_EQ(BiDijkstraResult, BiAStarResult);


		//if (BiDijkstraResult != BiAStarResult) {
		//	std::cout << std::endl << "Failing test case caught";
		//	As.query(u, v);
		//}
	}

}

TEST(BiAStarTests, CASE_1) {
	int n;
	DoubleAdj AdjListWithCost(2);
	vector<pair<llong, llong>> xy;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("2 1 0 0 0 1 1 2 1 4 1 1 2 2 1 2 2 1");
	inputToVars(inputStrm, n, xy, AdjListWithCost, Queries);

	Adv::BiAStar As(n, AdjListWithCost, xy);
	string ActualResult = As.query(Queries);

	EXPECT_EQ("0 0 1 -1", ActualResult);
}

TEST(BiAStarTests, CASE_2) {
	int n;
	DoubleAdj AdjListWithCost(2);
	vector<pair<llong, llong>> xy;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("4 4 0 0 0 1 2 1 2 0 1 2 1 4 1 2 2 3 2 1 3 6 1 1 3");
	inputToVars(inputStrm, n, xy, AdjListWithCost, Queries);

	Adv::BiAStar As(n, AdjListWithCost, xy);
	string ActualResult = As.query(Queries);

	EXPECT_EQ("3", ActualResult);
}

TEST(BiAStarTests, CASE_3) {
	int n;
	DoubleAdj AdjListWithCost(2);
	vector<pair<llong, llong>> xy;
	std::vector<std::pair<int, int>> Queries;
	std::istringstream inputStrm("18 36 -74258291 40695601 -74259991 40694901 -74257543 40695865 -74260991 40694301 -74256591 40696201 -74261991 40694501 -74261391 40694201 -74259891 40694101 -74254991 40696501 -74262191 40694601 -74263591 40693401 -74259091 40695901 -74262491 40693501 -74258091 40693501 -74254887 40696033 -74254891 40697301 -74253490 40697001 -74262591 40694701 1 2 1839 1 3 794 2 4 1167 2 1 1839 3 1 794 3 5 1010 4 6 1020 4 2 1167 4 7 413 4 8 1119 5 9 1628 5 3 1010 6 10 224 6 11 1942 6 4 1020 6 12 3221 7 4 413 7 13 1304 8 4 1119 8 14 1898 9 15 480 9 16 807 9 5 1628 9 17 1583 10 18 413 10 6 224 10 12 3362 11 6 1942 12 10 3362 12 6 3221 13 7 1304 14 8 1898 15 9 480 16 9 807 17 9 1583 18 10 413 10 2 17 10 8 6 8 11 13 16 2 15 14 15 8 6 5 7 1 17 11");
	inputToVars(inputStrm, n, xy, AdjListWithCost, Queries);

	Adv::BiAStar As(n, AdjListWithCost, xy);
	string ActualResult = As.query(Queries);

	EXPECT_EQ("6854 2363 2139 4679 6078 9935 8037 5830 3419 10983", ActualResult);
}