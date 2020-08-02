//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 578 👎 0


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

#include "queue"
#include "vector"
using std::queue;
using std::vector;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        TreeNode * last = root;
        TreeNode * p = root;

        vector<vector<int>> result;

        queue<TreeNode *> Q;
        if(p != nullptr) {
            Q.push(p);
            result.resize(1);
        }

        int level = 0;
        //队列非空，则一直遍历
        while (!Q.empty())
        {
            p = Q.front();
            Q.pop();

            result[level].push_back(p->val);

            if(p->left)
                Q.push(p->left);

            if(p->right)
                Q.push(p->right);

            if(p == last)
            {
                ++level;
                last = Q.back();
                if(!Q.empty())
                    result.resize(level+1);
            }
        }

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
