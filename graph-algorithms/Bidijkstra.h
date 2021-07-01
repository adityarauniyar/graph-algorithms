#pragma once
// Problem Description
// Task.Compute the distance between several pairs of nodes in the network. 
// 
// Input Format.The first line contains two integers 𝑛 and 𝑚 — the number of nodes and edges in the
// network, respectively.The nodes are numbered from 1 to 𝑛.Each of the following 𝑚 lines contains
// three integers 𝑢, 𝑣 and 𝑙 describing a directed edge(𝑢, 𝑣) of length 𝑙 from the node number 𝑢to the
// node number 𝑣. (Note that some social networks are represented by directed graphs while some other
// correspond naturally to undirected graphs.For example, Twitter is a directed graph(with a directed
// 	edge(𝑢, 𝑣) meaning that 𝑢 follows 𝑣), while Facebook is an undirected graph(where an undirected
// 		edge{ 𝑢, 𝑣 } means that 𝑢 and 𝑣 are friends).In this problem, we work with directed graphs only for a
// simple reason.It is easy to turn an undirected graph into a directed one : just replace each undirected
// edge{ 𝑢, 𝑣 } with a pair of directed edges(𝑢, 𝑣) and (𝑣, 𝑢).)
// The next line contains an integer 𝑞 — the number of queries for computing the distance.Each of the
// following 𝑞 lines contains two integers 𝑢 and 𝑣 — the numbers of the two nodes to compute the distance
// from 𝑢 to 𝑣.

// Constraints. 1 ≤ 𝑛 ≤ 1 000 000; 1 ≤ 𝑚 ≤ 6 000 000; 1 ≤ 𝑢, 𝑣 ≤ 𝑛; 1 ≤ 𝑙 ≤ 1 000; 1 ≤ 𝑞 ≤ 1 000. For
// Python2, Python3, Ruby and Javascript, 1 ≤ 𝑚 ≤ 2 000 000.
// Output Format.For each query, output one integer on a separate line.If there is no path from 𝑢 to 𝑣,
// output −1.Otherwise, output the distance from 𝑢 to 𝑣

#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include "Constants.h"

using namespace std;

// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
// pair is as (adjacent vertex, distance)
typedef vector<vector<vector<pair<int,int>>>> DoubleAdj;

// Distances can grow out of int type
typedef long long llong;

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
typedef pair<llong, int> QElem;
typedef vector<priority_queue<QElem, vector<QElem>, greater<QElem>>> Queue;

namespace Adv {

	class Bidijkstra {
		// Number of nodes
		int n_;
		// Graph adj_[0] and cost_[0] correspond to the initial graph,
		// adj_[1] and cost_[1] correspond to the reversed graph.
		// Graphs are stored as vectors of adjacency lists corresponding
		// to nodes.
		// Adjacency list itself is stored in adj_ with (Adj Vertex, Cost) pair.
		DoubleAdj adj_;
		// distance_[0] stores distances for the forward search,
		// and distance_[1] stores distances for the backward search.
		vector<vector<llong>> distance_;
		// Stores all the nodes visited either by forward or backward search.
		vector<int> workset_;
		// Stores a flag for each node which is True iff the node was visited
		// either by forward or backward search.
		vector<bool> visited_;

	public:
		Bidijkstra(int, DoubleAdj);

		// Initialize the data structures before new query,
		// clear the changes made by the previous query.
		void clear(); 

		// Processes visit of either forward or backward search 
		// (determined by value of side), to node v trying to
		// relax the current distance by dist.
		void visit(Queue&, int, int, llong);

		// Returns the distance from s to t in the graph.
		llong query(int, int); 
		string query(vector<pair<int, int>>);

		// Function that processes i.e. does a BFS on the priortised vertex
		void process(Queue&, int, int);

		// Finding the shortestpath 
		llong shortestpath();
	};

}

Adv::Bidijkstra::Bidijkstra(int n, DoubleAdj adj)
	: n_(n+1), adj_(adj), distance_(2, vector<llong>(n + 1, INF)), visited_(n + 1)
{
	workset_.reserve(n + 1);
}

void Adv::Bidijkstra::clear() {
	for (int i = 0; i < workset_.size(); ++i) {
		int v = workset_[i];
		distance_[0][v] = distance_[1][v] = INF;
		visited_[v] = false;
	}
	workset_.clear();
}

void Adv::Bidijkstra::visit(Queue& q, int side, int v, llong dist) {
	
	q[side].push(make_pair(dist,v));
	distance_[side][v] = dist;
	workset_.push_back(v);
}

llong Adv::Bidijkstra::shortestpath() {
	llong min = INF;
	for (int i = 0; i < workset_.size(); i++) {
		llong dist = distance_[0][workset_[i]] + distance_[1][workset_[i]];
		if (dist < min)
			min = dist;
	}
	return min == INF ? -1 : min;
}

llong Adv::Bidijkstra::query(int s, int t) {
	Queue q(2);
	clear();

	int Start = s;
	int End = t;

	visit(q, 0, Start, 0);
	visit(q, 1, End, 0);

	while (!q[0].empty() && !q[1].empty()){
		QElem FwdElem = q[0].top();
		q[0].pop();
		QElem BackElem = q[1].top();
		q[1].pop();

		// Fwd Dijkstra 
		process(q, 0, FwdElem.second);

		if (visited_[FwdElem.second])
			return shortestpath();
		visited_[FwdElem.second] = true;

		// Back Dijkstra 
		process(q, 1, BackElem.second);

		if (visited_[BackElem.second])
			return shortestpath();
		visited_[BackElem.second] = true;
	}

	return -1;
}

void Adv::Bidijkstra::process(Queue& q, int side, int iVertex) {
	for (int i = 0; i < adj_[side][iVertex].size(); i++) {
		int AdjVtx = adj_[side][iVertex][i].first;
		int AdjDist = adj_[side][iVertex][i].second;
		llong DistanceToBe = distance_[side][iVertex] + AdjDist;

		if (distance_[side][AdjVtx] > DistanceToBe)
			visit(q, side, AdjVtx, DistanceToBe);
	}
}

string Adv::Bidijkstra::query(vector<pair<int,int>> Queries) {
	vector<int> QueryResult(Queries.size(), -1);
	

	for (int i = 0; i < Queries.size(); i++) {
		int Start = Queries[i].first;
		int End = Queries[i].second;

		QueryResult[i] = query(Start, End);

	}

	string Str;
	for (int i = 0; i < QueryResult.size(); i++) {

		Str += std::to_string(QueryResult[i]);

		if (i < QueryResult.size()-1)
			Str += " ";
	}

	return Str;
}