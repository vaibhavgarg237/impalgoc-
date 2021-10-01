#include <iostream>
using namespace std;

void InsertionSort(int *A, int n)
{
    int x;
    for (int i = 1; i < n; i++) // First element is assumed to be sorted
    {
        int j =i-1;
        x = A[i]; // the element which is going to be inserted

        while (j > -1 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n =10;
    InsertionSort(A, n);
    for (int x : A)
    {
        cout <<x<<" ";
    }
    cout <<endl;  
    return 0;
}
