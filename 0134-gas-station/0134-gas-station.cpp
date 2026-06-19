class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int totalGain = 0;
        int currentTank = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            totalGain += gain;
            currentTank += gain;
            // If tank drops below zero, current start can't work
            // Skip to i + 1 as the new candidate
            if (currentTank < 0) {
                start = i + 1;
                currentTank = 0;
            }
        }
        // If total gas < total cost, no solution exists
        return totalGain >= 0 ? start : -1;
    }
};