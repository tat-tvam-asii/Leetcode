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
    int helper(vector<int>& arr){
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            mp[arr[i]] = i;
        }
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(temp[i] != arr[i]){
                swap(mp[arr[i]],mp[temp[i]]);
                swap(arr[i],arr[mp[arr[i]]]);
                cnt++;
            }
        }
        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            for(int i = 0;i < n;i++){
                TreeNode* temp = q.front();
                arr.push_back(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans += helper(arr);
        }
        return ans;
    }
};