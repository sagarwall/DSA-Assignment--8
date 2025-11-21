#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Heapify downward from index i
    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify upward after insert / increaseKey
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

public:
    // Insert a new key
    void insertKey(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Return maximum element
    int getMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    // Extract maximum element
    int extractMax() {
        if (heap.empty()) {
            cout << "Priority Queue is empty\n";
            return -1;
        }
        if (heap.size() == 1) {
            int maxVal = heap[0];
            heap.pop_back();
            return maxVal;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
        return root;
    }

    // Increase value at index to newVal
    void increaseKey(int i, int newVal) {
        if (i >= heap.size()) {
            cout << "Invalid index\n";
            return;
        }

        heap[i] = newVal;
        heapifyUp(i);  // correct position upward
    }

    // Delete key at index
    void deleteKey(int i) {
        increaseKey(i, INT_MAX); // raise to highest value
        extractMax();            // remove from top
    }

    // Print priority queue
    void printHeap() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.insertKey(15);
    pq.insertKey(10);
    pq.insertKey(30);
    pq.insertKey(40);
    pq.insertKey(5);

    cout << "Priority Queue (Heap): ";
    pq.printHeap();

    cout << "Maximum Element: " << pq.getMax() << endl;
    
    cout << "Extract Max: " << pq.extractMax() << endl;
    cout << "After Extracting Max: ";
    pq.printHeap();

    pq.increaseKey(2, 50);
    cout << "After Increasing Key at index 2 to 50: ";
    pq.printHeap();

    pq.deleteKey(1);
    cout << "After Deleting Key at index 1: ";
    pq.printHeap();

    return 0;
}
