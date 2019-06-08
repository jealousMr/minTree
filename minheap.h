#ifndef MINHEAP_H
#define MINHEAP_H
#include"edgenode.h"

//最小堆对边进行排序

class MinHeap
{
public:
    MinHeap(int ms);
    ~MinHeap();
    int size();
    MinHeap& Insert(EdgeNode& x);
    MinHeap& Delete(EdgeNode& x);
    EdgeNode head();
private:
    EdgeNode *heap;
    int MaxSize;
    int CurrentSize;
};

#endif // MINHEAP_H
