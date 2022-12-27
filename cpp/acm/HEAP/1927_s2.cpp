#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int heap[100001];


void heap_insert(int& size, int value);
int heap_pop(int& size);

int main(void) {
    cout.tie(NULL);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int size = 0;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        /* heap insert */
        if (tmp > 0) {
            heap_insert(size, tmp);
        }
        /* heap pop */
        else {
            cout << heap_pop(size) << "\n";
        }
    }

    return 0;
}

void heap_insert(int& size, int value) {
    heap[size++] = value;

    int idx = size - 1;

    while (idx != 0) {
        int parent_idx = idx % 2 == 0 ? (idx - 1) / 2 : idx / 2;
        if (heap[parent_idx] > value) {
            heap[idx] = heap[parent_idx];
            idx = parent_idx;
        }
        else
            break;
    }

    heap[idx] = value;
}

int heap_pop(int& size) {

    if (size == 0)
        return 0;

    int retval = heap[0];

    int idx = 0;
    int value = heap[size - 1];
    heap[idx] = value;

    size --;

    while (true) {
        int l = idx * 2 + 1;
        int r = idx * 2 + 2;

        if (l >= size)
            break;

        else if (r >= size) {
            if (heap[l] < value) {
                heap[idx] = heap[l];
                idx = l;
            }
            else
                break;
        }
        else {
            int idx2 = (heap[l] < heap[r]) ? l : r;

            if (heap[idx2] < value) {
                heap[idx] = heap[idx2];
                idx = idx2;
            }
            else
                break;
        }

    }
    heap[idx] = value;

    return retval;
}