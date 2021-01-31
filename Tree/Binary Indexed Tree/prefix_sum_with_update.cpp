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
int fen[100005];
void update(int i, int x, int n)
{
    //Time Complexity: O(logn)
    while (i < n)
    {
        fen[i] += x;
        i += (i & (-i));
    }
}
int prefix_sum(int i)
{
    //Time Complexity: O(logn)
    int res = 0;
    while (i > 0)
    {
        res += fen[i];
        i -= (i & (-i));
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {2, 5, 6, 7};
    for (int i = 0; i < v.size(); i++)
        update(i, v[i], 4);

    cout << prefix_sum(2);

    return 0;
}