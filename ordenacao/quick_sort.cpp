#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& N, int i, int j);
int partition(vector<int>& N, int start,  int end);
void quickSort(vector<int>& N, int start, int end);

int main() {
    vector<int> list = { 16, 12071, 2, 77, -1, 40, 5, 10, 37 };
    int size = list.size() - 1;
    quickSort(list, 0, size);

    for (int n = 0; n <= size; ++n)
        printf("%d ", list[n]);

    return 0;
}

int partition(vector<int>& N, int start,  int end) {
    int pivot = N[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        
        if (N[j] <= pivot) {
            i++;
            swap(N, i, j);
        }
    }
    swap(N, i + 1, end);
    return i + 1;
}

void swap(vector<int>& N, int i, int j) {
    int swap = N[j];
    N[j] = N[i];
    N[i] = swap;
}

void quickSort(vector<int>& N, int start, int end) {

    if (start < end) {
        int q = partition(N, start, end);
        quickSort(N, start, q - 1);
        quickSort(N, q  + 1, end);
    }
}