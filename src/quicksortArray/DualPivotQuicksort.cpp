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
            while(arr[backSwap] > backPivot && checkIndex < backSwap)
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
    /* To remove below line, initialize frontSwap as begin 
       and increment before swapping in frontPivot check (see below) */
    frontSwap--;
    /* To remove below line, initialize backSwap as end,
       make backPivot check into do-while, and remove extra backSwap-- after swap (see below) */
    backSwap++;
    swap(arr[begin], arr[frontSwap]);
    swap(arr[end], arr[backSwap]);

    *lp = frontSwap;
    return backSwap;
}

int modifyPartition(int arr[], int begin, int end, int *lp) {
    if(arr[begin] > arr[end])
        swap(arr[begin], arr[end]);
    
    int frontPivot = arr[begin], backPivot = arr[end];
    int frontSwap = begin, backSwap = end;
    int checkIndex = begin + 1;

    while(checkIndex <= backSwap) {
        if(arr[checkIndex] >= backPivot) {
            do {
                backSwap--;
            } while(arr[backSwap] > backPivot && checkIndex < backSwap);
            swap(arr[checkIndex], arr[backSwap]);
        }
        if(arr[checkIndex] < frontPivot) {
            frontSwap++;
            swap(arr[checkIndex], arr[frontSwap]);
        }
        checkIndex++;
    }
    swap(arr[begin], arr[frontSwap]);
    swap(arr[end], arr[backSwap]);

    *lp = frontSwap;
    return backSwap;
}

void dualPivotQuicksort(int arr[], int begin, int end) {
    if(begin < end) {
        // lp = left pivot, rp = right pivot
        int lp, rp;
        // rp = partition(arr, begin, end, &lp);
        rp = modifyPartition(arr, begin, end, &lp);
        dualPivotQuicksort(arr, begin, lp - 1);
        dualPivotQuicksort(arr, lp + 1, rp - 1);
        dualPivotQuicksort(arr, rp + 1, end);
    }
}

int main() {
    int myArray[] = {4, 3, 6, 5, 2, 8, 0, 9, 1, 7};

    dualPivotQuicksort(myArray, 0, 9);

    print(myArray, 10);

    return EXIT_SUCCESS;
}