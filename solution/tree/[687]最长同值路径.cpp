//给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。 
//
// 注意：两个节点之间的路径长度由它们之间的边数表示。 
//
// 示例 1: 
//
// 输入: 
//
// 
//              5
//             / \
//            4   5
//           / \   \
//          1   1   5
// 
//
// 输出: 
//
// 
//2
// 
//
// 示例 2: 
//
// 输入: 
//
// 
//              1
//             / \
//            4   5
//           / \   \
//          4   4   5
// 
//
// 输出: 
//
// 
//2
// 
//
// 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。 
// Related Topics 树 递归 
// 👍 323 👎 0


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

    int currentMaxElement = -1;
    int currentMaxPath = -1;

    int longestUnivaluePath(TreeNode* root) {
        int element;
        int depth;
        longest(root, element, depth);
        return currentMaxPath;

    }

    void longest(TreeNode* root, int & element, int & depth) {
        if(root == nullptr) {
            element = -100;
            depth = 0;
            if(depth > currentMaxPath)
                currentMaxPath = depth;
            return;
        }
        else {
            int leftDepth, rightDepth;
            int leftELe, rightEle;

            longest(root->left, leftELe, leftDepth);
            longest(root->right, rightEle, rightDepth);

            int tmpDepth;

            if(root->val == leftELe && root->val == rightEle) {
                tmpDepth = leftDepth + rightDepth + 2;
                if(tmpDepth > currentMaxPath) {
                    currentMaxPath = tmpDepth;
                    currentMaxElement = root->val;
                }
                depth = max(leftDepth, rightDepth) + 1;
            }
            else if(root->val == leftELe) {
                tmpDepth = leftDepth + 1;
                if(tmpDepth > currentMaxPath) {
                    currentMaxPath = tmpDepth;
                    currentMaxElement = leftELe;
                }
                depth = tmpDepth;
            }
            else if(root->val == rightEle) {
                tmpDepth = rightDepth + 1;
                if(tmpDepth > currentMaxPath) {
                    currentMaxPath = tmpDepth;
                    currentMaxElement = rightEle;
                }
                depth = tmpDepth;
            }
            else {
                depth = 0;
                if(depth > currentMaxPath)
                    currentMaxPath = depth;
            }

            element = root->val;

        }
    }
};

//leetcode submit region end(Prohibit modification and deletion)
