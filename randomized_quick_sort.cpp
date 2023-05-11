#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++;
        }
    }
    swap(arr[i + 1], arr[high]);
    comparisons++;
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high, int& comparisons) {
    int randomIndex = rand() % (high - low + 1) + low;
    swap(arr[randomIndex], arr[high]);
    comparisons++;
    return partition(arr, low, high, comparisons);
}

int quickSort(int arr[], int low, int high, int& comparisons) {
    int count = 0;
    if (low < high) {
        int p = randomizedPartition(arr, low, high, comparisons);
        quickSort(arr, low, p - 1, comparisons);
        quickSort(arr, p + 1, high, comparisons);
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
        int comparisons = 0;
        quickSort(arr, 0, n - 1, comparisons);
        cout << "Number of comparisons for input size " << n << ": " << comparisons << endl;
    }
    return 0;
}