#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <memory.h>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;

        multiset<int> mset;

        for (int i = 0; i < K; i++)
        {
            string command;
            cin >> command;

            if (command == "I")
            {
                int temp;
                cin >> temp;

                mset.insert(temp);
            }
            else if (command == "D")
            {
                int temp;
                cin >> temp;

                if (temp == 1 && mset.size() != 0)
                {
                    mset.erase(--mset.end());
                }
                else if (temp == -1 && mset.size() != 0)
                {
                    mset.erase(mset.begin());
                }
            }
        }

        if (mset.size() == 0)
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << *--mset.end() << " " << *mset.begin() << " " << '\n';
        }

    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <memory.h>
#include <unordered_map>

#define HEAP_SIZE 1000001

using namespace std;

typedef struct
{
    int key;
} element;

typedef struct
{
    element* heap;
    // element heap[HEAP_SIZE];
    int heap_size;
    int min_index;
} HeapType;

void insert_max_heap(HeapType* h, element item)
{
    int i = ++(h->heap_size);

    // int min_index_temp = h->mini_index;
    while (i != 1 && h->heap[i / 2].key < item.key)
    {
        if (i / 2 == h->min_index)
        {
            h->min_index *= 2;
        }
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;

    // cout << "h->min_index: " << h->min_index << endl;
    // cout << "heap min: " << h->heap[h->min_index].key << " item key: " << item.key << endl;
    if (h->heap_size == 1)
    {
        h->min_index = i;
    }
    else
    {
        if (h->heap[h->min_index].key > item.key)
        {
            h->min_index = i;
        }
    }
    // cout << "h->min_index: " << h->min_index << endl;
    // cout << "heap min: " << h->heap[h->min_index].key << " item key: " << item.key << endl;
}

element delete_max_heap(HeapType* h)
{
    element item = h->heap[1];
    element temp = h->heap[h->heap_size--];
    int parent = 1;
    int child = 2;

    bool flag = false;
    if (h->heap_size + 1 == h->min_index)
    {
        flag = true;
    }

    while (child <= h->heap_size)
    {
        if (child < h->heap_size && h->heap[child].key < h->heap[child + 1].key)
        {
            child++;
        }

        if (h->heap[child].key <= temp.key)
        {
            break;
        }

        h->heap[parent] = h->heap[child];
        if (h->min_index == child && flag == false)
        {
            h->min_index = parent;
        }
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;

    if (flag == true)
    {
        h->min_index = parent;
    }

    /*h->min_index = 1;
    for (int i = 1; i <= h->heap_size; i++)
    {
        if (h->heap[h->min_index].key > h->heap[i].key)
        {
            h->min_index = i;
        }
    }*/
    // cout << "h->min_index: " << h->min_index << endl;

    return item;
}

element delete_min_index_element(HeapType* h)
{
    if (h->min_index == h->heap_size)
    {
        // 로그 heap_size에서 부터 heap_size까지
        if (pow(2, (int)log2(h->heap_size) == h->heap_size))
        {
            h->min_index = pow(2, (int)log2(h->heap_size) - 1);
            for (int i = pow(2, (int)log2(h->heap_size) - 1); i < h->heap_size - 1; i++)
            {
                if (h->heap[h->min_index].key > h->heap[i].key)
                {
                    h->min_index = i;
                }
            }
        }
        else
        {
            h->min_index = pow(2, (int)log2(h->heap_size));
            for (int i = (h->min_index); i < h->heap_size; i++)
            {
                if (h->heap[h->min_index].key > h->heap[i].key)
                {
                    h->min_index = i;
                }
            }
        }

        // cout << "h->min_index: " << h->min_index << endl;

        return h->heap[h->heap_size--];
    }

    element item = h->heap[h->min_index];
    int temp = h->min_index;
    // h->heap[h->min_index] = h->heap[h->heap_size--];

    // 마지막 node와 min_index의 부모 노드와 비교
    // 마지막 노드가 크다면 min_index자리에 부모 노드를 삽입
    // 다시 min_index의 부모 노드의 부모 노드와 마지막 노드를 비교
    int parent = temp / 2;
    while (parent > 0)
    {
        if (h->heap[h->heap_size].key > h->heap[parent].key)
        {
            h->heap[temp] = h->heap[parent];
        }
        else
        {
            h->heap[temp] = h->heap[h->heap_size];
            break;
        }

        temp /= 2;
        parent = temp / 2;
    }
    h->heap_size--;

    h->min_index = 1;
    for (int i = 1; i <= h->heap_size; i++)
    {
        if (h->heap[h->min_index].key > h->heap[i].key)
        {
            h->min_index = i;
        }
    }

    // cout << "h->min_index: " << h->min_index << endl;

    return item;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;

        HeapType heap;
        heap.heap = new element[K];
        heap.heap_size = 0;
        heap.min_index = 0;

        for (int i = 0; i < K; i++)
        {
            string command;
            cin >> command;

            if (command == "I")
            {
                int temp;
                cin >> temp;

                insert_max_heap(&heap, element{ temp });

                /*cout << "heap: ";
                for (int i = 1; i <= heap.heap_size; i++)
                {
                    cout << heap.heap[i].key << " ";
                }
                cout << endl;*/
                // cout << "heap min: " << heap.heap[heap.min_index].key << endl;
            }
            else if (command == "D")
            {
                int temp;
                cin >> temp;

                if (temp == 1 && heap.heap_size > 0)
                {
                    delete_max_heap(&heap).key;
                    // cout << delete_max_heap(&heap).key << endl;

                    /*cout << "heap: ";
                    for (int i = 1; i <= heap.heap_size; i++)
                    {
                        cout << heap.heap[i].key << " ";
                    }
                    cout << endl;*/
                }
                else if (temp == -1 && heap.heap_size > 0)
                {
                    delete_min_index_element(&heap).key;
                    // cout << delete_min_index_element(&heap).key << endl;

                    /*cout << "heap: ";
                    for (int i = 1; i <= heap.heap_size; i++)
                    {
                        cout << heap.heap[i].key << " ";
                    }
                    cout << endl;*/
                }
            }
        }

        if (heap.heap_size == 0)
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << heap.heap[1].key << " " << heap.heap[heap.min_index].key << '\n';
        }
        delete[] heap.heap;
    }

    return 0;
}