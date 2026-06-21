class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> f(100001);
        for(auto c:costs)
        {
            f[c]++;
        }
        int k=0;
        for(int cost=1;cost<=100000;cost++)
        {
            if(f[cost]==0)
            continue;
            if(coins<cost)
            break;
            int take=min(f[cost],coins/cost);
            k+=take;
            coins-=take*cost;

        }
        return k;
        
    }
};