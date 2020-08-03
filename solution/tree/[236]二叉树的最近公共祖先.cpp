//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 
//
// 示例 2: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉树中。 
// 
// Related Topics 树 
// 👍 682 👎 0


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        set<TreeNode *> nodeSet;
        stack<TreeNode *> S;

        TreeNode* firstMeet = nullptr;
        TreeNode* tmp = root;
        TreeNode* recent = nullptr;
        TreeNode* res = nullptr;
        while(tmp || !S.empty())
        {
            if(tmp) {
                S.push(tmp);
                tmp = tmp->left;
            }
            else {
                tmp = S.top();
                if(tmp->right && tmp->right != recent){
                    tmp = tmp->right;
                    S.push(tmp);
                    tmp = tmp->left;
                }
                    //下面就是对节点的访问
                else {
                    if((tmp == p || tmp == q) && firstMeet == nullptr){
                        if(tmp == p)
                            firstMeet = p;
                        else if(tmp == q)
                            firstMeet = q;

                        stack<TreeNode *> tempStack = S;
                        while(!tempStack.empty()) {
                            nodeSet.insert(tempStack.top());
                            tempStack.pop();
                        }
                    }
                    else if((tmp == p || tmp == q) && firstMeet)
                    {
                        stack<TreeNode *> tempStack = S;
                        while(!tempStack.empty()) {
                            TreeNode* topNode = tempStack.top();
                            if(nodeSet.count(topNode)) {
                                res = topNode;
                                break;
                            }
                            tempStack.pop();
                        }
                        break;
                    }
                    S.pop();
                    recent = tmp;
                    tmp = nullptr;
                }
            }
        }
        return res;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)
