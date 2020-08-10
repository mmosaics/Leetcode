//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。 
//
// 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。 
//
// 
//
// 示例: 
//
// 输入: "25525511135"
//输出: ["255.255.11.135", "255.255.111.35"] 
// Related Topics 字符串 回溯算法 
// 👍 336 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {

private:
    vector<string> ans;
    vector<int> segment;

public:
    vector<string> restoreIpAddresses(string s) {
        segment.resize(4);
        dfs(s, 0, 0);
        return ans;
    }

    const int MAX_COUNT = 4;

    void dfs(string & s, int count, int startIndex) {
        if(count == MAX_COUNT) {
            if(startIndex == s.length()) {
                string tmpIp;
                for(int i = 0; i < 4; ++i) {
                    tmpIp.append(to_string(segment[i]));
                    if(i != 3)
                        tmpIp += '.';
                }
                ans.push_back(tmpIp);
            }
            else
                return;
        }

        //如果三段还没走完，就已经到结束，说明也不行
        if(startIndex >= s.length())
            return;

        //考虑开头是0的特殊情况
        if(count < MAX_COUNT && s[startIndex] == '0') {
            segment[count] = 0;
            dfs(s, count+1, startIndex+1);
        }

        //count小于MAX_COUNT，则需要判断当前这一段是否符合IP地址格式
        if(count < MAX_COUNT) {
            int tmpNum = 0;
            for(int i = 1 ; i < 4; ++i) {
                tmpNum = stoi(s.substr(startIndex, i));
                if(tmpNum > 0 && tmpNum <= 255) {
                    segment[count] = tmpNum;
                    dfs(s, count+1, startIndex+i);
                }
                else
                    return;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
