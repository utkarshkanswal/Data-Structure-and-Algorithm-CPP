/* Name: Utkarsh Kumar
Institution: NIT Meghalaya
*/
#include <bits/stdc++.h>
#define mod (1000000007)
#define lli long long int
#define pf push_front
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
// Time Complexity: O(n)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int diff[n + 2] = {0};
    int q, l, r, w;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l >> r >> w;
        diff[l] += w;
        diff[r + 1] -= w;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += diff[i];
        arr[i] += count;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}