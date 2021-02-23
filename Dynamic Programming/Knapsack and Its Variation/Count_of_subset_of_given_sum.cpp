#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
//Time Complexity: O(n^2)
int count_subset(vector<int> &v, int n, int sum)
{
    int total = accumulate(all(v), 0);
    int dp[n + 1][total + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= total; j++)
        {
            if (v[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - v[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int sum = 0;
    cin >> sum;
    cout << count_subset(v, n, sum);
    return 0;
}