#include "heap.h"

HeapSort::HeapSort(vector<int>& inputVec): Heap(inputVec) {};

void HeapSort::heapSort()
{
    buildMaxHeap();
    for(int i = arrayLength - 1; i > 0; i--)
    {
        swap(A[0], A[i]);
        heapSize -= 1;
        maxHeapify(0);
    }
}