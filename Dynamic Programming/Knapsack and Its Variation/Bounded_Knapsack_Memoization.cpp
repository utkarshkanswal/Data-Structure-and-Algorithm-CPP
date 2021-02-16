#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
//Time Complexity: O(n^2)
int dp[1000][1000];
int knapsack(vector<int> &wt, vector<int> &val, int w, int n)
{
    if (w == 0 || n == 0)
        return 0;
    if (dp[n][w] != -1)
        return dp[n][w];
    if (wt[n - 1] <= w)
    {
        return dp[n][w] = max(val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), knapsack(wt, val, w, n - 1));
    }
    else
        return dp[n][w] = knapsack(wt, val, w, n - 1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    vector<int> wt = {4, 2, 1, 4, 5};
    vector<int> val = {2, 8, 2, 3, 4};
    cout << knapsack(wt, val, 12, 5);
    return 0;
}