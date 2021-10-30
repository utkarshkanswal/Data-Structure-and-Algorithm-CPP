#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;

// Time Complexity: String Matching O(1) time

lli Hash[100001], power[100001];
const lli q = 31;
void create_Hash(string str)
{
    power[0] = 1;
    lli N = str.size();
    for (lli i = N - 1; i >= 0; i--)
    {
        Hash[i] = ((Hash[i + 1] * q) % mod + (str[i] - 'a' + 1)) % mod;
        power[N - i] = (power[N - i - 1] * q) % mod;
    }
    power[N] = (power[N - 1] * q) % mod;
}
lli Hash_value(lli l, lli r)
{
    return (mod - (Hash[r + 1] * power[r - l + 1]) % mod + Hash[l]) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    lli n = str.size();
    create_Hash(str);
    cout << Hash_value(0, n - 1);
    return 0;
}