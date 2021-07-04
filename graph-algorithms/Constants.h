#pragma once
#include<limits>
#include<vector>
#include<map>
#include<queue>

using namespace std;


typedef long long llong;

typedef map<int, map<int, map< int, llong>>> DoubleAdjMapList;
typedef vector<vector<vector<pair<int, int>>>> DoubleAdj;
typedef vector<vector<pair<int, int>>> Adj;

typedef pair<llong, int> QElem;
typedef priority_queue<QElem, vector<QElem>, greater<QElem>> Q;

const llong INF = numeric_limits<llong>::max() / 4;