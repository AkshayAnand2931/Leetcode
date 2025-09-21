#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        int min = prices[0];

        for(int i = 1; i < size; i++) {
            int profit = 0;
            if(prices[i] < min) {
                min = prices[i];
            } else {
                profit = prices[i] - min;
            }
            max_profit = max(max_profit, profit);
        }

        return max_profit;
    }
};