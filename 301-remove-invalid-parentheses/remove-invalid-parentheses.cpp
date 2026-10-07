#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int invalid_l = 0, invalid_r = 0;
        
        // Step 1: Count the minimum number of misplaced '(' and ')' to remove
        for (char c : s) {
            if (c == '(') {
                invalid_l++;
            } else if (c == ')') {
                if (invalid_l > 0) {
                    invalid_l--;
                } else {
                    invalid_r++;
                }
            }
        }

        vector<string> res;
        dfs(0, invalid_l, invalid_r, s, res);
        return res;
    }

private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    void dfs(int start, int l, int r, string str, vector<string>& res) {
        // Base case: no more parenthesis removals needed
        if (l == 0 && r == 0) {
            if (isValid(str)) {
                res.push_back(str);
            }
            return;
        }

        for (int i = start; i < str.length(); ++i) {
            // Skip duplicate adjacent brackets to prevent duplicate results
            if (i > start && str[i] == str[i - 1]) continue;

            if (str[i] == '(' && l > 0) {
                dfs(i, l - 1, r, str.substr(0, i) + str.substr(i + 1), res);
            } else if (str[i] == ')' && r > 0) {
                dfs(i, l, r - 1, str.substr(0, i) + str.substr(i + 1), res);
            }
        }
    }
};