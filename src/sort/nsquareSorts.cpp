#include <iostream>

template <typename T> void swap(T * val1, T * val2) {
    T temp = * val1;
    * val1 = * val2;
    * val2 = temp;
}

void bubblesort(int arr[], int size) {
    bool didSwap;
    for(int currentVal = 0; currentVal < size; currentVal++) {
        didSwap = false;
        for(int checkVal = 0; checkVal < size - currentVal - 1; checkVal++) {
            if(arr[checkVal] > arr[checkVal + 1]) {
                swap<int>(&arr[checkVal], &arr[checkVal + 1]);
                didSwap = true;
            }
        }
        if(!didSwap)
            break;
    }
}

void insertionsort(int arr[], int size) {
    for(int currentIndex = 1; currentIndex < size; currentIndex++) {
        int key = arr[currentIndex];
        int leftIndex = currentIndex - 1;

        while(leftIndex >= 0 && arr[leftIndex] > key) {
            arr[leftIndex + 1] = arr[leftIndex];
            leftIndex--;
        }
        arr[leftIndex + 1] = key;
    }
}

void selectionsort(int arr[], int size) {
    for(int currentIndex = 0; currentIndex < size - 1; currentIndex++) {
        int minIndex = currentIndex;
        for(int nextIndex = currentIndex + 1; nextIndex < size; nextIndex++) {
            if(arr[nextIndex] < arr[minIndex])
                minIndex = nextIndex;
        }
        if(minIndex != currentIndex)
            swap<int>(&arr[minIndex], &arr[currentIndex]);
    }
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int myArray[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    selectionsort(myArray, 11);

    printArr(myArray, 11);

    return EXIT_SUCCESS;
}