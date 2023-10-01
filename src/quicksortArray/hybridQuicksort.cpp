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

// Insertion sort is good for smaller sizes, will make combo with quicksort and insertion sort
void insertionSort(int arr[], int begin, int n) {
    for(int i = 0; i <= n; i++) {
        int val = arr[i];
        int j = i;
        while(j > begin && arr[j - 1] > val) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = val;
    }
}

// Geeksforgeeks uses Lomuto partition, not sure why, but I built it to practice it
int endPartition(int arr[], int begin, int end) {
    int pivot = arr[end];
    int j = begin;

    for(int i = begin; i < end; i++) {
        if(arr[i] < pivot) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    swap(arr[j], arr[end]);
    return j;
}

// exciting stuff
void hybridQuicksort(int arr[], int begin, int end) {
    // while(begin < end) {
    //     if(end - begin + 1 < 10) {
    //         insertionSort(arr, begin, end);
    //         return ;
    //     } else {
    //         int pivot = endPartition(arr, begin, end);
    //         if(pivot - begin < end - pivot) {
    //             hybridQuicksort(arr, begin, pivot - 1);
    //             begin = pivot + 1;
    //         } else {
    //             hybridQuicksort(arr, pivot + 1, end);
    //             end = pivot - 1;
    //         }
    //     }
    // }

    // Else clause of Geeksforgeeks code uses less recursion, this is another way to write it
    if(begin < end) {
        if(end - begin + 1 < 10) {
            insertionSort(arr, begin, end);
            return ;
        } else {
            int pivot = endPartition(arr, begin, end);
            hybridQuicksort(arr, begin, pivot - 1);
            hybridQuicksort(arr, pivot + 1, end);
        }
    }
}

int main() {
    int intArr[] = {33, 14, 84, 73, 97, 49, 85, 70, 64, 46, 65, 30, 78, 69, 74, 95, 62, 42, 61, 54};

    hybridQuicksort(intArr, 0, 20);

    print(intArr, 20);

    return EXIT_SUCCESS;
}