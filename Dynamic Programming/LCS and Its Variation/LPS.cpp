/* Name: Utkarsh Kumar
Institution:  NIT Meghalaya
*/
class Solution
{
    int LongestCommonSubsquence(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }

public:
    int longestPalindromeSubseq(string s)
    {

        string ss = s;
        reverse(ss.begin(), ss.end());
        return LongestCommonSubsquence(s, ss);
    }
};