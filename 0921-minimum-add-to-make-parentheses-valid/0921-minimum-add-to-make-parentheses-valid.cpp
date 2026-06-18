class Solution {
public:
    int minAddToMakeValid(string s) {
         int unmatchedOpen = 0;
        int unmatchedClose = 0;
        for (char c : s) {
            if (c == '(') {
                unmatchedOpen++;
            } else {
                // Match with an unmatched '(' if available
                if (unmatchedOpen > 0) {
                    unmatchedOpen--;
                } else {
                    unmatchedClose++;
                }
            }
        }
        return unmatchedOpen + unmatchedClose;
    }
};