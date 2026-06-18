class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childidx=0;
        int cookieidx=0;
        while(childidx < (int)g.size() && cookieidx < (int)s.size())
        {
            if(s[cookieidx]>=g[childidx])
            childidx++;
            cookieidx++;
        }
        return childidx;
    }
};