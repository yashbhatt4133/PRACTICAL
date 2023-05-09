#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int p, int r)
{
    int ran = p + rand() % (r - p + 1);
    swap(arr[ran], arr[r]);
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
int select(int *arr, int p, int r, int i)
{
    if (p == r)
        return arr[p];
    int q = partition(arr, p, r);
    int k = q - p + 1; // left side kitne elements hai + 1
    if (i == k)        // jo order chahiye left mai utne hi hai
        return arr[q];
    else if (i < k) // left mai jyada elems hai
        return select(arr, p, q - 1, i);
    return select(arr, q + 1, r, i - k); // left se k elements hata diye
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
    cout << select(arr, 0, n - 1, 8);
    return 0;
}