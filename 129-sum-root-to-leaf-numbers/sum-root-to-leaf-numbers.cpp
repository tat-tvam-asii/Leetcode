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
class Solution {
public:
    void dfs(TreeNode* root,string s,int& ans){
        s += to_string(root->val);
        if(root->left) dfs(root->left,s,ans);
        if(root->right) dfs(root->right,s,ans);
        if(!root->left && !root->right){
            ans += stoi(s);
            return;
        }
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root,"",ans);
        return ans;
    }
};