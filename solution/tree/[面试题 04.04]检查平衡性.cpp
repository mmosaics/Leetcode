//实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。 示例 1: 给定二叉树 [3,9,20,nu
//ll,null,15,7]     3    / \   9  20     /  \    15   7 返回 true 。示例 2: 给定二叉树 [1,2,
//2,3,3,null,null,4,4]       1      / \     2   2    / \   3   3  / \ 4   4 返回 fal
//se 。 Related Topics 树 深度优先搜索 
// 👍 25 👎 0


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
    bool isBalanced(TreeNode* root) {
        bool res;
        int h;
        isBalanced(root, h, res);
        return res;

    }

    void isBalanced(TreeNode* root, int & h, bool & balanced) {
        //如果为空节点，高度为-1，且平衡
        if(root == nullptr) {
            h = -1;
            balanced = true;
            return;
        }
        bool leftBalance;
        bool rightBalance;
        int leftHeight;
        int rightHeight;
        isBalanced(root->left, leftHeight, leftBalance);
        isBalanced(root->right, rightHeight, rightBalance);
        h = std::max(leftHeight, rightHeight) + 1;
        balanced = (std::abs(leftHeight - rightHeight) <= 1) && leftBalance && rightBalance;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
