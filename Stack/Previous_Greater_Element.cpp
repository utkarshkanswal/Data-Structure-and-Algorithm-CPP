/* Name: Utkarsh Kumar
Institution: utkarshkanswal
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
void print_previous_greater(vector<int> arr, int n)
{
    stack<int> st;
    st.push(arr[0]);
    cout << "-1 ";
    for (int i = 1; i < n; i++)
    {
        while (st.empty() == false && st.top() <= arr[i])
            st.pop();
        int temp_res = st.empty() ? -1 : st.top();
        cout << temp_res << " ";
        st.push(arr[i]);
    }
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
    print_previous_greater(arr, n);
    return 0;
}