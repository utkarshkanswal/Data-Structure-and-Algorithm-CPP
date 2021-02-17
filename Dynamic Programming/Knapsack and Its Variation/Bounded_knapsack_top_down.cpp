/*Author: Utkarsh Kumar
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
//Time Complexity: O(n^2)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dp[100][100];
    int n, m;
    cin >> n >> m;
    vector<int> wt(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    vector<int> val(n + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m];
    return 0;
}