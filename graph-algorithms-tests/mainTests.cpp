#include "pch.h"

#include "ExploreConnectedGraphsTests.h"
#include "ExploreTillMetTests.h"
#include "DirectedAcyclicGraphsTests.h"
#include "DAGTopologyGraphTests.h"
#include "DAGStronglyConnectedTests.h"
#include "MinEdgePathTests.h"

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
