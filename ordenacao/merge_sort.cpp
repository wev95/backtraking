#include <iostream>
#include <vector>

using namespace std;

void mergeTheRestOfTheElements(vector<int>& N, vector<int>& partition, int& nPointer, int& partitionPointer, int sizePartition);
void mergeLeftAndRight(vector<int>& N, int& nPointer, int endN, vector<int> Left, int& leftPointer, int leftSize, vector<int> Right, int& rightPointer, int rightSize);
vector<int> subVector(vector<int> N, int start, int end, int rule);
vector<int> merge(vector<int> N, int p, int half, int r);
vector<int> mergeSort(vector<int> N, int start, int end);

void mergeTheRestOfTheElements(vector<int>& N, vector<int>& partition, int& nPointer, int& partitionPointer, int sizePartition) { 
     while (partitionPointer < sizePartition) {
        N[nPointer++] = partition[partitionPointer++];
    }
}

void mergeLeftAndRight(vector<int>& N, int& nPointer, int endN, vector<int> Left, int& leftPointer, int leftSize, vector<int> Right, int& rightPointer, int rightSize) {
    while (leftPointer < leftSize && rightPointer < rightSize && nPointer <= endN) {
        if (Left[leftPointer] <= Right[rightPointer]) {
            N[nPointer] = Left[leftPointer++];
        }
        else {
            N[nPointer] = Right[rightPointer++];
        }
        nPointer++;
    }
}

vector<int> subVector(vector<int> N, int start, int end, int rule) {
    vector<int> slice;

    for (int i = start; i <= end; i++) {
        slice.push_back(N[rule + i]);
    }

    return slice;
}

vector<int> merge(vector<int> N, int startN, int halfN, int endN) {

    int leftSize = halfN - startN + 1;
    int rightSize = endN - halfN;
    int leftPointer = 0, rightPointer = 0;

    vector<int> Left = subVector(N, 1, leftSize, startN - 1);
    vector<int> Right = subVector(N, 1, rightSize, halfN);

    int nPointer = startN;

    mergeLeftAndRight(N, nPointer, endN, Left, leftPointer, leftSize, Right, rightPointer, rightSize);
    mergeTheRestOfTheElements(N, Left, nPointer, leftPointer, leftSize);
    mergeTheRestOfTheElements(N, Right, nPointer, rightPointer, rightSize);

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

int main() {
    vector<int> list = { 16, 12071, 2, 77, -1, 40, 5, 10, 37 };
    int size = list.size() - 1;
    vector<int> result = mergeSort(list, 0, size);

    for (int n = 0; n <= size; ++n)
        printf("%d ", result[n]);

    return 0;
}