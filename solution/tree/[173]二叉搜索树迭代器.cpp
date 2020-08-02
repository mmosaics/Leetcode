//实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。 
//
// 调用 next() 将返回二叉搜索树中的下一个最小的数。 
//
// 
//
// 示例： 
//
// 
//
// BSTIterator iterator = new BSTIterator(root);
//iterator.next();    // 返回 3
//iterator.next();    // 返回 7
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 9
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 15
//iterator.hasNext(); // 返回 true
//iterator.next();    // 返回 20
//iterator.hasNext(); // 返回 false 
//
// 
//
// 提示： 
//
// 
// next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h) 内存，其中 h 是树的高度。 
// 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 中至少存在一个下一个最小的数。 
// 
// Related Topics 栈 树 设计 
// 👍 219 👎 0


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
class BSTIterator {
public:

    stack<TreeNode *> * nodeStack;

    BSTIterator(TreeNode* root) {
        //首先把root的左子节点全部压入栈中，执行完这个步骤后我们知道，这个时候的栈顶元素其实就是最小值了
        //那么栈的初始化就已经完成
        //那么之后只需要每次保证栈顶的元素都是最小值即可
        nodeStack = new stack<TreeNode *>();
        stackHelper(root);
    }
    
    /** @return the next smallest number */
    int next() {
        //首先弹出栈顶的元素
        TreeNode * p = nodeStack->top();
        nodeStack->pop();
        int res = p->val;
        //然后我们需要判断p是否有右儿子，如果有右儿子，说明下一个最小值会在p的右子树中
        //那么需要把右子树的节点压入栈中
        if(p->right) {
            stackHelper(p->right);
        }
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        //只要栈非空，那么就有next
        return !nodeStack->empty();
    }

    //栈的帮助函数，用于把root的左节点依次压入到栈中
    void stackHelper(TreeNode* root) {
        if(root) {
            nodeStack->push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//leetcode submit region end(Prohibit modification and deletion)
