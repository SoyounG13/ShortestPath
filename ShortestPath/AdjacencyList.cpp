#include "AdjacencyList.h"

// size를 받고 vector resize하는 생성자
AdjacencyList::AdjacencyList(int size)
{
    this->size = size; // size 저장

    // vector resize
    Adj.resize(size);
}

// 인접리스트의 사이즈를 설정하는 함수
void AdjacencyList::setSize(int size) 
{
    this->size = size; // size 저장

    // vector resize
    Adj.resize(size);
}

// Edge를 추가하는 함수
void AdjacencyList::addEdge(int u, int v, int w) 
{
    // Edge 추가
    pair<int, int> temp;
    temp.first = v;
    temp.second = w;

    Adj[u].push_back(temp);
}

// size를 반환하는 함수
int AdjacencyList::getSize()
{
    return size; // size 반환
}

// 인접리스트를 반환하는 함수
list<pair<int, int>> AdjacencyList::getList(int v)
{
    return Adj[v];
}