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
//Time Complexity: O(n)
void print_next_greater(vector<int> arr, int n)
{
    stack<int> st;
    st.push(arr[n - 1]);
    vector<int> res;
    res.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.empty() == false && st.top() <= arr[i])
            st.pop();
        int temp_res = st.empty() ? -1 : st.top();
        res.push_back(temp_res);
        st.push(arr[i]);
    }
    for (int i = n - 1; i >= 0; i--)
        cout << res[i] << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    print_next_greater(arr, n);

    return 0;
}