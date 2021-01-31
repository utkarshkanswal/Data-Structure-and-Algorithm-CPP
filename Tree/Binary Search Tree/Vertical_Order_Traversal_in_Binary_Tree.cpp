/*Author : Utkarsh Kumar
Institutions: NIT Meghalaya
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
map<int, multiset<pair<int, int>>> mp;
void dfs(TreeNode *root, int num, int d)
{
    if (root == nullptr)
        return;
    mp[num].insert({d, root->val});
    if (root->left != nullptr)
        dfs(root->left, num - 1, d + 1);
    if (root->right != nullptr)
        dfs(root->right, num + 1, d + 1);
}
vector<vector<int>> Vertical_traversal(TreeNode *root)
{
    vector<vector<int>> res;
    dfs(root, 0, 1);
    for (auto it : mp)
    {
        vector<int> temp;
        for (auto x : it.second)
            temp.push_back(x.second);
        res.push_back(temp);
    }
    return res;
}