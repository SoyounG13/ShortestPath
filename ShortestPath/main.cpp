#include <fstream>
#include <sstream>
#include <string>
#include <fstream>
#include "ShortestPath.h"

bool readSPFromFile(string fileName, ShortestPath& SP);

int main()
{
    // graph ���� �� �ؽ�Ʈ���Ͽ��� �ε�
    ShortestPath graph;
    if (!readSPFromFile("graph1.csv", graph))
        return 0;

    // graph���� 1�������� BFS ����
    graph.Dijkstra(0);
    cout << "----- graph Dijkstra print -----" << endl;
    for (int i = 1; i < graph.getSize(); i++)
        graph.PRINT(0, i);
}

// �ؽ�Ʈ ������ �а� Edge�� �߰��ϴ� �Լ�
bool readSPFromFile(string fileName, ShortestPath& SP)
{
    ifstream file(fileName);
    if (!file) 
    {
        cout << "Failed to open file: " << fileName << endl;
        return false;
    }

    string line;
    getline(file, line);
    int size = stoi(line);

    SP = ShortestPath(size);

    for (int i = 0; i < size; i++) {
        getline(file, line);
        stringstream ss(line);
        string cell;
        int j = 0;

        while (getline(ss, cell, ',')) 
        {
            if (stoi(cell) != 0)
                SP.addEdge(i, j, stoi(cell));
            j++;
        }
    }

    file.close();
    return true;
}