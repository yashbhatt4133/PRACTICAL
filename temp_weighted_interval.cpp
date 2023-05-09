#include <bits/stdc++.h>
using namespace std;
// input - n , w[n],st[n],ft[n]
// returns max profit

struct jobb
{
    int weight, st, ft;
};
bool comp(jobb j1, jobb j2)
{
    return j1.ft < j2.ft;
}
int *makep(int n, jobb *jobs)
{
    sort(jobs, jobs + n, comp);
    int *p = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int s = jobs[i].st;
        int j = i - 1;
        while (jobs[j].ft > s && j >= 0)
        {
            j--;
        }
        p[i] = j + 1;
    }
    return p;
}
int wis(int n, jobb *jobs, int *p)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return jobs[n - 1].weight;
    return 0 + max(jobs[n - 1].weight + wis(p[n - 1], jobs, p),
                   wis(n - 1, jobs, p));
}
int main()
{
    int n;
    cout << "No of jobs >";
    cin >> n;
    cout << "start time of jobs >";
    jobb jobs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].st;
    }
    cout << "Finsh of jobs >";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].ft;
    }
    cout << "Value of jobs >";
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].weight;
    }
    int *p1 = makep(n, jobs);
    cout << "profit >" << wis(n, jobs, p1);
    return 0;
}
// 6
// 7 0 1 2 1 6
// 10 2 5 6 8 9
// 1 2 4 4 7 2