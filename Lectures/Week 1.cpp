#include <iostream>
using namespace std;
/*
Lecture 2 1/12

Array Data Structure
    A data Structure consiting of a collection of elements identified by an index or key. Usually used in a continuous sequence.
CreateArray(n) // create array with size n
a[i] = x       // assign the value of x at the index identified
x = a[i]       // read the value of a[i] to x
*/

//Algorithm: Linear Search

int lSearch(int arr[], int n, int x)
{
    int i;
    for(i = 0; i < n; i++) //for loop iterates through entire array of size n
    {
        if(arr[i] == x)    //checks each element of array and compares to i
        {
            return i;      //return index/position within array 
        }
    }
    return -1;
}

//Example
void main()
{
    int arr[] = {3,4,1,7,5};
    int n = 5;
    int x = 4;
    int index = lSearch(arr, n, x);
    if(index == -1) {
        cout << "Element is not present in the array" << endl;
    }
    else {
        cout << "Element found at position" << index << endl;
    }
}
//End Example

//Algorithm: Binary Search

int binarySearch(int arr[], int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

/*
Data Structure: Classes
Declarations for classes should be completed in header files and definitions in .cpp file
*/

//Example
class Circle {
    private:
        double radius;
    public:
        Circle () {radius = 0.0;}
        Circle (double r);
        double setRadius (double r);
        double getArea ();
        double getCircumference ();
};
Circle::Circle (double r) {
    radius = r;
}
double Circle::getArea () {
    return radius*radius*(22.0/7);
}
double Circle::getCircumference () {
    return 2*radius*(22.0/7);
}

void main() {
    Circle c (7);
    cout << "The area of the circle c is"
         << c.getArea()
         << endl;
}
//End Example

/*
Execuetable code is stored in source .cpp files
Header files store class declarations and functions
Making an execuetable from code requires three steps
    Preprocessing, Compilation, Linking 
Compiler command is g++
*/

/*
Time Complexity and the Big-Oh Notation

Algorithms trandform input objects into output objects witht he running time gorwing with the input size
We focus on the worst-case analysis (most critical) since its difficult to measure average case
In order to compare two algorithms we have use same hardware & software enviornments

Pseudocode
A high-level description of code that is strucutred closesly to english by removing syntax and less detailed than code

Primitive operations are assumed to take a constant time to compute (evalulating expression, indexing into array)
Seven functions that appear in algorithm analysis: 
    Constant = 1
    Logarithmic = log n
    Linear = n
    N-log-N = n log n
    Quadratic = n^2
    Cubic = n^3
    Exponential = 2^n

We can determine the maximum number of primitive operations execueted by an algorithm. as a function of input size, giving us its time complexity

//Example
Algorithm arrayMax(A, n)              #operations
    currentMax <- A[0]                     2
    for i <- 1 to n-1 do                   2n
        if A[i] > currentMax then        2(n-1)
            currentMax <- A[i]           2(n-1)
    {increment counter i}                2(n-1)
    return currentaMax                     1
                                     Total = 8n-2
//End Example

a = Time taken by the fastest primitive operation
b = Time taken by the slowest primitive operation

Let T(n) be te worst-case time of arrayMax. Then a(8n-2) < T(n) < b(8n-2)
*/

/*
Comparing functions f(n) and g(n), f(n) = O(g(n)) means there are posivitve constants c and n0, such that 0 < f(n) < cg(n) for all n > n0.

//Example
    2n + 10 is O(n)
    2n + 10 < cn
    (c - 2)n > 10
    n > 10/(c - 2)
    Pick c = 3 and n0 = 10

    7n - 2 is O(n)
    need c > 0 and n0 > 1 such that 7n - 2 < c*n for n > n0
    so c = 7 and n0 = 1
//End Example

If f(n) is a polynomial of degree d, then f(n) is O(n^d)
Use the smallest possible class of functions "2n is O(n) not 2n is O(n^2)"
Use the simplist expression of the class "3n + 5 is O(n) not 3n + 5 is O(3n)"

Big-Oh gives an upper bound on the growth rate of the function
This can rank functions based on their growth rates
*/

/*
Data Structure: Stack

Abstract Data Type: define a data structure by specifying what function it supports
This separates the interface from the implementation
It is a mathematical representation of a set of values and set of operations supported by these values

Stack has operations to create, destroy, push, pop, is_empty, is_full (if stack has a size)
Stack property is LIFO, if x is on the stack before y is pushed, then x will be popped after y is popped

We can implement the stack using an array by adding elements from left to right with a variable to keep track of the index of the top element
*/

//Example
#define SIZE 5
using namespace std;

class STACK {
    private:
        int num[SIZE];
        int top;
    public:
        STACK();
        int push(int);
        int pop();
        int isEmpty();
        int isFull();
};
int STACK::isEmpty() {
    if(top == -1)
        return 1;
    else
        return 0;
}
int STACK::isFull() {
    if(top == (SIZE - 1))
        return 1;
    else
        return 0;
}
int STACK::push(int n) {
    if(isFull())
        return 0;
    ++top;
    num[top] = n;
    return n;
}
int STACK::pop() {
    int temp;
    if(isEmpty())
        return 0;
    temp = num[top];
    --top;
    return temp;
}
//End Example

/*
Stack Performance and Limitations

Let n be the number of elements in the stack
The space used is O(n)
Each operation runs in time O(1)

The maximum size of the stack must be defined and can't be changed

Two-Stack Algorithm:
    Value: push onto the value stack
    Operator: push onto the operator stack
    Left Parenthesis: ignore
    Right Parenthesis: pop operator and two values; push the result of applying that operator to those values ontot the operand stack
*/

/*
Postfix Expressions

Another way of writing arithmetic expressions
The operator is written after the two operands
    Infix: 2 + 5               Postfix: 2 5 +
    Infix: (3 + ((4 + 5) * 2)) Postfix: 3 4 5 + 2 * +
Expressions are evaulted from left to right and pushing operands into a stack then pop and execute operations
Precedence rules and parenthesis are never needed
*/