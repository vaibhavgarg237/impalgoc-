#include <iostream>
using namespace std;

void SelectionSort(int *A, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int k;
        for (int j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(A[i],A[k]);
    }
    
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n =10;
    SelectionSort(A, n);
    for (int x : A)
    {
        cout <<x<<" ";
    }
    cout <<endl;  
    return 0;
}
