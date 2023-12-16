#include <iostream>
#include <chrono>

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

int partition(int arr[], int begin, int end, int *lp) {
    if(arr[begin] > arr[end])
        swap(arr[begin], arr[end]);
    
    int frontPivot = arr[begin], backPivot = arr[end];
    int frontSwap = begin + 1, backSwap = end - 1;
    int checkIndex = begin + 1;

    while(checkIndex <= backSwap) {
        // NOTE: not sure why the if statement to check infront of the pivot is
        // written twice...
        // // Current value is less than front pivot
        // if(arr[checkIndex] < frontPivot) {
        //     swap(arr[checkIndex], arr[frontSwap]);
        //     frontSwap++;
        // } 
        // // Current value is same or more than back pivot
        // else 
        // if(arr[checkIndex] >= backPivot) {
        //     while(arr[backSwap] > backPivot && checkIndex < backSwap)
        //         backSwap--;
        //     swap(arr[checkIndex], arr[backSwap]);
        //     backSwap--;
        //     if(arr[checkIndex] < frontPivot) {
        //         swap(arr[checkIndex], arr[frontSwap]);
        //         frontSwap++;
        //     }
        // }
        if(arr[checkIndex] >= backPivot) {
            while(arr[backSwap] >= backPivot && checkIndex < backSwap)
                backSwap--;
            swap(arr[checkIndex], arr[backSwap]);
            backSwap--;
        }
        if(arr[checkIndex] < frontPivot) {
            swap(arr[checkIndex], arr[frontSwap]);
            frontSwap++;
        }
        checkIndex++;
    }
    frontSwap--;
    backSwap++;
    swap(arr[begin], arr[frontSwap]);
    swap(arr[end], arr[backSwap]);

    *lp = frontSwap;
    return backSwap;
}

void dualPivotQuicksort(int arr[], int begin, int end) {
    if(begin < end) {
        // lp = left pivot, rp = right pivot
        int lp, rp;
        rp = partition(arr, begin, end, &lp);
        dualPivotQuicksort(arr, begin, lp - 1);
        dualPivotQuicksort(arr, lp + 1, rp - 1);
        dualPivotQuicksort(arr, rp + 1, end);
    }
}

int main() {
    int myArray[] = {33, 14, 84, 73, 97, 49, 85, 70, 64, 46, 65, 30, 78, 69, 74, 95, 62, 42, 61, 54};

    auto begin = std::chrono::high_resolution_clock::now();
    dualPivotQuicksort(myArray, 0, 19);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    print(myArray, 20);

    std::cout << "\nElapsed time: " << duration.count() << std::endl;

    return EXIT_SUCCESS;
}