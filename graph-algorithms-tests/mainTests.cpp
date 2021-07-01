#include "pch.h"

#include "ExploreConnectedGraphsTests.h"
#include "ExploreTillMetTests.h"
#include "DirectedAcyclicGraphsTests.h"
#include "DAGTopologyGraphTests.h"
#include "DAGStronglyConnectedTests.h"
#include "MinEdgePathTests.h"
#include "BipartiteTests.h"
#include "DijkstraTests.h"
#include "DetectingAnomaliesTests.h"
#include "ShortestPathsTests.h"
#include "ConnectNodesWithMinCostTests.h"
#include "ClusteringTests.h"
#include "BidijkstraTests.h"
#include "BiAStarTests.h"
#include "AStarTests.h"

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
