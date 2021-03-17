/* Name: Utkarsh Kumar
Institution: NIT Meghalaya
*/
#include <iostream>
#include <vector>
using namespace std;
/* 
 Time Complexity: 
 Worst Case :O(nlogn)
 Space: O(n)
*/
void merge(vector<int> &arr, int l, int n, int r)
{
    int n1 = n - l + 1;
    int n2 = r - n;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[n + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}
void MergeSort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(v, l, m);
        MergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    MergeSort(v, 0, n - 1);
    for (auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}