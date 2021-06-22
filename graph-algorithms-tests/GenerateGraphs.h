#pragma once
#include<iostream>
#include<vector>
#include<algorithm>


void GenerateGraphs(std::pair<int, int> numVertex_MinMax, std::pair<int, int> numEdges_MinMax, int &numVertex, int &numEdges, std::vector<std::pair<int, int>> &EdgeList, int &startVertex, int &endVertex) {
	numVertex = rand() % (numVertex_MinMax.second - numVertex_MinMax.first +1) + numVertex_MinMax.first;
	numEdges = rand() % (numEdges_MinMax.second - numEdges_MinMax.first +1) + numEdges_MinMax.first;

	for (int i = 0; EdgeList.size() <= numEdges; i++) {
		int v1 = rand() % (numVertex) + 1;
		int v2 = rand() % (numVertex) + 1;
		if (v1<= numVertex && v2 <= numVertex)
			EdgeList.push_back(std::make_pair(v1, v2));
	}

	startVertex = rand() % (numVertex)+1;
	endVertex = rand() % (numVertex)+1;
}

std::vector<std::vector<int>>  GenerateAdjacencyMatrix(std::vector<std::pair<int, int>> &EdgeList, const int &numVertex) {

	std::vector<std::vector<int>> AdjacencyMatrix;

	for (int i = 0; i <= numVertex; i++) {
		std::vector<int> row;
		for (int j = 0; j <= numVertex; j++)
			row.push_back(EdgeList.size()+1);
		AdjacencyMatrix.push_back(row);
	}

	for (int i = 0; i < EdgeList.size(); i++) {
		AdjacencyMatrix[EdgeList[i].first][EdgeList[i].second] = 1;
		AdjacencyMatrix[EdgeList[i].second][EdgeList[i].first] = 1;
	}

	return AdjacencyMatrix;
}


// Floyd Warshall Algorithm algorithm with Time Complexity O(n^3)

std::vector<std::vector<int>> GenerateFloydWarshallMatrix(std::vector<std::vector<int>> AdjacencyMatrix) {

	std::vector<std::vector<int>> FloydWarshallMatrix;

	for (int i = 0; i < AdjacencyMatrix[0].size(); i++) {
		std::vector<int> row;
		for (int j = 0; j < AdjacencyMatrix[0].size(); j++) {
			if (i == j) 
				row.push_back(0);
			else
				row.push_back(AdjacencyMatrix[i][j]);
		}
		FloydWarshallMatrix.push_back(row);
	}

	for (int k = 1; k < FloydWarshallMatrix[0].size(); k++)
		for (int i = 1; i < FloydWarshallMatrix[0].size(); i++)
			for (int j = 1; j < FloydWarshallMatrix[0].size(); j++){
					if (FloydWarshallMatrix[i][k] + FloydWarshallMatrix[k][j] < FloydWarshallMatrix[i][j])
						FloydWarshallMatrix[i][j] = FloydWarshallMatrix[i][k] + FloydWarshallMatrix[k][j];
				}

	return FloydWarshallMatrix;
}