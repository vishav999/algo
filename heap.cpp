#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    comparisons++;

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    comparisons++;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    for (int n = 30; n <= 1000; n += 10) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        comparisons = 0;
        heapSort(arr);

        cout << "n = " << n << ", comparisons = " << comparisons << endl;
    }

    return 0;
}
