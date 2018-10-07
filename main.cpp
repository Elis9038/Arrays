#include <QCoreApplication>
#include <iostream>


bool IsNumIsAlreadyIn_C_Array(int C[], int size_C, int num) {

    for (int i = 0; i < size_C; i++) {

        if (C[i] == num) return false;

    }

    return true;

}


void merge(int A[], int B[], int C[], int size_A, int size_B, int size_C) {

    for (int i = 0; i < size_C; i++) {

        int theSmallestNum = 13;

        for (int i = 0; i < size_A; i++) {

            if (A[i] < theSmallestNum && IsNumIsAlreadyIn_C_Array(C, size_C, A[i])) theSmallestNum = A[i];
        }

        for (int i = 0; i < size_B; i++) {

            if (B[i] < theSmallestNum && IsNumIsAlreadyIn_C_Array(C, size_C, B[i])) theSmallestNum = B[i];
        }

        C[i] = theSmallestNum;
    }
}


void printArray(int array[], char arrayName, int arraySize) {

    std:: cout << "Array " << arrayName << " = {";

    for (int i = 0; i < arraySize-1; i++) {
        std:: cout << array[i] << ", ";
    }

    std:: cout << array[arraySize-1] << "}\n";
}


int main()
{
    int A[3] = {5, 9, 1};
    int B[5] = {2, 8, 6, 12, 10};
    int size_A = sizeof(A)/sizeof(*A);
    int size_B = sizeof(B)/sizeof(*B);

    int size_C = size_A + size_B;
    int C[size_C] = {};

    merge(A, B, C, size_A, size_B, size_C);


    printArray(A, 'A', size_A);
    printArray(B, 'B', size_B);
    printArray(C, 'C', size_C);

    return 0;

}
