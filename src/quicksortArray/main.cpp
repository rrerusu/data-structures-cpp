#include <iostream>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(int *_, int size) {
    std::cout << "Array contents:\n";
    for(int i = 0; i < size; i++) {
        std::cout << _[i] << " ";
    }
    std::cout << std::endl;
}

// Example from GeeksforGeeks
int endPartition(int *intArr, int begin, int end) {
    int swapPos = begin;
    int pivot = intArr[end];                          // end pivot

    for(int currentPos = begin; currentPos <= end - 1; currentPos++) {
        if(intArr[currentPos] < pivot) {
            swap(intArr[swapPos], intArr[currentPos]);
            swapPos++;
        }
    }
    swap(intArr[end], intArr[swapPos]);

    return pivot;
}

// Algorithm from endPartition but backwards (could've done middlePartition swap with pivot)
int beginPartition(int *intArr, int begin, int end) {
    int swapPos = end;
    int pivot = begin;

    for(int currentPos = end; currentPos >= begin + 1; currentPos--) {
        if(intArr[currentPos] > intArr[pivot]) {
            swap(intArr[currentPos], intArr[swapPos]);
            swapPos--;
        }
    }

    swap(intArr[swapPos], intArr[pivot]);
    return pivot;
}

/* 
    Algorithm from beginPartition (changes are getting pivot,
    swaping pivot and partition index if swapPos is pivot, and returning
    swapPos instead of pivot)
*/
int middlePartition(int intArr[], int begin, int end) {
    int swapPos = begin;
    int pivot = (end + 1 - begin) / 2 + begin;

    for(int currentPos = begin; currentPos <= end; currentPos++) {
        if(intArr[currentPos] < intArr[pivot]) {
            swap(intArr[swapPos], intArr[currentPos]);
            if(swapPos == pivot)
                pivot = currentPos;
            swapPos++;
        }
    }
    swap(intArr[swapPos], intArr[pivot]);

    return swapPos;
}

void quicksort(int *myArray, int start, int end) {
    if(start < end) {
        // int pivot = endPartition(myArray, start, end);
        // int pivot = beginPartition(myArray, start, end);
        int pivot = middlePartition(myArray, start, end);
        quicksort(myArray, start, pivot - 1);
        quicksort(myArray, pivot + 1, end);
    }
}

int main() {
    int myArray[] = {4, 3, 6, 5, 2, 8, 7, 9, 1, 0};

    quicksort(myArray, 0, 9);

    print(myArray, 10);

    return EXIT_SUCCESS;
}