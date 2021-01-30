/* Name: Utkarsh Kumar
Institution: NIT Meghalaya
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
vector<pair<int, int>> vp;
void prime_factors(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        int count = 0; //Time Complexity: O(sqrt(n))
        if (n % i == 0)
        {
            while (n % i == 0)
                count++, n /= i;
            vp.push_back({i, count});
        }
    }
    if (n > 1)
        vp.push_back({n, 1});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 24;
    prime_factors(n);
    for (auto it : vp)
        cout << it.first << "^" << it.second << endl;
    return 0;
}