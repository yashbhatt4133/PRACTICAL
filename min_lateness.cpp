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

void mergesort(int *arr, int *b, int *job, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(arr, b, job, p, q);
        mergesort(arr, b, job, q + 1, r);
        merge(arr, b, job, p, q, r);
    }
}
// input -
//  n no of jobs
//  burst time array[n]

int main()
{
    int n;
    cout << "No of jobs >";
    cin >> n;
    cout << "Burst time of jobs >";
    int burst[n], job[n];
    for (int i = 0; i < n; i++)
    {
        cin >> burst[i];
        job[i] = i + 1;
    }
    cout << "Deadline of jobs >";
    int deadline[n];
    for (int i = 0; i < n; i++)
    {
        cin >> deadline[i];
    }
    mergesort(deadline, burst, job, 0, n - 1);
    int st[n], ft[n];
    int s = 0;
    cout << "\tJOB\tST\tFT\n ";
    for (int i = 0; i < n; i++)
    {
        st[i] = s;
        ft[i] = st[i] + burst[i];
        s = ft[i];
        cout << "\t" << job[i] << "\t" << st[i] << "\t" << ft[i] << "\n";
    }
    return 0;
}