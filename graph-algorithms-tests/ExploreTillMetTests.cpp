#include "pch.h"
#include "..\graph-algorithms\ExploreTillMet.h"
#include"..\graph-algorithms\ExploreConnectedGraphs.h"
#include<vector>


TEST(ExploreTillMetTests, isReachable_should_be_true_for_densely_linked_vertices) {
	int n = 4,
		m = 4;
	std::vector<std::pair<int, int>> EdgeList = { {1,2}, {3,2}, {4,3}, {1,4} };
	int u = 1,
		v = 4;

	Basic::ExploreTillMet t(n, m, EdgeList, u, v);

	EXPECT_TRUE(t.isReachable);
}

TEST(ExploreTillMetTests, isReachable_should_be_false_for_sparsely_unlinked_vertices) {
	int n = 4,
		m = 2;
	std::vector<std::pair<int, int>> EdgeList = { {1,2}, {3,2} };
	int u = 1,
		v = 4;

	Basic::ExploreTillMet t(n, m, EdgeList, u, v);

	EXPECT_FALSE(t.isReachable);
}

//#include "pch.h"
//#include"..\graph-algorithms\ExploreConnectedGraphs.h"
//#include<vector>


TEST(ExploreConnectedGraphsTests, ConnectedGraphs_be_one_for_densely_linked_vertices) {
	int n = 4,
		m = 4;
	std::vector<std::pair<int, int>> EdgeList = { {1,2}, {3,2}, {4,3}, {1,4} };

	Basic::ExploreConnectedGraphs t(n, m, EdgeList);

	EXPECT_EQ(1, t.numConnectedGraphgs);
}

TEST(ExploreConnectedGraphsTests, ConnectedGraphs_be_two_for_sparsely_unlinked_vertices) {
	int n = 4,
		m = 2;
	std::vector<std::pair<int, int>> EdgeList = { {1,2}, {3,2} };
	int u = 1,
		v = 4;

	Basic::ExploreConnectedGraphs t(n, m, EdgeList);

	EXPECT_EQ(2, t.numConnectedGraphgs);
}
