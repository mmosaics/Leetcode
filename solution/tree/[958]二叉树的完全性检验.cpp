//给定一个二叉树，确定它是否是一个完全二叉树。 
//
// 百度百科中对完全二叉树的定义如下： 
//
// 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：
//第 h 层可能包含 1~ 2h 个节点。） 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[1,2,3,4,5,6]
//输出：true
//解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
// 
//
// 示例 2： 
//
// 
//
// 输入：[1,2,3,4,5,null,7]
//输出：false
//解释：值为 7 的结点没有尽可能靠向左侧。
// 
//
// 
//
// 提示： 
//
// 
// 树中将会有 1 到 100 个结点。 
// 
// Related Topics 树 
// 👍 63 👎 0


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
    bool isCompleteTree(TreeNode* root) {

        //用队列来进行层序遍历
        queue<TreeNode *> Q;

        TreeNode* p = root;

        //sentinel用于记录一次遍历过程中加入的儿子节点的个数
        int sentinel = 0;
        int left = 0;
        int right = 0;
        //flag标示是否出现了只有一个儿子节点进入队列，如果是，说明之后不应该有新的节点进入队列
        int flag = 0;

        Q.push(p);

        while(!Q.empty())
        {
            p = Q.front();
            Q.pop();

            sentinel = 0;
            left = 0;
            right = 0;

            if(p->left) {
                Q.push(p->left);
                ++sentinel;
                ++left;
            }
            if(p->right) {
                Q.push(p->right);
                ++sentinel;
                ++right;
            }

            if(left == 0 && right == 1)
                return false;
            else if(sentinel != 2 && flag == 0) {
                flag = 1;
                sentinel = 0;
            }

            if(flag == 1 && sentinel != 0)
                return false;

        }

        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
