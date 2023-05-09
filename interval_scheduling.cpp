#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
void merge(int *arr, int *b, int *job, int p, int q, int r)
{
    int lp = p, rp = q + 1, c = 0;
    int res[r - p + 1];
    int resb[r - p + 1];
    int resj[r - p + 1];
    while (lp <= q && rp <= r)
    {
        if (arr[lp] <= arr[rp])
        {
            res[c] = arr[lp];
            resb[c] = b[lp];
            resj[c] = job[lp];
            c++;
            lp++;
        }
        else
        {
            res[c] = arr[rp];
            resb[c] = b[rp];
            resj[c] = job[rp];
            c++;
            rp++;
        }
    }
    while (lp <= q)
    {
        res[c] = arr[lp];
        resb[c] = b[lp];
        resj[c] = job[lp];
        c++;
        lp++;
    }
    while (rp <= r)
    {
        res[c] = arr[rp];
        resb[c] = b[rp];
        resj[c] = job[rp];
        c++;
        rp++;
    }
    for (int i = 0; i < r - p + 1; i++)
    {
        arr[i + p] = res[i];
        b[i + p] = resb[i];
        job[i + p] = resj[i];
    }
}

void mergesort(int *arr, int *start, int *job, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(arr, start, job, p, q);
        mergesort(arr, start, job, q + 1, r);
        merge(arr, start, job, p, q, r);
    }
}
int main()
{
    int n;
    cout << "No of jobs >";
    cin >> n;
    cout << "start time of jobs >";
    int start[n], job[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
        job[i] = i + 1;
    }
    cout << "Finsh of jobs >";
    int finish[n];
    for (int i = 0; i < n; i++)
    {
        cin >> finish[i];
    }
    mergesort(finish, start, job, 0, n - 1);
    // int st[n], ft[n];
    int s = 0;
    cout << "\tJOB\tST\tFT\n ";
    for (int i = 0; i < n; i++)
    {
        if (start[i] >= s)
        {
            cout << "\t" << job[i] << "\t" << start[i] << "\t" << finish[i] << "\n";
            s = finish[i];
        }
    }
    return 0;
}
// 10
// 0 1 2 3 3 5 5 6 7 8
// 4 2 4 5 6 6 7 7 9 10