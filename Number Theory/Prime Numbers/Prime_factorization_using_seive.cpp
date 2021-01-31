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
int ar[1000001];
void seive_for_factors()
{
    //Time Complexity: O(nlog(logn))
    int maxn = 1000002;
    for (int i = 2; i < maxn; i++)
        ar[i] = i;
    for (int i = 4; i < maxn; i += 2)
        ar[i] = 2;

    for (int i = 3; i * i <= maxn; i++)
    {
        if (ar[i] == i)
        {
            for (int j = i * i; j < maxn; j += i)
            {
                if (ar[j] == j)
                    ar[j] = i;
            }
        }
    }
}
vector<int> get_factors(int num)
{
    //Time Complexity: O(logn)
    vector<int> res;
    while (num != 1)
    {
        res.push_back(ar[num]);
        num /= ar[num];
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive_for_factors();
    vector<int> res;
    res = get_factors(100);
    for (auto it : res)
        cout << it << " ";
    cout << endl;

    return 0;
}