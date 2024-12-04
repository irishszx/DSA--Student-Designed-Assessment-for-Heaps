#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int powerLevel) {
        heap.push_back(powerLevel);
        cout << "Adding artifact with power level " << powerLevel << " to the Max-Heap!" << endl;
        heapifyUp(heap.size() - 1);
        displayHeap();
    }

    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty! No artifact to delete." << endl;
            return;
        }
        cout << "Deleted artifact with power level " << heap[0] <<endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        displayHeap();
    }

    void heapify(vector<int>& arr) {
        heap = arr;
        int startIdx = (heap.size() / 2) - 1;
        for (int i = startIdx; i >= 0; i--) {
            heapifyDown(i);
        }
        cout << "Max-Heap after Heapify: ";
        displayHeap();
    }

    void displayHeap() {
        cout << "[ ";
        for (int power : heap) {
            cout << power << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    MaxHeap artifactHeap;

    // Task 1: Insert artifacts into the Max-Heap
    artifactHeap.insert(70);
    artifactHeap.insert(50);
    artifactHeap.insert(90);
    artifactHeap.insert(30);
    artifactHeap.insert(80);

    // Task 2: Delete the most powerful artifact
    artifactHeap.deleteRoot();

    // Task 3: Heapify a random array of artifacts
    vector<int> randomArtifacts = {30, 10, 50, 20, 40};
    cout << "Heapifying array: [30, 10, 50, 20, 40]" << endl;
    artifactHeap.heapify(randomArtifacts);

    return 0;
}
