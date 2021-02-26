/* Nmae: Utkarsh Kumar
Instituion: NIT Meghalaya
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
//Time Complexity: O(2^n)
vector<vector<string>> res;
bool is_palindrome(string str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
void solve(string s, int i, vector<string> v)
{
    if (i == s.size())
    {
        res.push_back(v);
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        if (is_palindrome(s, i, j) == true)
        {
            v.push_back(s.substr(i, j - i + 1));
            solve(s, j + 1, v);
            v.pop_back();
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    vector<string> temp;
    solve(str, 0, temp);
    for (auto v : res)
    {
        for (auto str : v)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}