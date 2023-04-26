#include"heap.h"

MaxPriorityQueue::MaxPriorityQueue(vector<int>& inputVec): Heap(inputVec) 
{
    buildMaxHeap();
};

int MaxPriorityQueue::heapMaximun()
{
    return A[0];
}

int MaxPriorityQueue::heapExtractMax()
{
    if(heapSize < 1)
    {
        cout<< "Heap Underflow";
        return -1;
    }
    int max = A[0];
    heapSize -= 1;
    A[0] = A[heapSize];
    maxHeapify(0);
    return max;
}

void MaxPriorityQueue::heapIncreaseKey(int i, int key)
{
    if(key < A[i])
    {
        cout<< "New key is smaller then current key";
        return;
    }
    A[i] = key;
    while (i > 0 && A[i] > A[PARENT(i)])
    {
        swap(A[i], A[PARENT(i)]);
        i = PARENT(i);
    } 
}

void MaxPriorityQueue::maxHeapInsert(int key)
{
    if(heapSize == arrayLength)
    {
        A.push_back(key);
        arrayLength += 1;
    }
    heapSize += 1;
    A[heapSize - 1] = INT16_MIN;
    heapIncreaseKey(heapSize - 1, key);
}