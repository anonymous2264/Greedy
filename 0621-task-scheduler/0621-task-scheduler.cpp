class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
          vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        // Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());
        // Count how many tasks share the maximum frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) maxCount++;
        }
        // Formula: (maxFreq - 1) blocks of size (n + 1) + final block of maxCount
        int formulaResult = (maxFreq - 1) * (n + 1) + maxCount;
        // Answer is at least the total number of tasks
        return max((int)tasks.size(), formulaResult);
    }
};