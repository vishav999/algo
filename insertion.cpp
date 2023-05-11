#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int insertionSort(int arr[], int n) {
    int i, key, j, count = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            count++;
        }
        arr[j + 1] = key;
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
        int comparisons = insertionSort(arr, n);
        cout << "Number of comparisons for input size " << n << ": " << comparisons << endl;
    }
    return 0;
}