#pragma once
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include "Constants.h"
#include <iostream>
#include <string>

// Problem Description

// Task. Compute the distance between several pairs of nodes in the network.

// Input Format.You will be given the input for this problem in two parts.The first part contains the
// description of a road network, the second part contains the queries.You have a separate time limit for
// preprocesssing the graph.Under this time limit, you need to read the graph and preprocesss it.After
// you’ve preprocesssed the graph, you need to output the string “Ready”(without quotes) and flush the
// output buffer(the starter files for C++, Java and Python3 do that for you; if you use another language,
// you will have to find out how to do this).Only after you output the string “Ready” you will be given
// the queries.You will have a time limit for the querying part, and under this time limit you will need
// to input all the queries and output the results for each of the quires.
// The first line of the road network description contains two integers 𝑛 and 𝑚 — the number of nodes
// and edges in the network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following
// 𝑚 lines contains three integers 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node
// number 𝑢 to the node number 𝑣.
// The first line of the queries description contains an integer 𝑞 — the number of queries for computing
// the distance.Each of the following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers of the two
// nodes to compute the distance from 𝑢 to 𝑣.

// Constraints. 1 ≤ 𝑛 ≤ 110 000; 1 ≤ 𝑚 ≤ 250 000; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 1 ≤ 𝑙 ≤ 200 000; 1 ≤ 𝑞 ≤ 10 000. It is
// guaranteed that the correct distances are less than 1 000 000 000. For Python2, Python3, Ruby
// and Javascript, 1 ≤ 𝑛 ≤ 11 000, 1 ≤ 𝑚 ≤ 25 000, 1 ≤ 𝑞 ≤ 1 000.

// Output Format.After you’ve read the description of the road network and done your preprocesssing,
// output one string “Ready”(without quotes) on a separate line and flush the output buffer.Then read
// the queries, and for each query, output one integer on a separate line.If there is no path from 𝑢 to 𝑣,
// output −1.Otherwise, output the distance from 𝑢 to 𝑣.
using namespace std;

// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of DoubleAdjMapListacency lists for each node.
// pair is as (DoubleAdjMapListacent vertex, distance)

// Distances can grow out of int type
typedef long long llong;

// Vector of two priority Qs - for forward and backward searches.
// Each priority Q stores the closest unprocessed node in its head.
typedef pair<llong, int> QElem;
typedef vector<priority_queue<QElem, vector<QElem>, greater<QElem>>> DoubleQ;


namespace Adv {

	class ContractionHierarchies {

		// Number of nodes
		int n_;
		// adj_[0] correspond to the edges in initial graph,
		// adj_[1] correspond to the edges in reversed graph.
		DoubleAdjMapList adj_;
		// weights_[0] stores distances for the forward search,
		// weights_[1] stores distances for the backward search.
		vector<vector<llong>> weights_;
		// Stores all the nodes visited either by forward or backward search.
		vector<int> workset_;
		// visited logs for each node
		vector<bool> visited_;

		// Heuristic data items
		vector<llong> minIncomingEdge_;
		vector<int> nodeLevel_;
		int nodeContractionImp_;
		int shortcutCount_;
		Q importanceQ;
		// Node Order for each nodes after preprocesssing 
		vector<int> rank_;

		// list of shortcuts 
		struct ShortCut {
			int v1;
			int v2;
			llong dist;

			// ShortCut(int u, int v, llong c) : v1(u), v2(v), dist(c) {}
		};
		
		vector<ShortCut> shortcuts_;
		bool shouldAddShortcut = false;
		
	public:
		ContractionHierarchies(int, DoubleAdjMapList);

		// Initialize the data structures before new query,
		// clear the changes made by the previous query.
		void clear();

		// Processes visit of either forward or backward search 
		// (determined by value of side), to node v trying to
		// relax the current distance by dist.
		void visit(DoubleQ& q, int side, int u, int v, llong cost);

		// Returns the distance from s to t in the graph.
		llong query(int, int);
		string query(vector<pair<int, int>>);

		// Contraction Hierarchies operation
		void initNodeContractionOrder();
		void preprocess();
		void contractNode(int&);
		llong witnessSearch(int&, int&, int&, llong&);
		void updateNodeLevel(int&);
		void addShortcut(int&, int&, llong&);
		void optimizeEdges();

		void process(DoubleQ&, QElem&, int);
	};

}

