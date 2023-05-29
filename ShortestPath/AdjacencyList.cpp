#include "AdjacencyList.h"

// size�� �ް� vector resize�ϴ� ������
AdjacencyList::AdjacencyList(int size)
{
    this->size = size; // size ����

    // vector resize
    Adj.resize(size);
}

// ��������Ʈ�� ����� �����ϴ� �Լ�
void AdjacencyList::setSize(int size) 
{
    this->size = size; // size ����

    // vector resize
    Adj.resize(size);
}

// Edge�� �߰��ϴ� �Լ�
void AdjacencyList::addEdge(int u, int v, int w) 
{
    // Edge �߰�
    pair<int, int> temp;
    temp.first = v;
    temp.second = w;

    Adj[u].push_back(temp);
}

// size�� ��ȯ�ϴ� �Լ�
int AdjacencyList::getSize()
{
    return size; // size ��ȯ
}

// ��������Ʈ�� ��ȯ�ϴ� �Լ�
list<pair<int, int>> AdjacencyList::getList(int v)
{
    return Adj[v];
}