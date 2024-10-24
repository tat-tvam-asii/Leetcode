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
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            TreeNode *parentX = NULL,*parentY = NULL;
            while(s--){
                TreeNode *node = q.front();
                q.pop();
                TreeNode *Left = node->left,*Right = node->right;
                if(Left){
                    if(Left -> val == x) parentX = node;
                    else if(Left -> val == y) parentY = node;
                    q.push(Left);
                }
                if(Right){
                    if(Right -> val == x) parentX = node;
                    else if(Right -> val == y) parentY = node;
                    q.push(Right);
                }
            }
            if(parentX && parentY) return parentX != parentY;
            if(parentX || parentY) return false;
        }
        return false;
    }
};