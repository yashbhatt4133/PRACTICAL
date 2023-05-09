#include <bits/stdc++.h>
using namespace std;
int *CS(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, arr[i]);
    int freq[mx + 1] = {0};
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (int i = 1; i < mx + 1; i++)
        freq[i] = freq[i - 1] + freq[i];
    int *out = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        out[--freq[arr[i]]] = arr[i];
    }
    return out;
}

int main()
{
    int t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    int *x = CS(arr, t);
    for (int i = 0; i < t; i++)
    {
        cout << x[i] << " ";
    }
    return 0;
}
// 12
// 7 4 6 4 2 3 9 1 2 2 3 4