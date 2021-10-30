#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
// Time Complexity: O(n)

vector<int> find_lps(string str)
{
    int n = str.size();
    vector<int> lps(n);
    lps[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && str[i] != str[j])
            j = lps[j - 1];

        if (str[i] == str[j])
            j++;
        lps[i] = j;
    }
    return lps;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    vector<int> v;
    v = find_lps(str);
    for (auto x : v)
        cout << x << " ";
    return 0;
}