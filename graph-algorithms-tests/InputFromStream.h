#pragma once
#include<sstream>
#include<vector>

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::pair<int, int>> &EdgeList) {
	while (input) {
		input >> n;
		input >> m;
		for (int i = 0; i < m; i++) {
			int v1, v2;
			input >> v1;
			input >> v2;
			EdgeList.push_back(std::make_pair(v1, v2));
		}
	}
}

void inputToVars(std::istringstream &input, int &n, int &m, std::vector<std::pair<int, int>> &EdgeList, int &u, int &v) {
	while (input) {
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
}