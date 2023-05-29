#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// AdjacencyList Class
class AdjacencyList 
{
private:
    int size;                           // AdjacencyList size
    vector<list<pair<int, int>>> Adj;   // AdjacencyList

public:
    AdjacencyList() {};
    AdjacencyList(int v);                   // size�� �ް� vector resize�ϴ� ������
    void setSize(int v);                    // ��������Ʈ�� ����� �����ϴ� �Լ�
    void addEdge(int u, int v, int w);      // Edge�� �߰��ϴ� �Լ�
    int getSize();                          // size�� ��ȯ�ϴ� �Լ�
    list<pair<int, int>> getList(int v);    // ��������Ʈ�� ��ȯ�ϴ� �Լ�
};

#endif // ADJACENCYLIST_H