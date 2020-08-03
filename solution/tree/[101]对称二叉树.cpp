//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 939 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(root == nullptr)
            return true;

        return isSymmetric(root->left, root->right);

    }

    bool isSymmetric(TreeNode* lhs, TreeNode* rhs) {
        bool valueEqual = false;

        if(lhs == nullptr && rhs == nullptr)
            return true;
        if(lhs && rhs && lhs->val == rhs->val)
            valueEqual = true;

        return valueEuqal
               && isSymmetric(lhs->left, rhs->right)
               && isSymmetric(lhs->right, rhs->left);


    }
};
//leetcode submit region end(Prohibit modification and deletion)
