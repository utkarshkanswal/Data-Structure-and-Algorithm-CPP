/* Name: Utkarsh Kumar
Institution: NIT Meghalaya
*/
#include <iostream>
#include <vector>
using namespace std;
/* 
 Time Complexity: 
 Worst Case :O(n^2)
 Space: O(1)
*/
void BubbleSort(vector<int> &v, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    BubbleSort(v, n);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}