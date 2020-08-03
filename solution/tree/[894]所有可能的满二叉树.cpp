//满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。 
//
// 返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。 
//
// 答案中每个树的每个结点都必须有 node.val=0。 
//
// 你可以按任何顺序返回树的最终列表。 
//
// 
//
// 示例： 
//
// 输入：7
//输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0
//,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
//解释：
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= N <= 20 
// 
// Related Topics 树 递归 
// 👍 129 👎 0


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

#include <vector>
#include <map>
#include <algorithm>

using std::vector;
using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int, vector<TreeNode *>> memo;

    vector<TreeNode*> allPossibleFBT(int N) {
        if(!memo.count(N)) {
            vector<TreeNode *> ans;
            if(N == 1) {
                ans.push_back(new TreeNode(0));
            } else if( N % 2 == 1) {
                for(int x = 0; x < N; ++x) {
                    int y = N - 1 - x;
                    for(auto left: allPossibleFBT(x)) {
                        for(auto right: allPossibleFBT(y)) {
                            TreeNode* bns = new TreeNode(0);
                            bns->left = left;
                            bns->right = right;
                            ans.push_back(bns);
                        }
                    }
                }
            }
            memo[N] = ans;
        }

        return memo[N];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
