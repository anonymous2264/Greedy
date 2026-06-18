class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first1, first2, second1, second2;
        int highPoints, lowPoints;
        if (x >= y) {
            first1 = 'a'; first2 = 'b'; highPoints = x;
            second1 = 'b'; second2 = 'a'; lowPoints = y;
        } else {
            first1 = 'b'; first2 = 'a'; highPoints = y;
            second1 = 'a'; second2 = 'b'; lowPoints = x;
        }
        int score = 0;
        // Pass 1: remove the higher-value pair
        vector<char> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back() == first1 && c == first2) {
                stack.pop_back();
                score += highPoints;
            } else {
                stack.push_back(c);
            }
        }
        // Pass 2: remove the lower-value pair from leftovers
        vector<char> remaining = stack;
        stack.clear();
        for (char c : remaining) {
            if (!stack.empty() && stack.back() == second1 && c == second2) {
                stack.pop_back();
                score += lowPoints;
            } else {
                stack.push_back(c);
            }
        }
        return score;
    }
};