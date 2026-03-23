#include <vector>
#include <numeric>
using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        for (const auto& account : accounts){
            int wealth = accumulate(account.begin(), account.end(), 0);
            
            if (wealth > max_wealth){max_wealth = wealth;}
        }
        
        return max_wealth;

    }
};