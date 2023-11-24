#include <iostream>
#include <chrono>

void merge(int array[], int const left, int const mid, int const right) {
    // Subarrays
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int * leftArray = new int[subArrayOne], * rightArray = new int[subArrayTwo];

    for(int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for(int i = 0; i < subArrayTwo; i++)
        rightArray[i] = array[i + mid + 1];
    
    // Compare arrays, sort them
    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0, indexOfMergedArray = left;
    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Remaining elements must be larger than all values of other array
    // Only either while loop will trigger
    while(indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while(indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergesort(int array[], int const begin, int const end) {
    if(begin >= end)
        return;
    
    int mid = begin + (end - begin) / 2;
    mergesort(array, begin, mid);
    mergesort(array, mid + 1, end);
    // First pass: Once arrays are smallest, we come here
    merge(array, begin, mid, end);
}

void printArr(int arr[], int size) {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int intArr[] = {33, 14, 84, 73, 97, 49, 85, 70, 64, 46, 65, 30, 78, 69, 74, 95, 62, 42, 61, 54};

    auto start = std::chrono::high_resolution_clock::now();
    mergesort(intArr, 0, 19);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    printArr(intArr, 20);
    std::cout << "\nElapsed time: " << duration.count() << std::endl;

    return EXIT_SUCCESS;
}