//
// Created by Haider Ali on 29/08/21.
//
#include<iostream>
#include <vector>

using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int partition(vector<int> &arr, int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(arr[high], arr[random]);
    int pivot = arr[high];
    int greaterElePos = low;
    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            swap(arr[greaterElePos], arr[i]);
            greaterElePos++;
        }
    }
    swap(arr[greaterElePos], arr[high]);
    return greaterElePos;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    vector<int> arr = {56, 2, 12, 99, 34, 13, 1, 97, 55, 49};
    printArray(arr);
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);
}