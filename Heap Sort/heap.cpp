#include "heap.h"

Heap::Heap(vector<int>& inputVec): A(inputVec) 
{
    heapSize = arrayLength = inputVec.size();
};

void Heap::swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Heap::maxHeapify(int i)
{
    int largest;
    int l = LEFT(i);
    int r = RIGHT(i);
    if(l < heapSize && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if(r < heapSize && A[r] > A[largest])
        largest = r;
    if(largest != i)
    {
        swap(A[largest], A[i]);
        maxHeapify(largest);
    }
}

void Heap::minHeapify(int i)
{
    int smallest;
    int l = LEFT(i);
    int r = RIGHT(i);
    if(l < heapSize && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    if(r < heapSize && A[r] < A[smallest])
        smallest = r;
    if(smallest != i)
    {
        swap(A[smallest], A[i]);
        minHeapify(smallest);
    }
}

void Heap::buildMaxHeap()
{
    for(int i = heapSize/2 - 1; i >= 0; i--)
        maxHeapify(i);
}

void Heap::buildMinHeap()
{
    for(int i = heapSize/2 - 1; i >= 0; i--)
        minHeapify(i);
}

void Heap::printHeap()
{
    for(int i = 0; i < arrayLength; i++)
        cout<< A[i] << "\t";
}