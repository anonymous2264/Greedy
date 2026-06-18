class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        // Process indices 0 to n-2; we don't need to jump from the last index
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            // Reached the end of the current BFS level
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
                // Early exit if we can already reach the end
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};