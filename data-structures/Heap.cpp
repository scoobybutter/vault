//
// Created by Haider Ali on 28/08/21.
//
#include<iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> arr;

    void heapifyDown(int i) {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int largest = i;
        if (l <= arr.size() && arr[l] > arr[largest]) {
            largest = l;
        }
        if (r < arr.size() && arr[r] > arr[largest]) {
            largest = r;
        }
        if (arr[largest] != arr[i]) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        if (i > 0 && arr[i] > arr[parent]) {
            swap(arr[i], arr[parent]);
            heapifyUp(parent);
        }
    }

    void buildMaxHeap() {
        for (int i = arr.size() / 2; i >= 0; i--) {
            heapifyDown(i);
        }
    }

public:

    MaxHeap(vector<int> arr) {
        this->arr = arr;
        buildMaxHeap();
    }

    int maximum() {
        return arr[0];
    }

    int extractMaximum() {
        int maximum = arr[0];
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapifyDown(0);
        return maximum;
    }

    void increaseValue(int pos, int value) {
        arr[pos] += value;
        heapifyUp(pos);
    }

    void decreaseValue(int pos, int value) {
        // Assuming negative values are not allowed
        if (arr[pos] > value) {
            arr[pos] -= value;
            heapifyDown(pos);
        }
    }

    void insertValue(int val) {
        arr.push_back(val);
        heapifyUp(arr.size() - 1);
    }
};


int main() {
    vector<int> arr = {22, 33, 11, 45, 7, 29};
    MaxHeap maxHeap(arr);
    cout << maxHeap.maximum() << "\n";
    maxHeap.insertValue(99);
    cout << maxHeap.maximum() << "\n";
    cout << maxHeap.extractMaximum() << "\n";
    cout << maxHeap.maximum() << "\n";
}
