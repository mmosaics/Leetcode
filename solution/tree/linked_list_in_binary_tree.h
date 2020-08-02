//给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
//
// 如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False
//。
//
// 一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
//
//
//
// 示例 1：
//
//
//
// 输入：head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null
//,1,3]
//输出：true
//解释：树中蓝色的节点构成了与链表对应的子路径。
//
//
// 示例 2：
//
//
//
// 输入：head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,nu
//ll,1,3]
//输出：true
//
//
// 示例 3：
//
// 输入：head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,
//null,1,3]
//输出：false
//解释：二叉树中不存在一一对应链表的路径。
//
//
//
//
// 提示：
//
//
// 二叉树和链表中的每个节点的值都满足 1 <= node.val <= 100 。
// 链表包含的节点数目在 1 到 100 之间。
// 二叉树包含的节点数目在 1 到 2500 之间。
//
// Related Topics 树 链表 动态规划
// 👍 46 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {

        if(head == nullptr)
            return true;
        if(root == nullptr)
            return false;

        //先判断当前节点，当前不行，再判断左子树和右子树
        return isSub(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

    bool isSub(ListNode * head, TreeNode* root) {
        //如果head已经到了最后，说明匹配完成
        if(head == nullptr)
            return true;

        //如果树到了末尾还未匹配完，说明这里不存在子串
        if(root == nullptr)
            return false;

        //如果值不等，则一定不匹配
        if(root->val != head->val)
            return false;

        //如果不属于上述情况，说明这个节点匹配，则我们继续往后比较
        return isSub(head->next, root->left) || isSub(head->next, root->right);

    }
};
//leetcode submit region end(Prohibit modification and deletion)
