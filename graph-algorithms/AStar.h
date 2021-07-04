#pragma once
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include "Constants.h"

// Problem Description
// Task.Compute the distance between several pairs of nodes in the network.
// Input Format.The first line contains two integers 𝑛 and 𝑚 — the number of nodes and edges in the
// network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following 𝑛 lines contains the
// coordinates 𝑥 and 𝑦 of the corresponding node.Each of the following 𝑚 lines contains three integers
// 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node number 𝑢 to the node number 𝑣.
// It is guaranteed that 𝑙 ≥
// √︀(𝑥(𝑢) − 𝑥(𝑣))2 + (𝑦(𝑢) − 𝑦(𝑣))2 where(𝑥(𝑢), 𝑦(𝑢)) are the coordinates of 𝑢
// and (𝑥(𝑣), 𝑦(𝑣)) are the coordinates of 𝑣.The next line contains an integer 𝑞 — the number of queries
// for computing the distance.Each of the following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers
// of the two nodes to compute the distance from 𝑢 to 𝑣.
// Constraints. 1 ≤ 𝑛 ≤ 110 000; 1 ≤ 𝑚 ≤ 250 000; −1e9 ≤ 𝑥, 𝑦 ≤ 1e9
// ; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 0 ≤ 𝑙 ≤ 100 000;
// 1 ≤ 𝑞 ≤ 10 000. For Python2, Python3, Ruby and Javascript, 1 ≤ 𝑛 ≤ 11 000, 1 ≤ 𝑚 ≤ 30 000.
// Output Format.For each query, output one integer.If there is no path from 𝑢 to 𝑣, output −1.Otherwise,
// output the distance from 𝑢 to 𝑣.
using namespace std;

// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
// pair is as (adjacent vertex, distance)

// Distances can grow out of int type
typedef long long llong;

// Vector of two priority Qs - for forward and backward searches.
// Each priority Q stores the closest unprocessed node in its head.

namespace Adv {

	class AStar {
		// Number of nodes
		int n_;
		// Graph adj_[0] and cost_[0] correspond to the initial graph,
		// adj_[1] and cost_[1] correspond to the reversed graph.
		// Graphs are stored as vectors of adjacency lists corresponding
		// to nodes.
		// Adjacency list itself is stored in adj_ with (Adj Vertex, Cost) pair.
		Adj adj_;
		// weights_ stores distances for the forward search,
		// and weights_[1] stores distances for the backward search.
		vector<llong> weights_;
		// Stores all the nodes visited either by forward or backward search.
		vector<int> workset_;
		// Coordinates of the nodes
		vector<pair<llong, llong>> xy_;
		// visited logs for each node
		vector<bool> visited_;

	public:
		AStar(int, Adj, vector<pair<llong, llong>>);

		// Initialize the data structures before new query,
		// clear the changes made by the previous query.
		void clear();

		// Processes visit of either forward or backward search 
		// (determined by value of side), to node v trying to
		// relax the current distance by dist.
		void visit(Q&, int, llong, llong);

		// Returns the distance from s to t in the graph.
		llong query(int, int);
		string query(vector<pair<int, int>>);

		// Function that processes i.e. does a BFS on the priortised vertex
		void process(Q&, int, int);

		// Euclidean Distance 
		llong findEuclideanDistance(int&, int&, int&, int&);

		// Euclidean Distance between nodes
		map<int, map<int, llong>> euclideanDistance;
	};

}

Adv::AStar::AStar(int n, Adj adj, vector<pair<llong, llong>> xy)
	: n_(n + 1), adj_(adj), weights_(n + 1, INF), xy_(xy), visited_(n+1, false)
{
	workset_.reserve(n + 1);
}

void Adv::AStar::clear() {
	for (int i = 0; i < workset_.size(); ++i) {
		int v = workset_[i];
		weights_[v] = INF;
		visited_[v] = false;
	}
	workset_.clear();
}

llong Adv::AStar::findEuclideanDistance(int& x1, int& y1, int& x2, int& y2) {
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

void Adv::AStar::visit(Q& q, int v, llong AStarVal, llong wt) {

	weights_[v] = wt;
	workset_.push_back(v);
	if (!visited_[v])
		q.push(make_pair(AStarVal, v));
}

llong Adv::AStar::query(int s, int t) {
	Q q;
	clear();

	int Start = s;
	int End = t;
	llong dist = INF;

	visit(q, Start, 0, 0);
	
	while (!q.empty()) {
		QElem FwdElem = q.top();
		q.pop();

		if (FwdElem.second == End) {
			dist = weights_[FwdElem.second];
			continue;
		}
			
		if (weights_[FwdElem.second] <= dist)
			process(q, FwdElem.second, End);

		visited_[FwdElem.second] = true;
	}

	return dist == INF ? -1 : dist;
}

void Adv::AStar::process(Q& q, int iVertex, int goalV) {
	for (int i = 0; i < adj_[iVertex].size(); i++) {
		int AdjVtx = adj_[iVertex][i].first,
			AdjDist = adj_[iVertex][i].second;
		// adding Euclidean distance from the adjacent vertex to the goal vertex
		// A smaller distance would signify we are getting close.
		if (!euclideanDistance[AdjVtx][goalV] && !euclideanDistance[goalV][AdjVtx]) {
			int x1 = xy_[AdjVtx].first,
				y1 = xy_[AdjVtx].second,
				x2 = xy_[goalV].first,
				y2 = xy_[goalV].second;
			euclideanDistance[goalV][AdjVtx] = findEuclideanDistance(x1, y1, x2, y2);
		}
		llong eucludeanDist = euclideanDistance[AdjVtx][goalV] || euclideanDistance[goalV][AdjVtx];
		llong weightsToBe = weights_[iVertex] + AdjDist;
		llong AStarVal = weightsToBe + eucludeanDist;

		if (weights_[AdjVtx] > weightsToBe)
			visit(q, AdjVtx, AStarVal, weightsToBe);
	}
}

string Adv::AStar::query(vector<pair<int, int>> Queries) {
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