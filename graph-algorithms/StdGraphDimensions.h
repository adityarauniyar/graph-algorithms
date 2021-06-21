#pragma once
#include<map>
#include<vector>

// Input Format. An undirected graph with 𝑛 vertices and 𝑚 edges.The next line contains two vertices 𝑢
//	and 𝑣 of the graph.
// Constraints. 2 ≤ 𝑛 ≤ 103
//  ; 1 ≤ 𝑚 ≤ 103
//  ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 𝑢 ̸ = 𝑣.

class StandardGraphClass
{
	protected:
		int n;
		int m;
		std::map<int, std::vector<int>> AdjacencyList;
	public:
		void static StdGraphInputs(int &n, int &m, std::vector<std::pair<int, int>> &EdgeList);
		StandardGraphClass(int n, int m) : n(n), m(m) {}
};

void StandardGraphClass::StdGraphInputs(int &numVertices, int &numEdges, std::vector<std::pair<int, int>> &EdgeList) {
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