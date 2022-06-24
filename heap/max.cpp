#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& N, int i, int j);
int left(int i);
int right(int i);
vector<int> buildHeap(vector<int> N, int i, int size);
vector<int> maxHeap(vector<int> N, int i, int size);

int main() {
    vector<int> list = { -1, 16, 12071, 2, 77, -1, 40, 5, 10,  37 }; // ignore list[0]
    //vector<int> list = {-1, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = list.size() - 1;
    int i = size / 2;
    list = buildHeap(list, i, size);
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

vector<int> buildHeap(vector<int> N, int i, int size) {

    vector<int> ass;
    while (i > 0) {
        N = maxHeap(N, i, size);
        i--;
    }
    return N;
}