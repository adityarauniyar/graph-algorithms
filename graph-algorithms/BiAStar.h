#pragma once
#include <cassert>
#include <vector>
#include <queue>
#include <utility>
#include "Constants.h"

// DISCLAIMER : CODE CONTAINS SOME CORNER CASE BUG

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

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
typedef pair<llong, int> QElem;
typedef vector<priority_queue<QElem, vector<QElem>, greater<QElem>>> Queue;

namespace Adv {

	class BiAStar {
		// Number of nodes
		int n_;
		// Graph adj_[0] and cost_[0] correspond to the initial graph,
		// adj_[1] and cost_[1] correspond to the reversed graph.
		// Graphs are stored as vectors of adjacency lists corresponding
		// to nodes.
		// Adjacency list itself is stored in adj_ with (Adj Vertex, Cost) pair.
		DoubleAdj adj_;
		// weights_[0] stores distances for the forward search,
		// and weights_[1] stores distances for the backward search.
		vector<vector<llong>> weights_;
		// Stores all the nodes visited either by forward or backward search.
		vector<int> workset_;
		// Stores a flag for each node which is True iff the node was visited
		// either by forward or backward search.
		vector<bool> visited_;
		// Coordinates of the nodes
		vector<pair<llong, llong>> xy_;

	public:
		BiAStar(int, DoubleAdj, vector<pair<llong, llong>>);

		// Initialize the data structures before new query,
		// clear the changes made by the previous query.
		void clear();

		// Processes visit of either forward or backward search 
		// (determined by value of side), to node v trying to
		// relax the current distance by dist.
		void visit(Queue&, int, int, llong, llong);

		// Returns the distance from s to t in the graph.
		llong query(int, int);
		string query(vector<pair<int, int>>);

		// Function that processes i.e. does a BFS on the priortised vertex
		void process(Queue&, int, int, int);

		// Finding the shortestpath 
		llong shortestpath(int, int);
		// Euclidean Distance 
		llong findEuclideanDistance(int, int, int, int);
	};

}

Adv::BiAStar::BiAStar(int n, DoubleAdj adj, vector<pair<llong, llong>> xy)
	: n_(n + 1), adj_(adj), weights_(2, vector<llong>(n + 1, INF)), visited_(n + 1), xy_(xy)
{
	workset_.reserve(n + 1);
}

void Adv::BiAStar::clear() {
	for (int i = 0; i < workset_.size(); ++i) {
		int v = workset_[i];
		weights_[0][v] = weights_[1][v] = INF;
		visited_[v] = false;
	}
	workset_.clear();
}

llong Adv::BiAStar::findEuclideanDistance(int x1, int y1, int x2, int y2) {
	return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

void Adv::BiAStar::visit(Queue& q, int side, int v, llong BiAStarVal, llong wt) {

	q[side].push(make_pair(BiAStarVal, v));
	weights_[side][v] = wt;
	workset_.push_back(v);
}

llong Adv::BiAStar::shortestpath(int s, int t) {
	llong min = INF;
	for (int i = 0; i < workset_.size(); i++) {
		int iVertex = workset_[i];
		llong dist = weights_[0][iVertex] + weights_[1][iVertex]; 
		if (dist < min)
			min = dist;
	}
	return min == INF ? -1 : min;
}

llong Adv::BiAStar::query(int s, int t) {
	Queue q(2);
	clear();

	int Start = s;
	int End = t;

	visit(q, 0, Start, 0, 0);
	visit(q, 1, End, 0, 0);

	while (!q[0].empty() && !q[1].empty()) {
		QElem FwdElem = q[0].top();
		q[0].pop();
		QElem BackElem = q[1].top();
		q[1].pop();

		// Fwd A* 
		process(q, 0, FwdElem.second, End);

		if (visited_[FwdElem.second] && (q[0].empty() || weights_[0][FwdElem.second] <= weights_[0][q[0].top().second]))
			return shortestpath(Start, End);
		visited_[FwdElem.second] = true;

		// Back A*  
		process(q, 1, BackElem.second, Start);

		if (visited_[BackElem.second] && (q[1].empty() || weights_[1][BackElem.second] <= weights_[1][q[1].top().second]))
			return shortestpath(Start, End);
		visited_[BackElem.second] = true;
	}
	

	return (weights_[0][End] + weights_[1][Start] < INF) ? min(weights_[0][End], weights_[1][Start]) : -1;
}

void Adv::BiAStar::process(Queue& q, int side, int iVertex, int goalV) {
	for (int i = 0; i < adj_[side][iVertex].size(); i++) {
		int AdjVtx = adj_[side][iVertex][i].first,
			AdjDist = adj_[side][iVertex][i].second;
		// adding Euclidean distance from the adjacent vertex to the goal vertex
		// A smaller distance would signify we are getting close.
		int x1 = xy_[goalV].first,
			y1 = xy_[goalV].second,
			x2 = xy_[AdjVtx].first,
			y2 = xy_[AdjVtx].second;
		llong eucludeanDist = findEuclideanDistance(x1, y1, x2, y2);
		llong weightsToBe = weights_[side][iVertex] + AdjDist;
		llong BiAStarVal = weightsToBe + eucludeanDist;

		if (weights_[side][AdjVtx] > weightsToBe)
			visit(q, side, AdjVtx, BiAStarVal, weightsToBe);
	}
}

string Adv::BiAStar::query(vector<pair<int, int>> Queries) {
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