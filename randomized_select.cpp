#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int comparisons = 0;

int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
        comparisons++;
    }

    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int randomizedSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return randomizedSelect(arr, left, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, right, k);
    }
}

int main() {
    srand(time(nullptr));

    for (int n = 30; n <= 1000; n += 10) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        comparisons = 0;
        int k = rand() % n;
        int result = randomizedSelect(arr, 0, n - 1, k);

        cout << "n = " << n << ", k = " << k << ", result = " << result << ", comparisons = " << comparisons << endl;
    }

    return 0;
}
