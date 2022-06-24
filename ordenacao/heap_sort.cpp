#include <iostream>
#include <vector>

using namespace std;

int left(int i);
int right(int i);
void swap(vector<int>& N, int i, int j);
vector<int> maxHeap(vector<int> N, int i, int size);
vector<int> heapSort(vector<int> N);
vector<int> BuildHeap(vector<int> N, int i, int size);

int main() {
    //vector<int> list = { -1, 16, 12071, 2, 77, -1, 40, 5, 10,  37 }; 
    vector<int> list = {-1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = list.size() - 1;
    int i = size / 2;
    list = heapSort(list);
    for (int n = 0; n <= size; ++n)
        printf("%d ", list[n]);
    return 0;
}

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return (2 * i) + 1;
}

void swap(vector<int>& N, int i, int j) {
    int swap = N[j];
    N[j] = N[i];
    N[i] = swap;
}

vector<int> heapSort(vector<int> N) {
    int i = N.size() - 1;
    vector<int> heap;
    heap = BuildHeap(N, i, i);

    while (i > 1) {
        swap(heap, 1, i);
        i--;
        heap = maxHeap(heap, 1, i); // sobe o maior elemento para primeira posição ignorando a última posição atual -1, pois era o maior valor que foi movido para o fim da lista
    }
    return heap;
}

vector<int> BuildHeap(vector<int> N, int i, int size) {
    while (i > 0) {
        N = maxHeap(N, i, size);
        i--;
    }
    return N;
}

vector<int> maxHeap(vector<int> N, int i, int size) {
    int l = left(i), r = right(i);
    int max = 0;
    if (l <= size && N[l] > N[i]) {
        max = l;
    }
    else {
        max = i;
    }

    if (r <= size && N[r] > N[max]) {
        max = r;
    }

    if (i != max) {
        swap(N, i, max);
        return maxHeap(N, max, size);
    }
    return N;
}