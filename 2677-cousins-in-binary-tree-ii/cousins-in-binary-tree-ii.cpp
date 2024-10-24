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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = root->val;
        while(!q.empty()){
            int sz = q.size();
            int tempsum = 0;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    if(node->right){
                        int total = node->left->val + node->right->val;
                        q.push(node->left);
                        q.push(node->right);
                        node->left->val = total;
                        node->right->val = total;
                        tempsum += total;
                    }
                    else{
                        q.push(node->left);
                        tempsum += node->left->val;
                    }
                }
                else if(node->right){
                    q.push(node->right);
                    tempsum += node->right->val;
                }
                node -> val = sum - node->val;
            }
            sum = tempsum;
        }
        return root;
    }
};