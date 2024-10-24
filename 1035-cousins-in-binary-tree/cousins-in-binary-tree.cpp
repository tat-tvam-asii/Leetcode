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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({root,root});
        while(!q.empty()){
            int s = q.size();
            bool a = false,b = false;
            while(s--){
                TreeNode *node = q.front().first,*parent = q.front().second;
                q.pop();
                if(node->val == x) a = true;
                if(node->val == y) b = true;
                TreeNode *Left = node->left,*Right = node->right;
                if(Left && Right && ((Left->val == x && Right->val == y) || (Left->val == y && Right->val == x))) return false;
                if(Left) q.push({Left,node});
                if(Right) q.push({Right,node});
            }
            if(a && b) return true;
        }
        return false;
    }
};