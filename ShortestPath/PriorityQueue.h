#pragma once //중복 include 방지

#include <iostream> // 읽기 및 쓰기에 대한 헤더파일
#include <limits>	// INT_MIN을 불러오기 위한 헤더파일
#include <vector>
using namespace std; 

// 클래스 생성
class PriorityQueue
{
public:
	// functions
	void Insert(pair<int, int> p);		// 숫자 대입 후 Max Heap 유지
	void Output();						// 현재 heap을 출력
	void Delete(int index);				// 특정 index 요소를 맨 뒤로 보낸 후 Max Heap 유지
	int getSize();						// 현재 heap size를 리턴
	int ExtractMin();					// 최대값을 리턴하고 Max Heap 유지
	bool empty();
	void changeValue(int i, int key);

private:
	// variables
	vector<pair<int, int>> heap;	// main문에서 n을 대입하여 배열을 만드는 코드가 없으므로
						// 문제에서 제시한 크기를 대입하여 배열 생성

	// functions
	int LEFT(int i);						// i번째 노드의 왼쪽 자식 노드의 index 리턴
	int RIGHT(int i);						// i번째 노드의 왼쪽 자식 노드의 index 리턴
	int PARENT(int i);						// i번째 노드의 부모 노드의 index 리턴
	void MinHeapify(int i);					// 특정 노드를 Max Heap에 맞는 위치로 이동
	void HeapDecreaseKey(int i, int key);	// i번째 노드의 값을 key로 변경 후 Max Heap에 맞는 위치로 이동
	void MinHeapInsert(pair<int, int> p);   // key를 Max Heap에 추가 후 Max Heap 유지
	void MinHeapDelete(int i);				// i번째 노드를 삭제 후 Max Heap 유지
};