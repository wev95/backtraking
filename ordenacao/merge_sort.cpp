#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> N, int p, int half, int r);
vector<int> mergeSort(vector<int> N, int start, int end);

int main() {
    vector<int> list = { 16, 12071, 2, 77, -1, 40, 5, 10, 37 };
    int size = list.size() - 1;
    vector<int> result = mergeSort(list, 0, size);

    for (int n = 0; n <= size; ++n)
        printf("%d ", result[n]);

    return 0;
}

vector<int> merge(vector<int> N, int startN, int halfN, int endN) {

    vector<int> Left, Right;

    int leftSize = halfN - startN + 1;
    int rightSize = endN - halfN;
    int leftPointer = 0, rightPointer = 0;

    for (int i = 1; i <= leftSize; i++) {
        Left.push_back(N[startN + i - 1]);
    }

    for (int i = 1; i <= rightSize; i++) {
        Right.push_back(N[halfN + i]);
    }

    int nPointer = startN;

    while (leftPointer < leftSize && rightPointer < rightSize && nPointer <= endN) {
        if (Left[leftPointer] <= Right[rightPointer]) {
            N[nPointer] = Left[leftPointer++];
        }
        else {
            N[nPointer] = Right[rightPointer++];
        }
        nPointer++;
    }

    while (leftPointer < leftSize) {
        N[nPointer++] = Left[leftPointer++];
    }

    while (rightPointer < rightSize) {
        N[nPointer++] = Right[rightPointer++];
    }

    return N;
}

vector<int> mergeSort(vector<int> N, int start, int end) {

    if (start >= end)
        return N;
    else {
        int half = (start + end) / 2;
        vector<int> A = mergeSort(N, start, half);
        vector<int> B = mergeSort(A, half + 1, end);
        vector<int> mergeAB = merge(B, start, half, end);
        return mergeAB;
    }
}