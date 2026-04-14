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
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);

        vector<int> temp;

        while(!que.empty()){
            TreeNode* nw = que.front();
            que.pop();

            if(nw == NULL){
                ans.push_back(temp);
                temp.clear();

                if(!que.empty())
                    que.push(NULL);
            }
            else{
                temp.push_back(nw->val);

                if(nw->left){
                    que.push(nw->left);
                }
                if(nw->right){
                    que.push(nw->right);
                }
            }
        }

        return ans;
    }
};
