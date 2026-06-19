class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
                  // Sort by height descending; if same height, by k ascending
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        vector<vector<int>> queue;
        // Insert each person at their k index
        for (auto& person : people) {
            queue.insert(queue.begin() + person[1], person);
        }
        return queue;
    }
};