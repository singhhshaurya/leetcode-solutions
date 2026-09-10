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
    int ans = 0;
    pair<int, int> traverse(TreeNode* root){
        int sum = root->val;
        int n = 1;

        if(root->left){
            auto i = traverse(root->left);
            n += i.first;
            sum += i.second;
        }
        if(root->right){
            auto i = traverse(root->right);
            n += i.first;
            sum += i.second;
        }
        if(root->val == (int)sum/n) ans += 1;
        return {n, sum};


    }
    int averageOfSubtree(TreeNode* root) {
        // yar nsquare me to easily ho jayega
        traverse(root);
        return ans;

    }
};