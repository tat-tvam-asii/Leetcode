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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while(!q.empty()){
            int n = q.size(),j = 0;
            vector<int> temp1;
            for(int i = 0;i < n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->right){
                    q.push(node->right);
                    temp1.push_back(node->right->val);
                }
                if(node->left){
                    q.push(node->left);
                    temp1.push_back(node->left->val);
                }
                if(level % 2) node->val = temp[j++];
            }
            if(level % 2 == 0) reverse(temp1.begin(),temp1.end());
            temp = temp1;
            level++;
        }
        return root;
    }
};