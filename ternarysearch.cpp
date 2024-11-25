#include <iostream>
using namespace std;

int ternarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3; // First division
        int mid2 = right - (right - left) / 3; // Second division

        if (arr[mid1] == target) return mid1; // Target found at mid1
        if (arr[mid2] == target) return mid2; // Target found at mid2

        if (target < arr[mid1]) {
            right = mid1 - 1; // Search in the left segment
        } else if (target > arr[mid2]) {
            left = mid2 + 1; // Search in the right segment
        } else {
            left = mid1 + 1; // Search in the middle segment
            right = mid2 - 1;
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = ternarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}