Adv::ContractionHierarchies::ContractionHierarchies(int n, DoubleAdjMapList Adj)
	: n_(n + 1), adj_(Adj), weights_(2, vector<llong>(n_,INF)), visited_(n_, false), rank_(n_, INT_MAX), nodeLevel_(n_, 0), shortcuts_(3), minIncomingEdge_(n_, INF)
{
	workset_.reserve(n + 1);

	for (auto& node : adj_[1]) {
		int v = node.first;
		for (auto& incomingNode : adj_[1][v]) {
			int uEdgeVal = incomingNode.second;
			if (minIncomingEdge_[v] > uEdgeVal)
				minIncomingEdge_[v] = uEdgeVal;
		}
	}
		
	preprocess();
	cout << "READY" << endl;
}

void Adv::ContractionHierarchies::clear() {
	for (int i = 0; i < workset_.size(); ++i) {
		int v = workset_[i];
		weights_[0][v] = weights_[1][v] = INF;
		visited_[v] = false;
	}
	workset_.clear();
}

void Adv::ContractionHierarchies::initNodeContractionOrder() {
	
	for (int v = 1; v < rank_.size(); ++v) {
		contractNode(v);
		importanceQ.push(make_pair(nodeContractionImp_, v));
	}
		
}

llong Adv::ContractionHierarchies::witnessSearch(int& u, int& v, int& w, llong& cost) {
	// Witness Search using Unidirectional Dijkstra
	vector<bool> djVisited(n_, false);
	vector<llong> djWts(n_, INF); 

	// limiting the number of loops during while()
	int hopsLimit = 3;

	djWts[u] = 0;
	Q q;
	q.push(make_pair(0, u));

	while (!q.empty() 
		&& q.top().second != w 
		&& q.top().first <= cost
		&& hopsLimit--) {

		QElem top = q.top();
		q.pop();
		
		for (auto& itr : adj_[0][top.second]) {
			int adjVtx = itr.first;
			if (adjVtx == v || rank_[adjVtx] <= rank_[v])
				continue;
			llong adjCost = itr.second;
			llong costToBe = djWts[top.second] + adjCost;
			if (djWts[adjVtx] > costToBe) {
				djWts[adjVtx] = costToBe;
				q.push(make_pair(djWts[adjVtx], adjVtx));
			}
		}
	}
	return djWts[w];
}

inline void Adv::ContractionHierarchies::addShortcut(int& u, int& w, llong& cost) {
	
	adj_[0][u][w] = cost;
	adj_[1][w][u] = cost;

}

void Adv::ContractionHierarchies::contractNode(int& v) {

	shortcuts_.clear();
	shortcutCount_ = 0;

	int contractedNeighbourCount = 0;
	int shortcutCoverCount = 0;

	// u --> v --> w
	// traversing backward adjacency list
	for(auto& BackItr : adj_[1][v]){
		int u = BackItr.first;
		llong uCost = BackItr.second;

		int initialShortcuts = shortcutCount_;
		if (rank_[v] <= rank_[u]) {
			// Traversing forward list from "v"
			for (auto& Fwditr : adj_[0][v]) {
				int w = Fwditr.first;
				llong wCost = Fwditr.second;
				if (rank_[w] >= rank_[v] && u != w) {
					llong cost = uCost + wCost;
					if (!adj_[0][u].count(w) || adj_[0][u][w] > cost) {
						llong trimmedCost = cost - minIncomingEdge_[w];
						llong alternateDist = witnessSearch(u, v, w, trimmedCost);
						if (alternateDist > cost) {
							shortcutCount_++;
							if (shouldAddShortcut)
								shortcuts_.push_back({ u, w, cost });
						}
					}
				}
				else if (rank_[w] < rank_[v])
					contractedNeighbourCount++;
			}
			if (shortcutCount_ > initialShortcuts) // check if any shortcut was added from "u" on contracting "v"
				shortcutCoverCount++;
		}
		else
			contractedNeighbourCount++;
	}

	// Setting node Importance value; the lesser the unimportant
	nodeContractionImp_ = shortcutCount_ - adj_[1][v].size() - adj_[0][v].size() // Edge Difference
		+ contractedNeighbourCount												 // Contracted Neighbours
		+ shortcutCoverCount													 // Shortcut Cover
		+ nodeLevel_[v];														 // Node level value
}

