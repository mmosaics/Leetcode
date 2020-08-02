//给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节
//点为空。 
//
// 每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。 
//
// 示例 1: 
//
// 
//输入: 
//
//           1
//         /   \
//        3     2
//       / \     \  
//      5   3     9 
//
//输出: 4
//解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
// 
//
// 示例 2: 
//
// 
//输入: 
//
//          1
//         /  
//        3    
//       / \       
//      5   3     
//
//输出: 2
//解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
// 
//
// 示例 3: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2 
//       /        
//      5      
//
//输出: 2
//解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
// 
//
// 示例 4: 
//
// 
//输入: 
//
//          1
//         / \
//        3   2
//       /     \  
//      5       9 
//     /         \
//    6           7
//输出: 8
//解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
// 
//
// 注意: 答案在32位有符号整数的表示范围内。 
// Related Topics 树 
// 👍 120 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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

#include "algorithm"

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
            return 0;

        AnnotatedNode * p = new AnnotatedNode(root, 0, 0);
        int left = 0, currentDepth = 0;
        queue<AnnotatedNode *> Q;
        Q.push(p);

        int ans = 0;

        while (!Q.empty())
        {
            p = Q.front();
            Q.pop();

            if(p->node != nullptr) {
                Q.push(new AnnotatedNode(p->node->left, p->depth + 1, p->pos * 2));
                Q.push(new AnnotatedNode(p->node->right, p->depth + 1, p->pos * 2 + 1));

                if(currentDepth != p->depth) {
                    currentDepth = p->depth;
                    left = p->pos;
                }

                ans = max(ans, p->pos - left + 1);

            }
        }
        return ans;
    }

    struct AnnotatedNode {
        TreeNode* node;
        unsigned long long depth;
        unsigned long long pos;

        AnnotatedNode(TreeNode* treeNode, int d, int p)
        : node(treeNode), depth(d), pos(p){}

    };

    unsigned long long max(unsigned long long a, unsigned long long b)
    {
        return a>b?a:b;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
