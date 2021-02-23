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

/* Time complexity: Insertion sort

   Best Case: O(n)  -- sorted order
   Worst Case: O(n^2) --reversely sorted

   Inplace and stable Algo.

*/
void insertion_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = v[i];
        while (j >= 0 && v[j] >= key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.pb(x);
    }
    insertion_sort(arr);
    for (auto it : arr)
        cout << it << " ";
    cout << "\n";
    return 0;
}