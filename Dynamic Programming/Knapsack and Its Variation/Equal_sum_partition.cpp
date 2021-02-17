#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
//Time Complexity: O(n^2)
bool is_equal_sum_partition(vector<int> &v, int n)
{

    int total = accumulate(all(v), 0);
    if ((total & 1))
        return false;
    bool dp[n + 1][total + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
        {
            if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int sum = total / 2;
    if (dp[n][sum] == true)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    if (is_equal_sum_partition(v, n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}