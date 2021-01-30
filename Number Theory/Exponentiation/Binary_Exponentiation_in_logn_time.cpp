/*Author: Utkarsh Kumar
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
int power(int b, int p)
{
    int res = 1;
    while (p)
    {
        if (p % 2 == 1) //Time complexity: O(log(p))
        {
            res *= b;
            p--;
        }
        else
        {
            p /= 2;
            b *= b;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << power(2, 6) << "\n";

    return 0;
}