#ifndef HEAP_H
#define HEAP_H

#include<iostream>
#include<vector>

using namespace std;

#define LEFT(X) ((X*2) + 1)
#define RIGHT(X) ((X*2) + 2) 
#define PARENT(X) ((X - 1)/2)

//Base Class The Heap 
class Heap
{
public:
    vector<int>& A;
    int heapSize;
    int arrayLength;
    //Constructor 
    Heap(vector<int>& inputVec);
    //Methodes
    void maxHeapify(int i);
    void minHeapify(int i);
    void swap(int& a, int& b);
    void buildMaxHeap();
    void buildMinHeap();
    void printHeap();
};

//Derived classes from the heap [HeapSort, MaxPriorityQueue, MinPriorityQueue] ==> Apllication for the Heap
class HeapSort: public Heap
{
public:
    HeapSort(vector<int>& inputVec);
    void heapSort();
};

class MaxPriorityQueue: public Heap
{
public:
    MaxPriorityQueue(vector<int>& inputVec);
    int heapMaximun();
    int heapExtractMax();
    void heapIncreaseKey(int i, int key);
    void maxHeapInsert(int key);
};

class MinPriorityQueue: public Heap
{
public:
    MinPriorityQueue(vector<int>& inputVec);
    int heapMinimun();
    int heapExtractMin();
    void heapDecreaseKey(int i, int key);
    void minHeapInsert(int key);
};


#endif