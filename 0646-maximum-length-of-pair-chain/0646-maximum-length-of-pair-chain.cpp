class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort by end value
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int chainEnd = INT_MIN;
        for (const auto& pair : pairs) {
            if (pair[0] > chainEnd) {
                count++;
                chainEnd = pair[1];
            }
        }
        return count;
    }
};