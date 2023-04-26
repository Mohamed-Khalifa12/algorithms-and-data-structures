#include"heap.h"

MinPriorityQueue::MinPriorityQueue(vector<int>& inputVec): Heap(inputVec) 
{
    buildMinHeap();
};

int MinPriorityQueue::heapMinimun()
{
    return A[0];
}

int MinPriorityQueue::heapExtractMin()
{
    if(heapSize < 1)
    {
        cout<< "Heap Underflow";
        return -1;
    }
    int min = A[0];
    heapSize -= 1;
    A[0] = A[heapSize];
    minHeapify(0);
    return min;
}

void MinPriorityQueue::heapDecreaseKey(int i, int key)
{
    if(key > A[i])
    {
        cout<< "New key is greater then current key";
        return;
    }
    A[i] = key;
    while (i > 0 && A[i] < A[PARENT(i)])
    {
        swap(A[i], A[PARENT(i)]);
        i = PARENT(i);
    } 
}

void MinPriorityQueue::minHeapInsert(int key)
{
    if(heapSize == arrayLength)
    {
        A.push_back(key);
        arrayLength += 1;
    }
    heapSize += 1;
    A[heapSize - 1] = INT16_MAX;
    heapDecreaseKey(heapSize - 1, key);
}

