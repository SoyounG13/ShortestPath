#include "PriorityQueue.h" // ������� include

// heap�� ���ڸ� �߰��ϰ� Max Heap�� �����ϴ� �Լ�
void PriorityQueue::Insert(pair<int, int> p)
{
	PriorityQueue::MinHeapInsert(p);
}

// ���� heap�� ��Ҹ� ����ϴ� �Լ�
void PriorityQueue::Output()
{
	for (const auto& i : heap) // heap.size()��ŭ �ݺ�
		cout << i.second << ",";
	cout << endl;
}

// Ư�� index�� ��Ҹ� �����ϰ� Max Heap�� �����ϴ� �Լ�
void PriorityQueue::Delete(int index)
{
	PriorityQueue::MinHeapDelete(index);
}

// ���� heap�� size�� return�ϴ� �Լ�
int PriorityQueue::getSize()
{
	return heap.size();
}

// heap�� �� ���� return�ϰ� Max Heap�� ����
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

// i��° ����� ���� �ڽ� ��带 return
int PriorityQueue::LEFT(int i)
{
	return 2 * i + 1;
}

// i��° ����� ������ �ڽ� ��带 return
int PriorityQueue::RIGHT(int i)
{
	return 2 * i + 2;
}

// i��° ����� �θ� ��带 return
int PriorityQueue::PARENT(int i)
{
	return (i - 1) / 2;
}

// Ư�� ��带 Max Heap�� �´� ��ġ�� �̵�
void PriorityQueue::MinHeapify(int i)
{
	int l = LEFT(i);	// ���� �ڽ� ��� index
	int r = RIGHT(i);	// ������ �ڽ� ��� index

	// i��° ���, l��° ���� r��° ��� �� ���� ū ���� ��� index�� ����
	int smallest;
	if (heap.size() > 0 && l <= heap.size() - 1 && heap[l].second < heap[i].second)
		smallest = l;
	else
		smallest = i;
	if (heap.size() > 0 && r <= heap.size() - 1 && heap[r].second < heap[smallest].second)
		smallest = r;

	// ���� ū ���� ��� index�� l�̳� r�̸�
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);		// ��ȯ��
		PriorityQueue::MinHeapify(smallest);	// ��ȯ�� �ڽ� ����� index�� ����Լ��� ������
	}
}

// i��° ����� ���� key�� ���� �� Max Heap�� �´� ��ġ�� �̵��ϴ� �Լ�
void PriorityQueue::HeapDecreaseKey(int i, int key)
{
	heap[i].second = key;
	while (i > 0 && heap[PARENT(i)].second > heap[i].second)
	{
		swap(heap[i], heap[PARENT(i)]);
		i = PARENT(i);
	}
}

// key�� Max Heap�� �߰� �� Max Heap �����ϴ� �Լ�
void PriorityQueue::MinHeapInsert(pair<int, int> p)
{
	pair<int, int> temp;
	temp.first = p.first;
	temp.second = INT_MAX;
	heap.push_back(temp);
	HeapDecreaseKey(heap.size() - 1, p.second);
}

// i��° ��带 ���� �� Max Heap �����ϴ� �Լ�
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