/* Author: Utkarsh Kumar
Institution: NIT Meghalaya
Codechef Username: utkarshkanswal
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
int st[400005], arr[100005];
#define inf INT_MAX;
void build(int si, int ss, int se)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si] = min(arr[2 * si], arr[2 * si + 1]);
}
void update(int si, int ss, int se, int qi)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    if (qi <= mid)
        update(2 * si, ss, mid, qi);
    else
        update(2 * si + 1, mid + 1, se, qi);

    st[si] = min(st[2 * si], st[2 * si + 1]);
}
int range_min(int si, int ss, int se, int qs, int qe)
{
    if (qs > se || qe < ss)
        return inf;
    if (ss >= qs && se <= qe)
        return st[si];
    int mid = (ss + se) / 2;
    int l = range_min(2 * si, ss, mid, qs, qe);
    int r = range_min(2 * si + 1, mid + 1, se, qs, qe);
    return min(l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    arr[0] = 6;
    arr[1] = 1;
    arr[2] = 2;
    build(0, 0, 2);
    cout << range_min(0, 0, 2, 0, 2) << "\n";
    arr[0] = 2;
    update(0, 0, 2, 0);
    cout << range_min(0, 0, 2, 0, 2) << "\n";
    return 0;
}