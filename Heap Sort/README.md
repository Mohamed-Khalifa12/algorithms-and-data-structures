# Introduction
In this repo, we will learn about the following topics related to heaps:

What is a heap?
why do we need use heap ? and What are the different types of heaps?
How to implement a heap ?
How to use heaps in different algorithms [heapsort - max priority queue - min priority queue].

A heap is a specialized tree-based data structure which is essentially an almost complete binary tree that satisfies the heap property: in a max heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C. In a min heap, the key of P is less than or equal to the key of C. The node at the "top" of the heap (with no parents) is called the root node.

The heap is one maximally efficient implementation of an abstract data type called a priority queue, and in fact, priority queues are often referred to as "heaps", regardless of how they may be implemented. In a heap, the highest (or lowest) priority element is always stored at the root. However, a heap is not a sorted structure; it can be regarded as being partially ordered. A heap is a useful data structure when it is necessary to repeatedly remove the object with the highest (or lowest) priority, or when insertions need to be interspersed with removals of the root node.

<h1 align="center">How to impelemet a heap</h1>

## 1. Get the left, right and parent nodes
At first, we need to know the left and right and the parent of any node. This is because the heap is a complete binary tree, and the parent, left, and right children of any node can be calculated using its index in the array.

- The parent of a node with index `i` is at index `(i-1)/2`.
- The left child of a node with index `i` is at index `2*i+1`.
- The right child of a node with index `i` is at index `2*i+2`.

For example, in the following heap, the parent of node 3 is node 1, the left child of node 3 is node 5, and the right child of node 3 is node 7.
```
1
/ \
2   3
/ \ / \
4   5   7
```

A good implementation of these procedure as "macros" like what I have done in the header file.
#### pseudocode of these procedure
```
PARENT(i)
    retutn (i-1)/2
``` 

```
LEFT(i)
    return 2*i + 1
```
```
RIGHT(i)
    return 2*i + 2
```

all of these procedure will take a const time `O(1)`

## 2. Maintaining the heap property
The second thing is to maintain the heap property. The heap property is a property that all nodes in a heap must satisfy. In a max heap, the heap property is that the key of each node must be greater than or equal to the keys of its children. In a min heap, the heap property is that the key of each node must be less than or equal to the keys of its children.

There are a few different ways to maintain the heap property. One way is to use the heapify algorithm(`MAX-HEAPIFY` - `MIN-HEAPIFY`). The heapify algorithm is a recursive algorithm that takes a node as input and ensures that the heap property is satisfied for that node and its subtrees.

The heap property is important because it ensures that the heap is always in a valid state. This makes it easy to perform operations on heaps, such as inserting and removing elements.

#### pseudocode of these procedure
```
MAX-HEAPIFY(A,i)
    l = LEFT(i)
    r = RIGHT(i)
    if l < A.heap-size and A[l] > A[i]
        largest = l
    else    largest = i
    if r < A.heap-size and A[r] > A[largest]
        largest = r
    if largest != i
        swap A[i] with A[largest]
        MAX-HEAPIFY(A, largest)
```
The heapify algorithm has a time complexity of O(log n), where n is the number of elements in the heap.

