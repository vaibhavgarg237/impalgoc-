// Sort array after converting elements to their squares
#include <iostream>
using namespace std;

// Sort1 is more efficient than Sort function
void Sort1(int *A, int n)
{
    int i = 0, j = n-1;
    int temp[n];
    for (int index = n-1; index >= 0; index--)
    {
        if (abs(A[i]) > abs(A[j]))
        {
            temp[index] = A[i]*A[i];
            i++;
        }
        else
        {
            temp[index] = A[j]*A[j];
            j--;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        A[i] = temp[i];
    }
}

void Sort(int *A, int n)
{
    // Array is already sorted 
    int k; // Will help in finding the last index of the negtive array and the first index of the positive array
    for (k = 0; k < n; k++)
    {
        if (A[k] >= 0)
        {
            break;
        }        
    }
    int i = k-1; //last index of the negative array
    int j = k; // first index of the positive array
    int index = 0; // Initail index of the temp array

    int temp[n];
    while (i >=0 && j < n)
    {
        if (A[i]*A[i] < A[j]*A[j])
        {
            temp[index++] = A[i]*A[i];
            i--;
        }
        else
        {
            temp[index++] = A[j]*A[j];
            j++;
        }
    }
    // If any of the negative or the positive array finishes then the above condition fails but we have to copy the remaining element to the temp array.
    while (i >= 0)
    {
        temp[index++] = A[i]*A[i];
        i--;
    }
    
    while (j < n)
    {
        temp[index++] = A[j]*A[j];
        j++;
    }
    // Copying the whole temp array to the original array
    for (int i = 0; i < n; i++)
    {
        A[i] = temp[i];
    }
}

int main()
{
    int arr[] = {-6, -3, -1, 2, 4, 5};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout <<"Before Sorting "<<endl;
    for (int x : arr)
    {
        cout <<x<<" ";
    }
    cout <<endl;

    Sort(arr, n);

    cout <<"After Sorting "<<endl;
    for (int x : arr)
    {
        cout <<x<<" ";
    }
    cout <<endl;
    return 0;
}
