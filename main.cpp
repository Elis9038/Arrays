#include <QCoreApplication>
#include <iostream>


/* We take every array number for a check. There are some repeating numbers in arrays so we count the quantity of these number in A and B arrays and in C array separately.
If quantity of number in A and B equals quantity in C, then, obviously, all certain repeating numbers are already added to C */

bool check(int A[], int B[], int C[], int size_A, int size_B, int size_C, int num) {

    int num_in_AB = 0;
    int num_in_C = 0;

    for (int i = 0; i < size_A; i++) {

        if (A[i] == num) num_in_AB++;
    }

    for (int i = 0; i < size_B; i++) {

        if (B[i] == num) num_in_AB++;
    }

    for (int i = 0; i < size_C; i++) {

        if (C[i] == num) num_in_C++;
    }


    if (num_in_AB - num_in_C == 0) return false;

}


void merge(int A[], int B[], int C[], int size_A, int size_B, int size_C) {

    for (int i = 0; i < size_C; i++) {

        int theSmallestNum = 15;

        for (int i = 0; i < size_A; i++) {

            if (A[i] < theSmallestNum && check(A, B, C, size_A, size_B, size_C, A[i])) theSmallestNum = A[i];
        }

        for (int i = 0; i < size_B; i++) {

            if (B[i] < theSmallestNum && check(A, B, C, size_A, size_B, size_C, B[i])) theSmallestNum = B[i];
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
    int A[5] = {2, 4, 7, 9, 10};
    int B[5] = {2, 5, 10, 10, 14};

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
