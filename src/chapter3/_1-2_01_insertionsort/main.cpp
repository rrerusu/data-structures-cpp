#include <iostream>

void insertionsort(char * A, int n) {
    for(int i = 1; i < n; i++) {
        char curr = A[i];
        int j = i - 1;
        while((j >= 0) && (A[j] > curr)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = curr;
    }
}

template <typename T>
void printArr(T * arr, int size) {
    for(int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    char chars[] = {'B', 'C', 'D', 'A', 'E', 'H', 'G', 'F'};

    insertionsort(chars, 8);
    printArr<char>(chars, 8);

    return EXIT_SUCCESS;
}