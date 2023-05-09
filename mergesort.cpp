#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int p, int q, int r)
{
    int lp = p, rp = q + 1, c = 0;
    int res[r - p + 1];
    while (lp <= q && rp <= r)
    {
        if (arr[lp] <= arr[rp])
            res[c++] = arr[lp++];
        else
            res[c++] = arr[rp++];
    }
    while (lp <= q)
    {
        res[c++] = arr[lp++];
    }
    while (rp <= r)
    {
        res[c++] = arr[rp++];
    }
    for (int i = 0; i < r - p + 1; i++)
        arr[i + p] = res[i];
}

void mergesort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
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
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}