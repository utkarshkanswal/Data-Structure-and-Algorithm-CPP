/* Name: Utkarsh Kumar
Institution : NIT Meghalaya
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
/* 
     Time Complexity: O(n^2)
*/
int min_subset_sum(vector<int> arr, int n)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> temp;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] == true)
            temp.pb(i);
    }
    int mn = INT_MAX;
    for (int i = 0; i < temp.size(); i++)
        mn = min(mn, abs(sum - 2 * temp[i]));
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = min_subset_sum(arr, n);
    cout << res << "\n";
    return 0;
}