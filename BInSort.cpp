#include <iostream>
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

void Insert(Node **ptrBins, int idx)
{
    // Insertion will be done at the end of the LinkedList
    Node *temp =new Node;
    temp->value = idx;
    temp->next = NULL;

    if (ptrBins[idx] == NULL) // ptrBins[idx] is head ptr
    {
        // Hum phela element linked list mai insert kar rahe hai
        ptrBins[idx] = temp;
    }
    else
    {
        // Ham dusra element jo ki repeated hai use linked list mai insert kar rahe hai
        Node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int Delete(Node **prtBins, int idx)
{
    // Deletion will follow FIFO
    Node *p = prtBins[idx];
    prtBins[idx] = prtBins[idx]->next; // GO to first node in LL
    int x = p->value;
    p->next = NULL;
    delete p;
    return x;
}

void BinSort(int *A, int n)
{
    int max_ele = Max(A, n);

    Node **bins = new Node*[max_ele+1]; // Array of pointers as har index par pointers store honge jo linked list ko point karenge

    for (int i = 0; i < max_ele+1; i++)
    {
        bins[i] = NULL;
    }
    
    for (int i = 0; i < n; i++)
    {
        Insert(bins, A[i]);
    }

    int i=0, j=0;
    while (i < max_ele+1)
    {
        while (bins[i] != NULL) // Jabtak lInked list khali nahi ho jata tabtAK 
        {
            A[j++] = Delete(bins, i);
        }
        i++;
    }
    delete [] bins;
}

int main()
{
    int A[] = {3, 7, 3, 10, 6, 6, 12, 4, 11, 2}, n = 10;
    BinSort(A, n);
    for (int i = 0; i < n - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
