#pragma once
#include<sstream>
#include<vector>

typedef long long llong;

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