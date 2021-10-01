#include <iostream>
using namespace std;

int Partion(int A[], int l, int h); // As to access the partion function in QuickSort

void QuickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int j = Partion(A, l, h);
        QuickSort(A, l, j); //jth element here acts as INT_MAX for this array
        QuickSort(A, j+1, h);
    }
    
}

int Partion(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot); // i will stop when element greater than pivot is found
        do
        {
            j--;
        } while (A[j] > pivot); // j will stop when element is smaller than or equal to pivot
        
        if (i < j)
        {
            swap(A[i], A[j]);
        }
    } while (i < j);
    swap(A[l], A[j]); // when i > j swaps the A[j] with the pivot element

    return j; // The index at which the sorted element is present
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT_MAX}, n = 11;
    QuickSort(A, 0, n-1);
    for (int i = 0; i < n-1; i++)
    {
        cout <<A[i]<<" ";
    }
    cout << endl;
    return 0;
}
