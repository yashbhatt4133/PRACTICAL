#include <bits/stdc++.h>
using namespace std;
// input - n , w[n],st[n],ft[n]
// returns max profit

void merge(int *ft, int *st, int *job, int *w, int p, int q, int r)
{
    int resf[r - p + 1];
    int ress[r - p + 1];
    int resj[r - p + 1];
    int resw[r - p + 1];
    int lp = p, rp = q + 1;
    int c = 0;
    while (lp <= q && rp <= r)
    {
        if (ft[lp] <= ft[rp])
        {
            resf[c] = ft[lp];
            ress[c] = st[lp];
            resj[c] = job[lp];
            resw[c] = w[lp];
            c++;
            lp++;
        }
        else
        {
            resf[c] = ft[rp];
            ress[c] = st[rp];
            resj[c] = job[rp];
            resw[c] = w[rp];
            c++;
            rp++;
        }
    }
    while (lp <= q)
    {
        resf[c] = ft[lp];
        ress[c] = st[lp];
        resj[c] = job[lp];
        resw[c] = w[lp];
        c++;
        lp++;
    }
    while (rp <= r)
    {
        resf[c] = ft[rp];
        ress[c] = st[rp];
        resj[c] = job[rp];
        resw[c] = w[rp];
        c++;
        rp++;
    }
    for (int i = 0; i < r - p + 1; i++)
    {
        ft[i + p] = resf[i];
        st[i + p] = ress[i];
        job[i + p] = resj[i];
        w[i + p] = resw[i];
    }
}

void mergesort(int *ft, int *st, int *job, int *w, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergesort(ft, st, job, w, p, q);
        mergesort(ft, st, job, w, q + 1, r);
        merge(ft, st, job, w, p, q, r);
    }
}
// rightmost non-conflicting,memoised
int *makep(int *ft, int *st, int *job, int *w, int n)
{
    mergesort(ft, st, job, w, 0, n - 1);
    int *p = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int s = st[i];
        int j = i - 1;
        while (ft[j] > s)
        {
            j--;
        }
        p[i] = j + 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << p[i] << " ";
    // }
    return p;
}
int wis(int n, int w[], int p[])
{
    if (n == 0)
        return 0;
    if (n == 1)
        return w[n - 1];
    return 0 + max(w[n - 1] + wis(p[n - 1], w, p),
                   wis(n - 1, w, p));
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
    cout << "Value of jobs >";
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int *p1 = makep(finish, start, job, w, n);
    cout << "profit >" << wis(n, w, p1);
    return 0;
}
// 6
// 7 0 1 2 1 6
// 10 2 5 6 8 9
// 1 2 4 4 7 2