#pragma once //�ߺ� include ����

#include <iostream> // �б� �� ���⿡ ���� �������
#include <limits>	// INT_MIN�� �ҷ����� ���� �������
#include <vector>
using namespace std; 

// Ŭ���� ����
class PriorityQueue
{
public:
	// functions
	void Insert(pair<int, int> p);		// ���� ���� �� Max Heap ����
	void Output();						// ���� heap�� ���
	void Delete(int index);				// Ư�� index ��Ҹ� �� �ڷ� ���� �� Max Heap ����
	int getSize();						// ���� heap size�� ����
	int ExtractMin();					// �ִ밪�� �����ϰ� Max Heap ����
	bool empty();
	void changeValue(int i, int key);

private:
	// variables
	vector<pair<int, int>> heap;	// main������ n�� �����Ͽ� �迭�� ����� �ڵ尡 �����Ƿ�
						// �������� ������ ũ�⸦ �����Ͽ� �迭 ����

	// functions
	int LEFT(int i);						// i��° ����� ���� �ڽ� ����� index ����
	int RIGHT(int i);						// i��° ����� ���� �ڽ� ����� index ����
	int PARENT(int i);						// i��° ����� �θ� ����� index ����
	void MinHeapify(int i);					// Ư�� ��带 Max Heap�� �´� ��ġ�� �̵�
	void HeapDecreaseKey(int i, int key);	// i��° ����� ���� key�� ���� �� Max Heap�� �´� ��ġ�� �̵�
	void MinHeapInsert(pair<int, int> p);   // key�� Max Heap�� �߰� �� Max Heap ����
	void MinHeapDelete(int i);				// i��° ��带 ���� �� Max Heap ����
};