//给定一个二叉树，它的每个结点都存放着一个整数值。 
//
// 找出路径和等于给定数值的路径总数。 
//
// 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。 
//
// 示例： 
//
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//
//      10
//     /  \
//    5   -3
//   / \    \
//  3   2   11
// / \   \
//3  -2   1
//
//返回 3。和等于 8 的路径有:
//
//1.  5 -> 3
//2.  5 -> 2 -> 1
//3.  -3 -> 11
// 
// Related Topics 树 
// 👍 512 👎 0


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
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int statistic = 0;
        vector<int> sumList;
        computePathSum(root, sumList, sum, statistic);
        return statistic;
    }

    void computePathSum(TreeNode* root, vector<int> sumList, int sum, int & statistic)
    {
        if(root) {
            //给数组里的所有
            for(auto & s: sumList) {
                s += root->val;
                if(sum == s)
                    ++statistic;
            }

            if(root->val == sum)
                ++statistic;

            sumList.push_back(root->val);

            computePathSum(root->left, sumList, sum, statistic);
            computePathSum(root->right, sumList, sum, statistic);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
