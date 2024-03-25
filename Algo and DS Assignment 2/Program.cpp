#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Function to play a sound effect
//void playSoundEffect() {
//    PlaySound(TEXT("swap_sound.wav"), NULL, SND_FILENAME | SND_ASYNC);
//}

// Function to merge two subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Recursive function to perform merge sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    // Recursive calls for left and right halves
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted halves
    merge(arr, left, mid, right);

    // Print the current state of the array
    cout << "Current array state: ";
    for (int i = left; i <= right; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Seed for random number generation
    srand(time(nullptr));

    // Input array size
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Initialize and populate the array with random numbers
    vector<int> arr(n);
    cout << "Original array:" << endl;
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform merge sort
    cout << "Sorting steps:" << endl;
    mergeSort(arr, 0, n - 1);

    // Output sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
