/* Author: Utkarsh Kumar
Institution: NIT Meghalaya
Codechef Username: utkarshkanswal
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
//Time Complexity: O(sqrt) for a single query
vector<int> find_divisors(int num)
{
    vector<int> res;
    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (num / i == i)
                res.push_back(i);
            else
            {
                res.push_back(i);
                res.push_back(num / i);
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> res = find_divisors(7);
    for (auto it : res)
        cout << it << " ";
    cout << "\n";
    return 0;
}