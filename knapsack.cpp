#include <iostream>
using namespace std;
// n weights 0->n-1
// n values 0->n-1
// given capacity
// maximise value

// recursive-global memoised
int **M;
int rnap(int n, int w, int weight[], int value[])
{
    if (n == 0 || w == 0)
        return (M[n][w] = 0);
    if (w < weight[n - 1])
        return (M[n][w] = rnap(n - 1, w, weight, value));
    return (M[n][w] = max(rnap(n - 1, w, weight, value), value[n - 1] + rnap(n - 1, w - weight[n - 1], weight, value)));
}

// iterative memoised
int knapsack(int n, int w, int weight[], int value[])
{
    int M[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            // if (~(i & j))
            if (i == 0 || j == 0)
            { // either i or j is 0
                M[i][j] = 0;
            }
            else if (j < weight[i - 1])
            { // cannot pick current value
                M[i][j] = M[i - 1][j];
            }
            else
            { // can pick current value - is it optimum ?
                M[i][j] = max(M[i - 1][j], value[i - 1] + M[i - 1][j - weight[i - 1]]);
            }
        }
    }
    return M[n][w];
}
int main()
{
    int n, w;
    cin >> n >> w;
    int weight[n], value[n];
    // global matrix
    M = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        M[i] = new int[w + 1];
    }
    cout << "Enter " << n << " Weights>>";
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cout << "Enter " << n << " Values>>";
    for (int i = 0; i < n; i++)
        cin >> value[i];
    cout << knapsack(n, w, weight, value) << endl;
    cout << rnap(n, w, weight, value);
    return 0;
}
// 3 8
// 2 6 1
// 5 2 7
// ans 12