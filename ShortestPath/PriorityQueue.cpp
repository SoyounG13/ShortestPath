#include "PriorityQueue.h" // 헤더파일 include

// heap에 숫자를 추가하고 Max Heap을 유지하는 함수
void PriorityQueue::Insert(pair<int, int> p)
{
	PriorityQueue::MinHeapInsert(p);
}

// 현재 heap을 요소를 출력하는 함수
void PriorityQueue::Output()
{
	for (const auto& i : heap) // heap.size()만큼 반복
		cout << i.second << ",";
	cout << endl;
}

// 특정 index의 요소를 삭제하고 Max Heap을 유지하는 함수
void PriorityQueue::Delete(int index)
{
	PriorityQueue::MinHeapDelete(index);
}

// 현재 heap의 size를 return하는 함수
int PriorityQueue::getSize()
{
	return heap.size();
}

// heap의 맨 위를 return하고 Max Heap을 유지
int PriorityQueue::ExtractMin()
{
	int min = heap[0].first;
	heap.front() = heap.back();
	heap.pop_back();
	PriorityQueue::MinHeapify(0);
	return min;
}

bool PriorityQueue::empty()
{
	if (heap.size() == 0)
		return true;
	return false;
}

// i번째 노드의 왼쪽 자식 노드를 return
int PriorityQueue::LEFT(int i)
{
	return 2 * i + 1;
}

// i번째 노드의 오른쪽 자식 노드를 return
int PriorityQueue::RIGHT(int i)
{
	return 2 * i + 2;
}

// i번째 노드의 부모 노드를 return
int PriorityQueue::PARENT(int i)
{
	return (i - 1) / 2;
}

// 특정 노드를 Max Heap에 맞는 위치로 이동
void PriorityQueue::MinHeapify(int i)
{
	int l = LEFT(i);	// 왼쪽 자식 노드 index
	int r = RIGHT(i);	// 오른쪽 자식 노드 index

	// i번째 노드, l번째 노드와 r번째 노드 중 가장 큰 값의 노드 index를 구함
	int smallest;
	if (heap.size() > 0 && l <= heap.size() - 1 && heap[l].second < heap[i].second)
		smallest = l;
	else
		smallest = i;
	if (heap.size() > 0 && r <= heap.size() - 1 && heap[r].second < heap[smallest].second)
		smallest = r;

	// 가장 큰 값의 노드 index가 l이나 r이면
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);		// 교환함
		PriorityQueue::MinHeapify(smallest);	// 교환된 자식 노드의 index로 재귀함수를 실행함
	}
}

// i번째 노드의 값을 key로 변경 후 Max Heap에 맞는 위치로 이동하는 함수
void PriorityQueue::HeapDecreaseKey(int i, int key)
{
	heap[i].second = key;
	while (i > 0 && heap[PARENT(i)].second > heap[i].second)
	{
		swap(heap[i], heap[PARENT(i)]);
		i = PARENT(i);
	}
}

// key를 Max Heap에 추가 후 Max Heap 유지하는 함수
void PriorityQueue::MinHeapInsert(pair<int, int> p)
{
	pair<int, int> temp;
	temp.first = p.first;
	temp.second = INT_MAX;
	heap.push_back(temp);
	HeapDecreaseKey(heap.size() - 1, p.second);
}

// i번째 노드를 삭제 후 Max Heap 유지하는 함수
void PriorityQueue::MinHeapDelete(int i)
{
	heap[i] = heap.back();
	heap.pop_back();
	MinHeapify(i);
}

void PriorityQueue::changeValue(int i, int key)
{
	for (int v = 0; v < heap.size(); v++)
		if (i == heap[v].first)
			HeapDecreaseKey(v, key);
}