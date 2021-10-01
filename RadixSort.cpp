#include <bits/stdc++.h>
using namespace std;

int Max(int *A, int n)
{
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max_ele < A[i])
        {
            max_ele = A[i];
        }
    }
    return max_ele;
}

class Node
{
    public:
      int value;
      Node *next;
};

int countDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x/10;
        count++;
    }
    return count;
}

void Insert(Node **ptrBins, int value, int idx)
{
    // here idx is the index at which we are inserting depending on the digit of the element
    Node *temp = new Node;
    temp->value = value;
    temp->next = NULL;

    if (ptrBins[idx] == NULL)
    {
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    p->next = NULL;
    delete p;
    return x;
}

int getBinIndex(int x, int idx)
{
     // x is the value of A[i] and idx is the pass
     return (int)(x/pow(10, idx)) % 10;
}

void RadixSort(int *A, int n)
{
    int max_ele = Max(A,n);
    int nPass = countDigits(max_ele); // as number of passes depends upon how many digit does an element have?

    Node **bins = new Node*[10]; // if int is decimal then size will be 10 else if int is binary digits then size of the array will be 2

    for (int i = 0; i < 10; i++)
    {
        bins[i] = NULL;
    }
    
    // Update bins and A for nPass times
    for (int pass = 0; pass < nPass; pass++)
    {
        // Update the bins based on the A value
        for (int i = 0; i < n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }
        
        int i=0, j=0;
        while (i < 10)
        {
            while (bins[i] != NULL)
            {
                A[j++] = Delete(bins, i);
            }
            i++;
        }

        // intializes the array of LL to null for next pass
        for (int i = 0; i < 10; i++)
        {
            bins[i] = NULL;
        }
    }
    delete [] bins;
}

int main()
{
    int A[] = {3, 7, 3, 10, 6, 6, 12, 4, 11, 2}, n = 10;
    RadixSort(A, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}