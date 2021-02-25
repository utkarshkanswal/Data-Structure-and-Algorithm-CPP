#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
int ceil_idx(vector<int> temp, int val)
{
    int l = 0, r = temp.size() - 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (temp[mid] >= val)
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}
int LIS(vector<int> &nums)
{
    vector<int> temp;
    int n = nums.size();
    if (n <= 1)
        return n;
    temp.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] <= temp.back())
        {
            int idx = ceil_idx(temp, nums[i]);
            temp[idx] = nums[i];
        }
        else
            temp.push_back(nums[i]);
    }
    int res = temp.size();
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int res = LIS(nums);
    cout << res;
    return 0;
}