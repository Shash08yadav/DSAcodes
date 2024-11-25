// Time Complexity:
// Best Case: 
// 𝑂
// (
// 𝑛
// )
// O(n) (Already sorted)
// Worst and Average Case: 
// 𝑂
// (
// 𝑛
// 2
// )
// O(n 
// 2
//  )
// Space Complexity: 
// 𝑂
// (
// 1
// )
// O(1) (In-place)

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Insertion Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
