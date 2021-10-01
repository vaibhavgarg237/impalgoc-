#include <iostream>
using namespace std;

void BubbleSort(int *A, int n)
{
    int flag; // To make it adaptive
    for (int i = 0; i < n-1; i++)
    {
        flag =0;
        for (int j = 0; j < n-1-i; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                flag++;
            }
        }
        if (flag == 0) // The array is already sorted
        {
            break;
        }
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n =10;
    BubbleSort(A, n);
    for (int x : A)
    {
        cout <<x<<" ";
    }
    cout <<endl;    
    return 0;
}
