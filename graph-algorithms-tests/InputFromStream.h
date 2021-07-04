#pragma once
#include<sstream>
#include<vector>
#include "..\graph-algorithms\Constants.h"

typedef long long llong;
typedef std::vector<std::vector<std::vector<std::pair<int, int>>>> FwdAndRevAdjWithCost;


void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::pair<int, int>> &EdgeList) {
	
	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		input >> v1;
		input >> v2;
		EdgeList.push_back(std::make_pair(v1, v2));
	}
	
}

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::pair<int, int>> &EdgeList, int &u, int &v) {
	
	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		input >> v1;
		input >> v2;
		EdgeList.push_back(std::make_pair(v1, v2));
	}
	input >> u;
	input >> v;
}

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::vector<llong>> &EdgeList, int &u, int &v) {
	
	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		llong v1, v2, val;
		input >> v1;
		input >> v2;
		input >> val;
		EdgeList.push_back({ v1,v2,val });
	}
	input >> u;
	input >> v;

}


void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::vector<int>> &EdgeList, int &u, int &v) {
	
	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, val;
		input >> v1;
		input >> v2;
		input >> val;
		EdgeList.push_back({ v1,v2,val });
	}
	input >> u;
	input >> v;

}

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::vector<llong>> &EdgeList, int &u) {
	
	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		llong v1, v2, val;
		input >> v1;
		input >> v2;
		input >> val;
		EdgeList.push_back({ v1,v2,val });
	}
	input >> u;

}

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::vector<llong>> &EdgeList) {

	input >> n;
	input >> m;
	for (int i = 0; i < m; i++) {
		llong v1, v2, val;
		input >> v1;
		input >> v2;
		input >> val;
		EdgeList.push_back({ v1,v2,val });
	}

}


// Reading Coordinates
void inputToVars(std::istringstream &input, int &n, std::vector<std::pair<int, int>> &CoordinatePairs) {

	input >> n;
	for (int i = 0; i < n; i++) {
		int v1, v2;
		input >> v1;
		input >> v2;
		CoordinatePairs.push_back(std::make_pair(v1, v2));
	}

}

// Reading Coordinates with no. of clusters
void inputToVars(std::istringstream &input, int &n, std::vector<std::pair<int, int>> &CoordinatePairs, int& numCluster) {

	input >> n;
	for (int i = 0; i < n; i++) {
		int v1, v2;
		input >> v1;
		input >> v2;
		CoordinatePairs.push_back(std::make_pair(v1, v2));
	}
	input >> numCluster;

}

// Reading and creating: forward and reverese adjacency list + reading the Queries
void inputToVars(std::istringstream &input, int &n, FwdAndRevAdjWithCost& Adj, std::vector<std::pair<int, int>>& Queries) {

	int numEdges;
	
	input >> n;
	input >> numEdges;

	std::vector<std::vector<std::pair<int, int>>> FwdAdjList(n+1);
	std::vector<std::vector<std::pair<int, int>>> RevAdjList(n+1);

	for (int i = 0; i < numEdges; i++) {
		int v1, v2, cost;
		input >> v1;
		input >> v2;
		input >> cost; 
		FwdAdjList[v1].push_back(std::make_pair( v2,cost ));
		RevAdjList[v2].push_back(std::make_pair(v1, cost));
	}
	Adj[0] = FwdAdjList;
	Adj[1] = RevAdjList;

	int numQueries;
	input >> numQueries;
	for (int i = 0; i < numQueries; i++) {
		int u, v;
		input >> u;
		input >> v;
		Queries.push_back({ u,v });
	}

}

// Reading and creating: forward and reverese adjacency list + reading the Queries in a map type Adj List
void inputToVars(std::istringstream &input, int &n, DoubleAdjMapList& Adj, std::vector<std::pair<int, int>>& Queries) {

	int numEdges;
	
	input >> n;
	input >> numEdges;

	for (int i = 0; i < numEdges; i++) {
		int v1, v2, cost;
		input >> v1;
		input >> v2;
		input >> cost; 
		Adj[0][v1][v2] = cost;
		Adj[1][v2][v1] = cost;
	}

	int numQueries;
	input >> numQueries;
	for (int i = 0; i < numQueries; i++) {
		int u, v;
		input >> u;
		input >> v;
		Queries.push_back({ u,v });
	}

}

// Reading coordinates of each node and creating: forward and reverese adjacency list + reading the Queries
void inputToVars(std::istringstream &input, int &n, std::vector<std::pair<llong, llong>>& xy, FwdAndRevAdjWithCost& Adj, std::vector<std::pair<int, int>>& Queries) {

	int numEdges;
	
	input >> n;
	input >> numEdges;

	std::vector<std::vector<std::pair<int, int>>> FwdAdjList(n+1);
	std::vector<std::vector<std::pair<int, int>>> RevAdjList(n+1);
	xy.push_back(std::make_pair(0, 0));

	for (int i=0; i < n; i++) {
		int c1, c2;
		input >> c1;
		input >> c2;
		xy.push_back(std::make_pair(c1, c2));
	}

	for (int i = 0; i < numEdges; i++) {
		int v1, v2, cost;
		input >> v1;
		input >> v2;
		input >> cost; 
		FwdAdjList[v1].push_back(std::make_pair( v2,cost ));
		RevAdjList[v2].push_back(std::make_pair(v1, cost));
	}
	Adj[0] = FwdAdjList;
	Adj[1] = RevAdjList;

	int numQueries;
	input >> numQueries;
	for (int i = 0; i < numQueries; i++) {
		int u, v;
		input >> u;
		input >> v;
		Queries.push_back({ u,v });
	}

}

// Reading coordinates of each node and creating: forward adjacency list + reading the Queries
void inputToVars(std::istringstream &input, int &n, std::vector<std::pair<llong, llong>>& xy, Adj& Adj, std::vector<std::pair<int, int>>& Queries) {

	int numEdges;
	
	input >> n;
	input >> numEdges;

	std::vector<std::vector<std::pair<int, int>>> FwdAdjList(n+1);
	xy.push_back(std::make_pair(0, 0));

	for (int i=0; i < n; i++) {
		int c1, c2;
		input >> c1;
		input >> c2;
		xy.push_back(std::make_pair(c1, c2));
	}

	for (int i = 0; i < numEdges; i++) {
		int v1, v2, cost;
		input >> v1;
		input >> v2;
		input >> cost; 
		FwdAdjList[v1].push_back(std::make_pair( v2,cost ));
	}
	Adj = FwdAdjList;

	int numQueries;
	input >> numQueries;
	for (int i = 0; i < numQueries; i++) {
		int u, v;
		input >> u;
		input >> v;
		Queries.push_back({ u,v });
	}

}