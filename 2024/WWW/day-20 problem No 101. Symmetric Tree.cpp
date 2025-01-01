class Solution {
    bool check(TreeNode* LTree, TreeNode* RTree) {
        if (LTree == NULL && RTree == NULL) {
            return true;
        }
        if (LTree == NULL || RTree == NULL) {
            return false;
        }
        if (LTree->val != RTree->val) {
            return false;
        }
        return check(LTree->left, RTree->right) &&
               check(LTree->right, RTree->left);
    }

public:
    bool isSymmetric(TreeNode* root) {

        bool ans = check(root->left, root->right);
        return ans;
    }
};
