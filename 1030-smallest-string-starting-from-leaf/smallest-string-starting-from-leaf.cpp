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
    void dfs(TreeNode* root,string& ans,string tmp){
        tmp = char('a'+ root->val) + tmp;
        if(root->left) dfs(root->left,ans,tmp);
        if(root->right) dfs(root->right,ans,tmp);
        if(!root->left && !root->right){
            ans = min(ans,tmp);
            return;
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans = "~";
        dfs(root,ans,"");
        return ans;
    }
};