#include "ShortestPath.h"

ShortestPath::ShortestPath(int size)
{
	this->size = size;

	AL.setSize(size);
	d.resize(size);
	p.resize(size);
}

void ShortestPath::addEdge(int u, int v, int w)
{
	AL.addEdge(u, v, w);
}

void ShortestPath::InitializeSingleSource(int s)
{
	for (int v = 0; v < size; v++)
	{
		d[v] = INT_MAX;
		p[v] = -1;
	}
	d[s] = 0;
}

void ShortestPath::Relax(int u, int v, int w)
{
	if (d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v] = u;
	}
}

void ShortestPath::Dijkstra(int s)
{
	InitializeSingleSource(s);

	pair<int, int> temp;
	for (int v = 0; v < size; v++)
	{
		temp.first = v;
		temp.second = d[v];
		PQ.Insert(temp);
	}

	while (!PQ.empty())
	{
		int u = PQ.ExtractMin();

		for (const auto& v : AL.getList(u))
		{
			Relax(u, v.first, v.second);
			PQ.changeValue(v.first, d[v.first]);
		}
	}
}

// path를 print하는 함수
bool ShortestPath::PRINTPATH(int s, int v)
{
	// 강의자료와 동일

	if (v == s)
	{
		cout << s + 1;
		return true; // path가 존재하다면 true 반환
	}
	else if (p[v] == -1)
	{
		cout << "no path from " << s + 1 << " to " << v + 1 << " exists" << endl;
		return false; // path가 없다면 false 반환
	}
	else
	{
		if (PRINTPATH(s, p[v]))
			cout << " -> " << v + 1;
	}
}

void ShortestPath::PRINT(int s, int v)
{
	if (PRINTPATH(s, v))                         // path 출력에 성공했다면
		cout << ": " << d[v] - d[s] << endl; // distance 출력
}

int ShortestPath::getSize()
{
	return size;
}