#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include "..\graph-algorithms\Constants.h"


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

std::vector<std::vector<int>> GenerateFloydWarshallMatrix(const std::vector<std::vector<int>> &AdjacencyMatrix) {

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

// Generates Edge List with weights. 
void GenerateGraphs(std::pair<int, int> numVertex_MinMax, std::pair<int, int> numEdges_MinMax, std::pair<int, int> wt_MinMax, int &numVertex, int &numEdges, std::vector<std::vector<int>> &EdgeListWithWt, int &startVertex, int &endVertex) {
	numVertex = rand() % (numVertex_MinMax.second - numVertex_MinMax.first + 1) + numVertex_MinMax.first;
	numEdges = rand() % (numEdges_MinMax.second - numEdges_MinMax.first + 1) + numEdges_MinMax.first;

	for (int i = 0; EdgeListWithWt.size() <= numEdges; i++) {
		int v1 = rand() % (numVertex)+1,
			v2 = rand() % (numVertex)+1,
			wt = rand() % (wt_MinMax.second - wt_MinMax.first + 1) + wt_MinMax.first;

		if (v1 <= numVertex && v2 <= numVertex && v1!=v2)
			EdgeListWithWt.push_back({ v1,v2,wt });
	}

	startVertex = rand() % (numVertex)+1;
	endVertex = rand() % (numVertex)+1;
}

// Generates Bidirectional Adjacency list from list of Edges as input.
DoubleAdj GenerateBiDirectionAdjList(const int& n, const std::vector<std::vector<int>>& EdgelistWithWt) {

	DoubleAdj BiDirAdjList(2, std::vector<std::vector<std::pair<int, int>>>(n + 1));

	for (int i = 0; i< EdgelistWithWt.size(); i++) {
		int v1 = EdgelistWithWt[i][0],
			v2 = EdgelistWithWt[i][1],
			cost = EdgelistWithWt[i][2];
		BiDirAdjList[0][v1].push_back(std::make_pair(v2, cost));
		BiDirAdjList[1][v2].push_back(std::make_pair(v1, cost));
	}

	return BiDirAdjList;
}

// Generates Bidirectional Adjacency list from list of Edges as input.
Adj GenerateAdjList(const int& n, const std::vector<std::vector<int>>& EdgelistWithWt) {

	Adj AdjList(n + 1);

	for (int i = 0; i< EdgelistWithWt.size(); i++) {
		int v1 = EdgelistWithWt[i][0],
			v2 = EdgelistWithWt[i][1],
			cost = EdgelistWithWt[i][2];
		AdjList[v1].push_back(std::make_pair(v2, cost));
	}

	return AdjList;
}

// Generate randin coordinate points for 'n' nodes within coordinate range
std::vector<std::pair<llong, llong>> GenerateCoordinates(const int& n, std::pair<int, int> coordinates_MinMax) {

	std::vector<std::pair<llong, llong>> xy(n+1);

	for (int i = 1; i < xy.size(); i++) {
		llong c1 = rand() % (coordinates_MinMax.second - coordinates_MinMax.first + 1) + coordinates_MinMax.first,
			c2 = rand() % (coordinates_MinMax.second - coordinates_MinMax.first + 1) + coordinates_MinMax.first;
		xy[i] = make_pair(c1, c2);
	}

	return xy;

}

void convertDoubleAdjToMapAdj(DoubleAdjMapList& adj1, DoubleAdj& adj2) {
	for (int i = 0; i < adj2.size(); i++) {
		for (int j = 1; j < adj2[i].size(); j++) {
			for (int k = 1; k < adj2[i][j].size(); k++) {
				int v = adj2[i][j][k].first;
				llong cost = adj2[i][j][k].second;
				adj1[i][j][v] = cost;
			}
		}
	}
}

void convertAdjToDoubleMapAdj(Adj& adj2, DoubleAdjMapList& adj1) {
	
	for (int j = 1; j < adj2.size(); j++) {
		for (int k = 0; k < adj2[j].size(); k++) {
			int v = adj2[j][k].first;
			llong cost = adj2[j][k].second;
			if (!adj1[0][j].count(v) || adj1[0][j][v]>cost)
				adj1[0][j][v] = cost;
			if (!adj1[1][v].count(j) || adj1[1][v][j] > cost)
				adj1[1][v][j] = cost;
		}
	}
}