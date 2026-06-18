class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
           int totalApples = 0;
        for (int a : apple) totalApples += a;
        // Sort in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());
        int currentCapacity = 0;
        for (int i = 0; i < capacity.size(); i++) {
            currentCapacity += capacity[i];
            if (currentCapacity >= totalApples) return i + 1;
        }
        return capacity.size();
    }
};