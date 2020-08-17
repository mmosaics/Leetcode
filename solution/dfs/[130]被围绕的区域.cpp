//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。 
//
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
//
// 示例: 
//
// X X X X
//X O O X
//X X O X
//X O X X
// 
//
// 运行你的函数后，矩阵变为： 
//
// X X X X
//X X X X
//X X X X
//X O X X
// 
//
// 解释: 
//
// 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被
//填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 344 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        int rowSize = board.size();
        int columnSize = board[0].size();
        //先对边缘为O的进行深度优先搜索
        for(int i = 0; i < rowSize; ++i) {
            if(i == 0 || i == rowSize-1) {
                for(int j = 0; j < columnSize; ++j)
                    dfs(board, i, j);
            }
            else {
                dfs(board, i, 0);
                dfs(board, i, columnSize-1);
            }
        }

        for(int i = 0; i < rowSize; ++i) {
            for(int j = 0; j < columnSize; ++j) {
                char & ele = board[i][j];
                if(ele == '-')
                    ele = 'O';
                else if(ele == 'O')
                    ele = 'X';
            }
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
