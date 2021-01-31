/* Author: Utkarsh Kumar
Institutions: NIT Meghalaya
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
int gcd(int a, int b)
{
    if (b == 0)
        return a; // Time Complexity: O(logmin(a,b))
    return gcd(b, a % b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << gcd(2, 3);

    return 0;
}