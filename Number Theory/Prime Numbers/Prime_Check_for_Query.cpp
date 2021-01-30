/* Name: Utkarsh Kumar
Institutions: NIT Meghalaya
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
int is_prime[100002];
void seive()
{
    int n = 100002;
    for (int i = 0; i <= n; i++)
        is_prime[i] = 1;
    is_prime[0] = 0;
    is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++) //Time Complexity: O(log(logn))
    {
        if (is_prime[i])
        {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    seive();
    for (int i = 1; i <= 13; i++)
    {
        cout << is_prime[i] << " ";
    }
    cout << "\n";
    return 0;
}