#include<bits/stdc++.h>
using namespace std;


void heapify(int arr[], int n, int i)
{
    int root = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<root && arr[left]>arr[root]) root = left;
    if(right<root && arr[right]>arr[root]) root = right;

    if(root != i)
    {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}

void heapsort(int arr[], int n)
{
    for(int i=n/2 - 1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i=n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    //return arr;
}



int main()
{
    int n; 
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    heapsort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << endl;
    return 0;
}