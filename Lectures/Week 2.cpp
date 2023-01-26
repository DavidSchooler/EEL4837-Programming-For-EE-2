#include <iostream>
using namespace std;
/*
Lecture 3 1/17

Basic Sorting: Bubblesort, Insertion Sort

Sorting is used to permute elements in an array so that they are ordered
    Bubblesort
    Insertion sort
    Mergesort
    Quicksort
    Heapsort
    Radix sort
    (First five are comparison based)

Bogosort - sorts a list of values by repetitively suffling them and check if they are sorted (not an algorithm since it has no time determination)
    It checks the list to see if it's sorted, if not, then it randomly permutes the entries in the array and repeats
    Worst-case running time: forever
    Best-case running time: O(1)

Bubblesort - compares neighboring elements and swapping their order
*/

int main(){
    const int n = 8;
    int a[n];

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-1-i; j++){
            if (a[j+1] < a[j]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

/*
Time complexity is n^2 due to nested for loops, while space complexity is O(1) since only one temp variable is used through the entire algorithm

Variations of the bubblesort (cocktail shaker sort) - alternate the passes start, check end to end, start again
*/

/*
C++ Templates

Function overloading can be used to use the same function with differing signatures to allow for all types to be used, however becomes clunky and hard to debug
We can use templates instead to generalize functions much more effciently
*/

template <class T>
T max (T x, T y){
    return (x > y? x : y);
}

/*
We can combine templates and bubblesort to sort any type of data
*/

//Example
template <class T>
void bubbleSort(T a[], int n){
    for (int i = 0; i < n-1; i++){
        for (int j = n-1; i < j; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
            }
        }
    }
}

int main(){
    int a[5] = {10, 50, 30, 40, 20};
    int n = sizeof(a) / sizeof(a[0]);

    bubbleSort(a, 5);
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

return 0;
}
//End Example

/*
Lecture 4 1/19

Templates can also apply to classes
*/

//Example
template <typename T>
class Array{
    private:
        T *ptr;
        int size;
    public:
        Array(T arr[], int s);
        void print();
};

template <typename T>
Array<T>::Array(T arr[], int s){
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++){
            ptr[i] = arr[i];
    }
}

template <typename T>
void Array<T>::print(){
    for(int i = 0; i < size; i++){
        cout << " " << *(ptr + i);
        cout << endl;
    }
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.print();
    return 0;
}
//End Example

/*
Insertion Sort

Orders a list of values by repetitively inseting a particular value into a soarted subset of the list
Insert a[i] to that array so that the sortedness is preserved, must shift values in array to insert
*/
int main(){
    int nextVal;
    const int n = 8;
    int a[n];

    for (int i = 1; i < n; i++){
        nextVal = a[i];
        int j = i;
        while(j > 0 && a[j-1] > nextVal){
            a[j] = a[j-1];
            j--;
        }
        a[j] = nextVal;
    }
}
/*
Time complexity of insertion sort is O(n^2) since there are nested loops however a cavet with the while loop is that it may not run every iteration of the for loop if there is no need to shift any spots

Space complexity is O(1) since only one extra variable to hold the inserted value
*/

/*
Recursion

A way of defining a concept where the definition refers to the concept that is being defined (define through itself). Solving a smaller version of a problem can solve the larger solution which is what recursion does
The problems have to be of the same type

Factorial is a simple version of recursion

n! = {1                  if n = 0
     {1*2*3*...*(n-1)*n  if n > 0
*/

int Factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * Factorial(n-1);
    }
}

/*
The time complexity of factorial, althought having only one input size, breaks the assumption of finite time to complete the multiplication operation since it scales due to how large the numbers get
*/

//Reversing an Array
int reverse(int arr[], int start, int end){
    int temp;

    if(start < end){
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        reverse(arr, start+1, end-1);
    }
    return 0;
}
/*
Time complexity of this function cuts down the speed of going through the array at a linear rate O(n/2) making it the class O(n)

We need to ensure that we facilitate recursion by defining additional parameters e.x. ReverseArray(A, i, j) not ReverseArray(A)

To write a recursive program
    Determine the size factor
    Determine the base case (which you know the answer)
    Determine the generl cases (where the problem is expressed as a smaller version of itself)
    Verify the algorithm (Three-Question Method)

    Three Question Method
        The Base-Case Question: If there a nonrecursive way out of the function and does this routine work correctly
        The Smaller-Caller Question: Does each recursive call to the function involve a smaller case of the original problem leading to the base case
        The General-Case Question: Assuming the recursive calls work correctly, does the function then work correctly

Advantages of Recursion
    Shorter, cleaner code
    Branching, tedious, and iterative problems
    Convenient for trees and graphs

Disadvantages of Recursion
    Takes up a lot of program stack space
    Uses more CPU time
    Difficult to debug
*/
/*
Divide-and-Conquer Sorting: Mergesort, Quicksort

Divide problem into smaller parts, independently solve the parts, combine these solutions to get overall solution

Mergesort: divide array into two halves, recursively sort left and right halves, then merge them back together
    Compare the values of each halved arrays with a pointer until arrays are merged
*/

//Merge part of Mergresort
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int P[n1], Q[n2];
    for (int  i = 0; i < n1; i++){
        P[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++){
        Q[j] = arr[m + 1 + j];
    }

    int i, j, k;
    i = 0; j = 0; k = l;

    while(i < n1 && j < n2){
        if(P[i] <= Q[j]){
            arr[k] = P[i]; i++;
        }
        else{
            arr[k] = Q[j]; j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = P[i]; i++; k++;
    }
    while(j < n2){
        arr[k] = Q[j]; j++; k++;
    }
}

//Full Mergesort Algorithm
void mergeSort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - 1)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
/*
Time complexity is O(n*log n), we know merging is O(n) so T(n) = 2^k*T(n/2^k)+k*cn, which completes when n/2^k <= 1, so k = O(log n)
*/