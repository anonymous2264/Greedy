class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0') return false;
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int farthest = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            // Start scanning from where we left off to avoid redundant work
            int start = max(i + minJump, farthest + 1);
            int end = min(i + maxJump, n - 1);
            for (int j = start; j <= end; j++) {
                if (s[j] == '0') {
                    visited[j] = true;
                    q.push(j);
                }
            }
            farthest = max(farthest, i + maxJump);
        }
        return visited[n - 1];
    }
};