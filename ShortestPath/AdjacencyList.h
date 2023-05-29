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
    AdjacencyList(int v);                   // size를 받고 vector resize하는 생성자
    void setSize(int v);                    // 인접리스트의 사이즈를 설정하는 함수
    void addEdge(int u, int v, int w);      // Edge를 추가하는 함수
    int getSize();                          // size를 반환하는 함수
    list<pair<int, int>> getList(int v);    // 인접리스트를 반환하는 함수
};

#endif // ADJACENCYLIST_H