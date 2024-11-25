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

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap adjacent elements
            }
        }
    }
}

int main() {
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    cout << "Bubble Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
