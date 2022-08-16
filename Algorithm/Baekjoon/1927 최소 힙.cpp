#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <regex>

#define HEAP_SIZE 100001

using namespace std;

typedef struct
{
    int key;
} element;

typedef struct
{
    element heap[HEAP_SIZE];
    int heap_size;
} HeapType;

void insert_min_heap(HeapType* h, element item)
{
    int i = ++(h->heap_size);

    while ((i != 1) && (h->heap[i / 2].key > item.key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

element delete_min_heap(HeapType* h)
{
    element item = h->heap[1];
    element temp = h->heap[h->heap_size--];
    int parent = 1;
    int child = 2;

    while (child <= h->heap_size)
    {
        if ((child < h->heap_size) && (h->heap[child].key > h->heap[child + 1].key))
        {
            child++;
        }

        if (temp.key <= h->heap[child].key)
        {
            break;
        }

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}

int main()
{
    HeapType Heap;
    Heap.heap_size = 0;

    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp == 0)
        {
            if (Heap.heap_size == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", delete_min_heap(&Heap).key);
            }
        }
        else
        {
            insert_min_heap(&Heap, element{ temp });
        }
    }

    return 0;
}