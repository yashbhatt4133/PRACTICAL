#include <bits/stdc++.h>
using namespace std;
void CS(int *arr, int n, int pos)
{
    int key = 0;
    int freq[10] = {0};
    for (int i = 0; i < n; i++)
    {
        key = (arr[i] / (int)pow(10, pos)) % 10;
        freq[key]++;
    }
    for (int i = 1; i <= 9; i++)
        freq[i] = freq[i - 1] + freq[i];
    int out[n];
    for (int i = n - 1; i >= 0; i--)
    {
        key = (arr[i] / (int)pow(10, pos)) % 10;
        out[--freq[key]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = out[i];
    }
}

void RS(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        mx = max(mx, arr[i]);
    int dig = 0;
    while (mx)
    {
        dig++;
        mx /= 10;
    }
    for (int i = 0; i < dig; i++)
    {
        CS(arr, n, i);
    }
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
    RS(arr, t);
    for (int i = 0; i < t; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// 8
// 1234 6572 1254 2345 9876 345 3341 21