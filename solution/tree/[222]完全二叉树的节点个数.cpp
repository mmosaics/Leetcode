//给出一个完全二叉树，求出该树的节点个数。 
//
// 说明： 
//
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为
//第 h 层，则该层包含 1~ 2h 个节点。 
//
// 示例: 
//
// 输入: 
//    1
//   / \
//  2   3
// / \  /
//4  5 6
//
//输出: 6 
// Related Topics 树 二分查找 
// 👍 198 👎 0


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

#include "cmath"

class Solution {
public:
    int countNodes(TreeNode* root) {
        int d = countLevel(root);

        if(d == -1)
            return 0;
        if(d == 0)
            return 1;

        int left = 1;
        int right = (1<<d) - 1;
        int pivot;
        while(left <= right) {
            pivot = left + (right-left)/2;
            if(exists(pivot, d, root))
                left = pivot + 1;
            else
                right = pivot - 1;
        }

        int nodes = ((1<<d)-1) + left;

        return nodes;
    }

    bool exists(int idx, int d,TreeNode* root)
    {
        int left = 0;
        int right = (1<<d) - 1;
        int pivot;
        TreeNode* p = root;

        for(int i = 0; i < d; ++i)
        {
            pivot = left + (right-left)/2;
            if(idx <= pivot) {
                p = p->left;
                right = pivot;
            }
            else {
                p = p->right;
                left = pivot + 1;
            }
        }

        return p != nullptr;

    }

    int countLevel(TreeNode* root)
    {
        if(root == nullptr)
            return -1;
        TreeNode* p = root;
        int count = -1;

        while (p) {
            ++count;
            p = p->left;
        }

        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
