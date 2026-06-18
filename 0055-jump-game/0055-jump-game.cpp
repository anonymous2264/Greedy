class Solution {
public:
    bool canJump(vector<int>& nums) {
      int goal = nums.size() - 1;
        // Work backwards: can each index reach the current goal?
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }
        return goal == 0;
    }
};