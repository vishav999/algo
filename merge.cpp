#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int merge(int arr[], int l, int m, int r) {
    int i, j, k, count = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        count++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return count;
}

int mergeSort(int arr[], int l, int r) {
    int count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);
        count += merge(arr, l, m, r);
    }
    return count;
}

int main() {
    srand(time(NULL));
    for (int n = 30; n <= 1000; n += 10) {
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        int comparisons = mergeSort(arr, 0, n - 1);
        cout << "Number of comparisons for input size " << n << ": " << comparisons << endl;
    }
    return 0;
}