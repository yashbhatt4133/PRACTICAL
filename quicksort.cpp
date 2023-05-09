#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int p, int r)
{
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j <= r; j++)
    {
        if (arr[j] <= pivot)
        {
            i += 1;
            swap(arr[i], arr[j]);
        }
    }
    return i;
}
void quicksort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}