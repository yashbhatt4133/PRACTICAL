#include <iostream>
using namespace std;
// maxheapify
void heapify(int *arr, int n, int i)
{
    int largest = i;
    int l = (2 * i);
    int r = 2 * i + 1;
    if (l <= n && arr[l] > arr[largest])
        largest = l;
    if (r <= n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
void heapsort(int *arr, int n)
{
    // buildheap
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    // delete
    for (int i = n; i >= 1; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}
void preorder(int *arr, int n, int i = 1)
{
    cout << arr[i] << " ";
    if (i * 2 <= n)
        preorder(arr, n, i * 2);
    if (i * 2 + 1 <= n)
        preorder(arr, n, 1 + i * 2);
}
void inorder(int *arr, int n, int i = 1)
{
    if (i * 2 <= n)
        inorder(arr, n, i * 2);
    cout << arr[i] << " ";
    if (i * 2 + 1 <= n)
        inorder(arr, n, 1 + i * 2);
}
void postorder(int *arr, int n, int i = 1)
{
    if (i * 2 <= n)
        postorder(arr, n, i * 2);
    if (i * 2 + 1 <= n)
        postorder(arr, n, 1 + i * 2);
    cout << arr[i] << " ";
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    heapsort(arr, n);
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    preorder(arr, n);
    cout << "\n";
    inorder(arr, n);
    cout << "\n";
    postorder(arr, n);
}