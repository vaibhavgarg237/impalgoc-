#include <bits/stdc++.h>
using namespace std;

void Merge(int *A, int l, int mid, int h)
{
    int i, j, k;
    i = l, j = mid + 1, k = l;
    int B[h + 1];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= h)
    {
        B[k++] = A[j++];
    }
    for (int i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void IMergeSort(int *A, int n)
{
    int p, i, l, h, mid;

    for (p = 2; p <= n; p = p * 2) // For passes
    {
        for (i = 0; i + p - 1 < n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = floor((l + h) / 2);
            Merge(A, l, mid, h);
        }
        if (n - i > p / 2)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, n - 1);
        }
    }
    if (p / 2 < n)
    {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

void RMergeSort(int *A, int l, int h)
{
    int mid;
    if (l < h)
    {
        // Like the Post order traversal of the tree
        mid = floor((l+h)/2);
        RMergeSort(A, l, mid);
        RMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
    
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    RMergeSort(A, 0, n-1);
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
