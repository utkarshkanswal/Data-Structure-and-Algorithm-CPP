/* Author : Utkarsh Kumar
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
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    { //Time complexity: O(sqrt(n))
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if (is_prime(n) == true)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}