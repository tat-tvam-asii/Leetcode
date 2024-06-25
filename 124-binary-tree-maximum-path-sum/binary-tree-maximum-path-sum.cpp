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
    int maxPathSum(TreeNode* root) {
       int sum = INT_MIN;
       pathsum(root,sum);
       return sum;
    }

private:
    int pathsum(TreeNode* node,int& sum){
        if(node == nullptr)
            return 0;
        int left = max(0,pathsum(node->left,sum));
        int right = max(0,pathsum(node->right,sum));
        sum = max(sum,left + right + node->val);
        return max(left,right) + node->val;
    }
};