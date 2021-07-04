#pragma once
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include "Constants.h"

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
		// Graph adj_[0] and cost_[0] correspond to the initial graph,
		// adj_[1] and cost_[1] correspond to the reversed graph.
		// Graphs are stored as vectors of DoubleAdjMapListacency lists corresponding
		// to nodes.
		// DoubleAdjMapListacency list itself is stored in adj_ with (DoubleAdjMapList Vertex, Cost) pair.
		DoubleAdjMapList adj_;
		// weights_ stores distances for the forward search,
		// and weights_[1] stores distances for the backward search.
		vector<vector<llong>> weights_;
		// Stores all the nodes visited either by forward or backward search.
		vector<int> workset_;
		// visited logs for each node
		vector<bool> visited_;
		// Contraction order for ndoes during preprocessing.
		vector<int> nodeContractionOrder_;
		// Status of whether ndoe is contracted or not; useful while preprocessing 
		vector<bool> isContracted;
		// Node Order for each nodes after preprocesssing 
		vector<int> nodeOrder_;
		// DoubleAdjMapListacency List of shortcut edges added during preprocesssing
		DoubleAdjMapList adjWithShortcuts_;

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

		// Contraction Hierarchies operations
		void setNodeContractionOrder();
		void preprocess();
		void contractNode(int&);
		llong findDijkstraDist(int&, int&, llong&);
		void addShortcut(int&, int&, llong&, llong&);
		void optimizeEdges();

		void process(DoubleQ&, QElem&, int);
	};

}

Adv::ContractionHierarchies::ContractionHierarchies(int n, DoubleAdjMapList Adj)
	: n_(n + 1), adj_(Adj), weights_(2, vector<llong>(n_,INF)), visited_(n_, false), nodeOrder_(n_, -1), nodeContractionOrder_(n,-1), isContracted(n_, false)
{
	workset_.reserve(n + 1);
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

void Adv::ContractionHierarchies::setNodeContractionOrder() {

	// Set Order at which the node contraction should take place. This would also define its node level.
	// TODO: set order in such a way that node with min edges gets contracted first and max at last; 
	//		this would optimize shortcut edge addition.
	for (int i = 0; i < nodeContractionOrder_.size(); ++i)
		nodeContractionOrder_[i] = i+1; // +1 since node numbers are from 1 to ...
	// Defining the node order based on node contraction order.
	for (int i = 1; i < nodeOrder_.size(); ++i)
		nodeOrder_[nodeContractionOrder_[i-1]] = i;
}

llong Adv::ContractionHierarchies::findDijkstraDist(int& u, int& v, llong& cost) {
	// Witness Search using Unidirectional Dijkstra
	vector<bool> djVisited(n_, false);
	vector<llong> djWts(n_, INF); 

	vector<int> hopsCounter(n_, 1);
	int hopsLimit = 1;

	djWts[u] = 0;
	Q q;
	q.push(make_pair(0, u));

	// Finding the shortest edge to v from NOT contracted nodes.
	llong finalEdgeAtMin = INF;
	for (auto& nodeElem : adj_[1][v]) {
		if (finalEdgeAtMin > nodeElem.second && !isContracted[nodeElem.first])
			finalEdgeAtMin = nodeElem.second;
	}

	while (!q.empty() 
		&& q.top().second != v 
		&& q.top().first <= (cost-finalEdgeAtMin)
		&& hopsCounter[q.top().second] <= hopsLimit) {

		QElem top = q.top();
		q.pop();
		
		for (auto& itr : adj_[0][u]) {
			int adjVtx = itr.first;
			if (isContracted[adjVtx])
				continue;
			hopsCounter[adjVtx] = hopsCounter[top.second] + 1;
			llong adjCost = itr.second;
			llong costToBe = djWts[top.second] + adjCost;
			if (djWts[adjVtx] > costToBe) {
				djWts[adjVtx] = costToBe;
				q.push(make_pair(djWts[adjVtx], adjVtx));
			}
		}
	}

	return djWts[v];
}

void Adv::ContractionHierarchies::addShortcut(int& u, int& w, llong& uCost, llong& wCost) {

	llong costToBe = uCost + wCost;
	if (!adj_[0][u].count(w) || adj_[0][u][w] > costToBe) {
		llong alternateDist = findDijkstraDist(u, w, costToBe);
		if (alternateDist > costToBe) {
			if (nodeOrder_[u] > nodeOrder_[w])
				adj_[1][w][u] = costToBe;
			else
				adj_[0][u][w] = costToBe;
		}
	}
}

void Adv::ContractionHierarchies::contractNode(int& v) {

	isContracted[v] = true;

	// u --> v --> w
	// traversing backward adjacency list
	for (auto& Backitr : adj_[1][v]) {
		int u = Backitr.first;
		llong uCost = Backitr.second;
		if (!isContracted[u]) {
			// Traversing forward list from "v"
			for (auto& Fwditr : adj_[0][v]) {
				int w = Fwditr.first;
				llong wCost = Fwditr.second;
				if (!isContracted[w] && u != w) {
					addShortcut(u, w, uCost, wCost);
					adj_[1][w].erase(v); // removing edges towards lower level from Rev Adj List
				}
			}
			adj_[0][u].erase(v); // removing edges towards lower level from Fwd Adj List
		}
	}
	
}

void Adv::ContractionHierarchies::optimizeEdges() {
	
}

void Adv::ContractionHierarchies::preprocess() {

	setNodeContractionOrder();
	
	for (int node : nodeContractionOrder_)
		if (!isContracted[node]) {
			contractNode(node);
		}		
	optimizeEdges();
}

void Adv::ContractionHierarchies::visit(DoubleQ& q, int side, int u, int v, llong cost) {
	if (nodeOrder_[v] > nodeOrder_[u] && weights_[side][v] > cost) {
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