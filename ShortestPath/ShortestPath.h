#pragma once

#include <limits>

#include "ShortestPath.h"
#include "AdjacencyList.h"
#include "PriorityQueue.h"

class ShortestPath
{
private:
	AdjacencyList AL;
	PriorityQueue PQ;

	int size;
	vector<int> d;
	vector<int> p;

public:
	ShortestPath() {};
	ShortestPath(int size);
	void addEdge(int u, int v, int w);
	void InitializeSingleSource(int s);
	void Relax(int u, int v, int w);
	void Dijkstra(int s);
	bool PRINTPATH(int s, int v);
	void PRINT(int s, int v);
	int getSize();
};