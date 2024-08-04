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
    // 这道题建树太麻烦，主要是递归，所以就直接写了
    // 思路：如果当前root不匹配就看root的左右节点，subroot不动
    // 如果匹配就验证下面的节点
    bool check(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr) return true;
        if((root == nullptr) || (subRoot == nullptr) || (root -> val != subRoot -> val)) return false;
        return check(root -> left, subRoot -> left) && check(root -> right, subRoot -> right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        return check(root, subRoot) || isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};