#pragma once
#include<map>
#include<vector>

// Input Format. A graph with 𝑛 vertices and 𝑚 edges.The next line contains two vertices 𝑢
//	and 𝑣 of the graph.
// Constraints. 2 ≤ 𝑛 ≤ 103
//  ; 1 ≤ 𝑚 ≤ 103
//  ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 𝑢 ̸ = 𝑣.


typedef long long llong;
typedef std::vector<std::vector<llong>> TDVector;
typedef std::vector<std::pair<int, int>> VectorOfPairs;


class StandardGraphClass
{
	protected:
		int n;
		int m;
		int StartVertex;
		int EndVertex;
		std::map<int, std::vector<int>> AdjacencyList;
		std::map<int, std::vector<std::pair<int, llong>>> AdjacencyListWithWeights;
		const bool isDirected;
	public:
		void static StdGraphInputs(int &n, int &m, VectorOfPairs &EdgeList);
		void static StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts);
		void static StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts, int &Start);
		void static StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts, int &Start, int &End);
		StandardGraphClass(int n, int m) : n(n), m(m), isDirected(false) {}
		StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected);
		StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected, const int &start);
		StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected, const int &start, const int &End);
};

StandardGraphClass::StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected,  const int &Start, const int &End)
	:n(numVertex), m(numEdges), StartVertex(Start), EndVertex(End), isDirected(isDirected) {
	
	for (int i = 0; i < numEdges; i++) {
		AdjacencyListWithWeights[EdgeListWithWts[i][0]].push_back(std::make_pair((int)EdgeListWithWts[i][1], EdgeListWithWts[i][2]));
		if (!isDirected)
			AdjacencyListWithWeights[EdgeListWithWts[i][1]].push_back(std::make_pair((int)EdgeListWithWts[i][0], EdgeListWithWts[i][2]));
	}
}

StandardGraphClass::StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected, const int &Start)
	:n(numVertex), m(numEdges), StartVertex(Start), isDirected(isDirected) {

	for (int i = 0; i < numEdges; i++) {
		AdjacencyListWithWeights[EdgeListWithWts[i][0]].push_back(std::make_pair((int)EdgeListWithWts[i][1], EdgeListWithWts[i][2]));
		if (!isDirected)
			AdjacencyListWithWeights[EdgeListWithWts[i][1]].push_back(std::make_pair((int)EdgeListWithWts[i][0], EdgeListWithWts[i][2]));
	}
}

StandardGraphClass::StandardGraphClass(const int &numVertex, const int &numEdges, const TDVector &EdgeListWithWts, const bool isDirected)
	:n(numVertex), m(numEdges), isDirected(isDirected) {

	for (int i = 0; i < numEdges; i++) {
		AdjacencyListWithWeights[EdgeListWithWts[i][0]].push_back(std::make_pair((int)EdgeListWithWts[i][1], EdgeListWithWts[i][2]));
		if (!isDirected)
			AdjacencyListWithWeights[EdgeListWithWts[i][1]].push_back(std::make_pair((int)EdgeListWithWts[i][0], EdgeListWithWts[i][2]));
	}
}

void StandardGraphClass::StdGraphInputs(int &numVertices, int &numEdges, VectorOfPairs &EdgeList) {
	std::cout << "Enter (numVertices'vc' numEdges'ec'): ";
	std::cin >> numVertices >> numEdges;

	for (int i = 1; i <= numEdges; i++)
	{
		int v1, v2;
		std::cout << std::endl << "Enter #" << i << " edge by vertex pair (v1 v2): ";
		std::cin >> v1 >> v2;
		EdgeList.push_back(std::make_pair(v1, v2));
	}
}

void StandardGraphClass::StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts, int &Start, int &End) {
	std::cout << "Enter (numVertices'vc' numEdges'ec'): ";
	std::cin >> numVertices >> numEdges;

	for (int i = 1; i <= numEdges; i++)
	{
		llong v1, v2, wt;
		std::cout << std::endl << "Enter #" << i << " edge by vertex pair and wt as (v1 v2 wt): ";
		std::cin >> v1 >> v2>>wt;
		EdgeListWithWts.push_back({ v1, v2, wt });
	}

	// Vertices to determince if they meet.
	std::cout << std::endl << "Enter Start vertex 'u' and End Vertex 'v' as (u v): ";
	std::cin >> Start >> End;
}

void StandardGraphClass::StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts, int &Start) {
	std::cout << "Enter (numVertices'vc' numEdges'ec'): ";
	std::cin >> numVertices >> numEdges;

	for (int i = 1; i <= numEdges; i++)
	{
		llong v1, v2, wt;
		std::cout << std::endl << "Enter #" << i << " edge by vertex pair and wt as (v1 v2 wt): ";
		std::cin >> v1 >> v2>>wt;
		EdgeListWithWts.push_back({ v1, v2, wt });
	}

	// Start Vertex
	std::cout << std::endl << "Enter Start vertex 'u': ";
	std::cin >> Start;
}

void StandardGraphClass::StdGraphInputsWithWts(int &numVertices, int &numEdges, TDVector &EdgeListWithWts) {
	std::cout << "Enter (numVertices'vc' numEdges'ec'): ";
	std::cin >> numVertices >> numEdges;

	for (int i = 1; i <= numEdges; i++)
	{
		llong v1, v2, wt;
		std::cout << std::endl << "Enter #" << i << " edge by vertex pair and wt as (v1 v2 wt): ";
		std::cin >> v1 >> v2 >> wt;
		EdgeListWithWts.push_back({ v1, v2, wt });
	}
}