#include "heap.h"

int main()
{
    vector<int> A = {10,1,12,1,13,4,7,8,0,23,14,12,5,9,40,5,6};
    MinPriorityQueue* mq = new MinPriorityQueue(A);
    //extract and get the max value
    cout<< "Min Value = " << mq->heapExtractMin() << "\n";
    cout<< "Next Min Value = " << mq->heapExtractMin() << "\n";
    cout<< "Next Min Value = " << mq->heapMinimun()<<"\n\n"; 

    //insert more than the extracted (The size of the array)
    mq->minHeapInsert(2);
    mq->minHeapInsert(3);
    mq->minHeapInsert(17);
    cout<< "After insert we will get the max value = " << mq->heapExtractMin() << "\n";
    cout<< "After insert we will get the max value = " << mq->heapExtractMin() << "\n";
    cout<< "After insert we will get the max value = " << mq->heapExtractMin()<<"\n"; 
    cout << "The next max = " << mq->heapMinimun();
    //Wow it works well :"D
}

/*
    ============= HEAP SORT TEST ===============
    HeapSort* h = new HeapSort(A);
    //before heap sort test
    h->printHeap();

    h->heapSort();
    cout<< "\n\n";

    //after heap sort test
    h->printHeap();
*/

/*
    =========== MAX PRIORITY QUEUE TEST =======================
    MaxPriorityQueue* mq = new MaxPriorityQueue(A);
    //extract and get the max value
    cout << "Max Value = " << mq->heapExtractMax() << "\n";
    cout<< "Next Max Value = " << mq->heapExtractMax() << "\n";
    cout<< "Next Max Value = " << mq->heapMaximun()<<"\n\n"; 
    //insert more than the extracted (The size of the array)
    mq->maxHeapInsert(41);
    mq->maxHeapInsert(42);
    mq->maxHeapInsert(45);
    cout<< "After insert we will get the max value = "<< mq->heapExtractMax()<< "\n";
    cout<< "After insert we will get the max value = "<< mq->heapExtractMax()<< "\n";
    cout<< "After insert we will get the max value = "<< mq->heapExtractMax()<< "\n";
    cout << "The next max = " << mq->heapMaximun();
    //Wow it works well :"D
*/