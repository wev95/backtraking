#include <iostream>

using namespace std;

void printA(int arg[], int length);

int const SIZE = 6;

int main() {
    int list[SIZE] = { 16, 12071, 2, 77, 40, 5};
    int i;

    for (i = 1; i <= SIZE - 1; i++) {

        int s = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > s) {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = s;
    }
    printA(list, SIZE);

    return 0;
}

void printA(int arg[], int length) {
    for (int n = 0; n < length; ++n)
        printf("%d ", arg[n]);
}
