#include <iostream>
using namespace std;
/*
Lecture 5 1/24

Quicksort:
    Given an array of n comparable elements, if one item then return
    One element is picked as the pivot
    Two sub-arrays are creaed by partitioning
        Elements that are less than the pivot
        Elements that are greater than the pivot
    Quicksort two sub-arrays
    Return the results
*/

//Full Quicksort Algorithm
void quickSort(int arr[], int start, int end){
    if (start >= end){
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p-1);

    quickSort(arr, p+1, end);
}

//Partition for Quicksort
int partition(int arr[], int start, int last){
    int i = start + 1, j = last, temp;

    while(i <= j){
        if (arr[i] <= arr[start]){
            i++;
        }
        if (arr[j] > arr[start]){
            j--;
        }
        if (i <= j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[start];
    arr[start] = arr[j];
    arr[j] = temp;

    return j;
}

/*
Partitioning takes O(N) time 

If the best pivot is chosen so that it splits evenly
    One element sort gives O(1)
    If N-elements, then 2 recursive calls plus linear time
        T(N) = 2T(N/2) + O(N) = O(N log N) (same relation as mergesort)

If the worst pivot is chosen where one sub-array is empty
    T(N) <= T(N-1) + bN
         <= T(N-2) + b(N-1) + bN
         <= T(C) + b(C+1) + ... + bN
         <= a + b(C + (C+1) + (C+2) + ... + N)
    T(N)  = O(N^2)
*/

/*
Sorting in "Linear" Time: Binsort and Radix Sort

Binsort:
    Use keys to sort elements into bins (arrays) and count through the main array to organize
    Then output original array by outputting each bin sequentially
    Time complexity is O(N) assuming k is constant

Radix Sort:
    Uses binsort on each digit, starting with the bottom digit and moving up
*/