#include <iostream>

template <typename T>
void swap(T * val1, T * val2) {
    T temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

template <typename T>
void maxHeapify(T arr[], int size, int currentIndex) {
    int largest = currentIndex, left = 2 * currentIndex + 1, right = 2 * currentIndex + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;
    
    if(largest != currentIndex) {
        swap<int>(&arr[largest], &arr[currentIndex]);
        maxHeapify(arr, size, largest);
    }
}

template <typename T>
void buildMaxHeap(T arr[], int size) {
    int startIndex = size / 2 - 1;      // Last non-leaf node of binary tree
    for(int i = startIndex; i > -1; i--)
        maxHeapify<int>(arr, size, i);
}

template <typename T>
void minHeapify(T arr[], int size, int currentIndex) {
    int smallest = currentIndex, left = 2 * currentIndex + 1, right = 2 * currentIndex + 2;

    if(left < size && arr[left] < arr[smallest])
        smallest = left;
    if(right < size && arr[right] < arr[smallest])
        smallest = right;
    
    if(smallest != currentIndex) {
        swap<int>(&arr[smallest], &arr[currentIndex]);
        minHeapify(arr, size, smallest);
    }
}

template <typename T>
void buildMinHeap(T arr[], int size) {
    int startIndex = size / 2 - 1;      // Last non-leaf node of binary tree
    for(int i = startIndex; i > -1; i--)
        minHeapify<int>(arr, size, i);
}

template <typename T>
void printHeap(T arr[], int size) {
    for(int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
            std::cout << "\n";
}

int main() {
    int myArray[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int size = 11;

    std::cout << "Max Heap:\n";
    buildMaxHeap<int>(myArray, size);
    printHeap<int>(myArray, size);

    std::cout << "Min Heap:\n";
    buildMinHeap<int>(myArray, size);
    printHeap<int>(myArray, size);

    return EXIT_SUCCESS;
}