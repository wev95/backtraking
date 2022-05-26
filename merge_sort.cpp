#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> N, int p, int half, int r);
vector<int> mergeSort(vector<int> N, int start, int end);

int main() {
    vector<int> list = { 16, 12071, 2, 77, -1, 40, 5, 10, 37 };
    int size = list.size() - 1;
    vector<int> resp = mergeSort(list, 0, size);

    for (int n = 0; n <= size; ++n)
        printf("%d ", resp[n]);

    return 0;
}

vector<int> merge(vector<int> N, int p, int half, int r) {

    vector<int> L, R; // L = Left e R = Right

    int Nl = half - p + 1, Nr = r - half; // tamanho dos pedaços de cada subLista
    int Pl = 0, Pr = 0; // ponteiros para andar por cada elemento das sublistas

    // popula a sublista L e R
    for (int i = 1; i <= Nl; i++) {
        L.push_back(N[p + i - 1]);
    }

    for (int i = 1; i <= Nr; i++) {
        R.push_back(N[half + i]);
    }

    // merge entre as sublistas
    int i = p; // ponteiro pra a lista principal

    while (Pl < Nl && Pr < Nr && i <= r) {
        if (L[Pl] <= R[Pr]) {
            N[i] = L[Pl++];
        }
        else {
            N[i] = R[Pr++];
        }
        i++;
    }

    while (Pl < Nl) {
        N[i++] = L[Pl++];
    }

    while (Pr < Nr) {
        N[i++] = R[Pr++];
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