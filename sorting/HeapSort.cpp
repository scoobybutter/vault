//
// Created by Haider Ali on 28/08/21.
//
#include<iostream>
#include <vector>

using namespace std;


void maxHeapify(vector<int> &arr, int i, int size) {
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int largest = i;
    if (l <= size && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r <= size && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, size);
    }
}

void buildMaxHeap(vector<int> &arr) {
    for (int i = arr.size() / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, i, arr.size() - 1);
    }
}

void heapSort(vector<int> &arr) {
    buildMaxHeap(arr);
    int heap_size = arr.size() - 1;
    for (int i = heap_size; i > 0; i--) {
        swap(arr[i], arr[0]);
        heap_size--;
        maxHeapify(arr, 0, heap_size);
    }
}


int main() {
    vector<int> arr = {22, 33, 11, 45, 7, 29};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}
