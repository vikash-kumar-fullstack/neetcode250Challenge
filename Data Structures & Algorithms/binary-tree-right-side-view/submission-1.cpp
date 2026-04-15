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
    // void solve(TreeNode*root,vector<int>&ans,int lev){
    //     if(!root)return;
    //     if(lev==ans.size())ans.push_back(root->val);
    //     solve(root->right,ans,lev+1);
    //     solve(root->left,ans,lev+1);
    // }
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int>ans;
    //     int lev=0;
    //     solve(root,ans,lev);
    //     return ans;
    // }

    // by levelorder traversal
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                TreeNode* node = q.front();
                q.pop();

                if(i == size-1)
                    ans.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return ans;
    }
};
