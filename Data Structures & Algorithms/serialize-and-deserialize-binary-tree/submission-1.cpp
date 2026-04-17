/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.

    void solveS(TreeNode*root,string& s){
        if(!root){
            s+="NULL,";
            return;
            }
        s+=to_string(root->val)+",";
        solveS(root->left,s);
        solveS(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s="";
        solveS(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* solveD(queue<string>&q){
        string t=q.front();
        q.pop();
        if(t=="NULL")return NULL;
        TreeNode* temp=new TreeNode(stoi(t));
        temp->left=solveD(q);
        temp->right=solveD(q);
        return temp;
    }
    TreeNode* deserialize(string data) {
        queue<string>q;
        string temp="";

        for(char ch:data){
            if(ch==','){
                q.push(temp);
                temp="";
            }else{
                temp+=ch;
            }
        }
        return solveD(q);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));