## 3. Building a heap
We can use the procedure `MAX-HEAPIFY` in a bottom-up manner to convert an array A[1..n]. to a max heap.
#### pseudocode of these procedure
```
BUILD-MAX-HEAP(A)
    A.heap-size = A.lenght
    for i = A.length / 2 - 1 downto 0
        MAX-HEAPIFY(A, i)
```
because of `MAX-HEAPIFY` will be implemented just once the time complexity for this procedure will be linear O(n). [from bottom it will create from the subtree a heap till the root which will check only for the root and it's children due to both of them will be max heap].

**Note: `MIN-HEAPIFY` and `BUILD-MIN-HEAP` are exactly the same you can find the implementation directly from the code.**

>We can consider the heap as a base class, and then inherit from it to create the HeapSort, MaxPriorityQueue, and MinPriorityQueue classes. This will add a level of abstraction, and make it easier to use these data structures.

The HeapSort class will be responsible for sorting an array using the heap sort algorithm. The MaxPriorityQueue class will be responsible for creating a priority queue that sorts elements in descending order. The MinPriorityQueue class will be responsible for creating a priority queue that sorts elements in ascending order.

All of these classes will inherit from the Heap class, which will provide them with the basic functionality of a heap. This will make it easier to implement these classes, and will also make them more reusable. 

## 4.  The heapsort algorithm
The heapsort algorithm starts by using `BUILD-MAX-HEAP` to build a max-heap on the input array `A[1..n]`, where `n = A.length`. since the max element in the array is stored at `A[0]`. we can put it into the correct position by exchanging it with `A[n]` and reduce the heap-size by 1. but now the root maybe violate the max-heap property so we apply `MAX-HEAPIFY` on `A[0]` to be a max-heap again. and then apply it again to the children of the root.
#### pseudocode of these procedure
```
HEAPSORT(A)
    BUILD-MAX-HEAP(A)
    for i = A.length - 1 downto 1
        swap A[1] with A[i]
        A.heap-size = A.heap-size - 1
        MAX-HEAPIFY(A,0)
```
The time complexity of heap sort is O(n log n). This is because the heap sort algorithm has two main steps:

- Building the heap: This step has a time complexity of O(n).
- Sorting the heap: This step has a time complexity of O(n log n).

The first step, building the heap, takes O(n) time because we need to iterate over all of the elements in the array and call the heapify algorithm on each element. The second step, sorting the heap, takes O(n log n) time because we need to repeatedly remove the root element from the heap and then heapify the remaining elements.

The total time complexity of heap sort is O(n log n) because the two steps are independent of each other.

**Note: Heapsort is the first derived class of the heap because it is the first algorithm that uses the heap data structure.**

## 5. Priority queues
A priority queue is a data structure that stores elements in a way that allows them to be retrieved in sorted order, according to their priorities. The priority of an element is a value that indicates how important it is. Elements with higher priorities are retrieved before elements with lower priorities.

Priority queues are important because they allow us to quickly retrieve the most important elements in a collection. This is useful for a variety of applications, such as:

* Task scheduling: Priority queues can be used to schedule tasks in a way that ensures that the most important tasks are completed first.
* Event handling: Priority queues can be used to handle events in a way that ensures that the most important events are handled first.
* Routing: Priority queues can be used to route packets in a network in a way that ensures that the most important packets are routed first.
* Log management: Priority queues can be used to manage logs in a way that ensures that the most important logs are processed first.

Priority queues are a powerful data structure that can be used to solve a variety of problems. They are efficient and easy to use, making them a good choice for a variety of applications.

A `MaxPriorityQueue` supports the following operations:
* HEAP-MAXIMUN(A)
* HEAP-EXTRACT-MAXIMUM(A)
* HEAP-INCREASE-KEY(a, i, key)
* MAX-HEAP-INSERT(A, x)

A `MinPriorityQueue` supports the following operations:
* HEAP-MINIMUM(A)
* HEAP-EXTRACT-MINIMUM(A)
* HEAP-DECREASE-KEY(a, i, key)
* MIN-HEAP-INSERT(A, x)

**Note: We will explain `MaxPriorityQueue` and `MinPriorityQueue` will be the same and the implementation exists.**

```
HEAP-MAXIMUM(A)
    return A[0]
```
The time complexity for get the max element of max-heap is const time ==>  O(1)

```
HEAP-EXTRACT-MAX(A)
    if A.heap-size < 1
        error "heap underflow"
    max = A[0]
    A[0] = A[A.heap-size - 1]
    A.heap-size = A.heap-size - 1
    MAX-HEAPIFY(A,0)
    return max
```
The running time of `HEAP-EXTRACT-MAX` is O(lg n), since it performs only a constant amount of work on top of the O(lg n) time for MAX-HEAPIFY.

```
HEAP-INCREASE-KEY(A,i,key)
    if key < A[i]
        error "new key is smaller then current key"
    A[i] = key
    while i > 0 and A[PARENT(i)] < A[i]
        swap A[i] with A[PARENT(i)]
        i = PARENT(i)
``` 
The running time of HEAP-INCREASE-KEY on an n-element heap is O(lg n), since the path traced from the node updated to the root has length O(lg n).

```
MAX-HEAP-INSERT(A, key)
    if A.heap-size = A.array-length
        A.push_back(key)
        A.arrayLength = A.arrayLength + 1
    A.heap-size = A.heap-size + 1
    A[A.heap-size - 1] = -inf
    HEAP-INCREASE-KEY(A, A.heap-size -1, key)
```
The `MAX-HEAP-INSERT` on an n-element heap is O(lg n).

>In summary, a heap can support any priorty queue operation on a set of size n in O(lg n) time.

**Note: MaxPriorityQuere is the second derived class of the heap because it is the second algorithm that uses the heap data structure. and MinPriorityQueue is the third one**

## Summary
A heap is a specialized tree-based data structure that satisfies the heap property. In a max heap, for any given node C, if P is a parent node of C, then the key (the value) of P is greater than or equal to the key of C. In a min heap, the key of P is less than or equal to the key of C.

The heap is one maximally efficient implementation of an abstract data type called a priority queue, and in fact, priority queues are often referred to as "heaps", regardless of how they may be implemented. In a heap, the highest (or lowest) priority element is always stored at the root. However, a heap is not a sorted structure; it can be regarded as being partially ordered. A heap is a useful data structure when it is necessary to repeatedly remove the object with the highest (or lowest) priority, or when insertions need to be interspersed with removals of the root node.

There are three main applications of the heap data structure:
1. Heapsort: Heapsort is a very efficient sorting algorithm that works by first building a heap from the elements to be sorted. Once the heap is built, the root element of the heap is removed and placed at the end of the array. The heap is then rebuilt, and the process is repeated until the entire array has been sorted.
2. Maximum priority queue: A maximum priority queue is a data structure that allows us to quickly retrieve the element with the highest priority in a collection.
3. Minimum priority queue: A minimum priority queue is a data structure that allows us to quickly retrieve the element with the lowest priority in a collection.

The heap data structure is a powerful data structure that can be used to solve a variety of problems. It is efficient and easy to use, making it a good choice for a variety of applications.

## References

* **Introduction to Algorithms**
    * Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein
    * The MIT Press, 2009
    * ISBN: 978-0-262-03384-8
    * [URL](https://mitpress.mit.edu/books/introduction-algorithms)
