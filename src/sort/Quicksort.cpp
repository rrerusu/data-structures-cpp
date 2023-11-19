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

    return swapPos;
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
    return swapPos;
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

// Hoare partition style, 3x fewer swaps
int hoarePartition(int intArr[], int begin, int end) {
    // int pivot = intArr[begin];
    // int i = begin;
    // int j = end;

    // while(true) {
    //     while(intArr[i] < pivot)
    //         i++;
    //     while(intArr[j] > pivot)
    //         j--;

    //     if(i >= j)
    //         return j;
        
    //     swap(intArr[i], intArr[j]);
    // }

    // modification that seems to work, will need testing
    // int pivot = intArr[begin];
    // int i = begin, j = end;

    // while(i < j) {
    //     while(intArr[i] < pivot)
    //         i++;
    //     while(intArr[j] > pivot)
    //         j--;
        
    //     swap(intArr[i], intArr[j]);
    // }

    // First two don't work when there are duplicate values.  This solves the issue
    int pivot = intArr[begin];
    int i = begin;
    int j = end;

    while(true) {
        while(intArr[i] < pivot)
            i++;
        while(intArr[j] > pivot)
            j--;

        if(i >= j)
            return j;
        
        swap(intArr[i], intArr[j]);

        // Seems to work with only either condition, don't need both
        if(intArr[j] == pivot)
            i++;
        else if(intArr[i] == pivot)
            j--;
    }

    return j;
}

void quicksort(int *myArray, int start, int end) {
    if(start < end) {
        // int pivot = endPartition(myArray, start, end);
        // int pivot = beginPartition(myArray, start, end);
        // int pivot = middlePartition(myArray, start, end);
        int pivot = endPartition(myArray, start, end);
        // quicksort(myArray, start, pivot - 1);
        quicksort(myArray, start, pivot - 1);               // Modification for Hoare's partition
        quicksort(myArray, pivot + 1, end);
    }
}

int main() {
    int myArray[] = {4, 3, 6, 1, 2, 5, 0, 9, 8, 7};

    quicksort(myArray, 0, 9);

    print(myArray, 10);

    return EXIT_SUCCESS;
}