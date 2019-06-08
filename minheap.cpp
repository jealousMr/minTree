#include "minheap.h"
#include"edgenode.h"


MinHeap::MinHeap(int ms)
{
    MaxSize = ms;
    CurrentSize = 0;
    heap = new EdgeNode[MaxSize + 1];
}

MinHeap::~MinHeap()
{
    delete[]heap;
}

MinHeap& MinHeap::Insert(EdgeNode& x)
{
    if (CurrentSize == MaxSize)
                throw"error";
            int i = ++CurrentSize;
            while (i!=1)
            {
                if (heap[i / 2] <= x)
                    break;
                heap[i] = heap[i / 2];
                i /= 2;
            }
            heap[i] = x;
            return *this;
}

MinHeap& MinHeap::Delete(EdgeNode &x)
{
    if (CurrentSize == 0)
                throw"error";
            x = heap[1];
            int i = 1, ci = 2;
            EdgeNode y = heap[CurrentSize--];
            while (ci<=CurrentSize)
            {
                if (ci<CurrentSize && heap[ci]>heap[ci + 1])
                    ci++;
                if (heap[ci] >= y)
                    break;
                heap[i] = heap[ci];
                i = ci;
                ci *= 2;
            }
            heap[i] = y;
            return *this;
}

EdgeNode MinHeap::head()
{
    return heap[1];
}