void Adv::ContractionHierarchies::updateNodeLevel(int& v) {
	int nodeLevelToBe = nodeLevel_[v] + 1;

	for (auto& outgoing : adj_[0][v]) {
		nodeLevel_[outgoing.first] = max(nodeLevel_[outgoing.first], nodeLevelToBe);
	}

	for (auto& incoming : adj_[1][v]) {
		nodeLevel_[incoming.first] = max(nodeLevel_[incoming.first], nodeLevelToBe);
	}
}

void Adv::ContractionHierarchies::optimizeEdges() {

	// removing edges from upper rank vertex to lower rank vertex in reverse Adjacency list
	for (auto& uElem = adj_[1].begin(); uElem != adj_[1].end();) {
		int u = uElem->first;
		uElem++;
		for (auto& vElem = adj_[1][u].begin(); vElem != adj_[1][u].end(); ) {
			int v = vElem->first;
			vElem++;
			if (rank_[v] < rank_[u])
				adj_[1][u].erase(v);
		}
	}

	// removing edges from upper rank vertex to lower rank vertex in forward Adjacency list 
	for (auto& uElem = adj_[0].begin(); uElem != adj_[0].end();) {
		int u = uElem->first;
		uElem++;
		for (auto& vElem = adj_[0][u].begin(); vElem != adj_[0][u].end(); ) {
			int v = vElem->first;
			vElem++;
			if (rank_[v] < rank_[u])
				adj_[0][u].erase(v);
		}
	}
}

void Adv::ContractionHierarchies::preprocess() {

	initNodeContractionOrder();
	shouldAddShortcut = true;
	int rankCounter = 1;
	
	while (!importanceQ.empty()) {
		auto node = importanceQ.top().second;
		importanceQ.pop();

		contractNode(node);

		if (importanceQ.empty() || nodeContractionImp_ <= importanceQ.top().first) {
			for (int i = 0; i < shortcutCount_; i++) {
				addShortcut(shortcuts_[i].v1, shortcuts_[i].v2, shortcuts_[i].dist);
			}
			updateNodeLevel(node);
			rank_[node] = rankCounter++;
		}
		else
			importanceQ.push(make_pair(nodeContractionImp_, node));
	}

	optimizeEdges();
}

void Adv::ContractionHierarchies::visit(DoubleQ& q, int side, int u, int v, llong cost) {
	if (weights_[side][v] > cost) {
		weights_[side][v] = cost;
		workset_.push_back(v);
		q[side].push(make_pair(cost, v));
	}
}

void Adv::ContractionHierarchies::process(DoubleQ& q, QElem& uElem, int side) {
	int u = uElem.second;
	llong uWt = uElem.first;
	for (auto& itr : adj_[side][u]) {
		int adjVtx = itr.first;
		llong adjWt = itr.second;
		llong wtToBe = uWt + adjWt;
		visit(q, side, u, adjVtx, wtToBe);
	}
}

llong Adv::ContractionHierarchies::query(int s, int t) {
	DoubleQ q(2);
	clear();

	int Start = s;
	int End = t;
	llong dist = INF;

	visit(q, 0, 0, Start, 0);
	visit(q, 1, 0, End, 0);

	while (!q[0].empty() || !q[1].empty()) {
		QElem FwdElem, RevElem;

		if (!q[0].empty()) {
			FwdElem = q[0].top();
			q[0].pop();

			if (visited_[FwdElem.second] && dist > weights_[0][FwdElem.second] + weights_[1][FwdElem.second])
				dist = weights_[0][FwdElem.second] + weights_[1][FwdElem.second];
			else {
				process(q, FwdElem, 0);
				visited_[FwdElem.second] = true;
			}

		}

		if (!q[1].empty()) {
			RevElem = q[1].top();
			q[1].pop();

			if (visited_[RevElem.second] && dist > weights_[0][RevElem.second] + weights_[1][RevElem.second])
				dist = weights_[0][RevElem.second] + weights_[1][RevElem.second];
			else {
				process(q, RevElem, 1);
				visited_[RevElem.second] = true;
			}
		}
	}

	return dist == INF ? -1 : dist;
}

string Adv::ContractionHierarchies::query(vector<pair<int, int>> Queries) {
	vector<int> QueryResult(Queries.size(), -1);

	for (int i = 0; i < Queries.size(); i++) {
		int Start = Queries[i].first;
		int End = Queries[i].second;

		QueryResult[i] = query(Start, End);

	}

	string Str;
	for (int i = 0; i < QueryResult.size(); i++) {

		Str += to_string(QueryResult[i]);

		if (i < QueryResult.size() - 1)
			Str += " ";
	}

	return Str;
}