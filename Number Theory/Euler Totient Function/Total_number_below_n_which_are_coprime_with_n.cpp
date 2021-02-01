/* Author: Utkarsh Kumar
Institutions: NIT Meghalaya
Codechef Username: utkarshkasnwal
*/

/*
  Important Point to Remember
  phi(n)=n*((p1-1)/p1)*((p2-1)/p2)*.....

*/

#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
int phi(int n)
{
    //Time Complexity: O(sqrt(n))
    int res = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            res /= i;
            res *= (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res /= n, res *= (n - 1);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << phi(200);

    return 0;
}