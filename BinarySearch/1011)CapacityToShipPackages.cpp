#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int daysRequired(vector<int>& weights, long long weightLimit) {
        int sum = 0;
        int days = 1;

        for(const int& weight : weights) {
            sum = sum + weight;

            if(sum > weightLimit) {
                sum = weight;
                days++;
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high) {
            long long mid = (low + high) / 2;

            if(daysRequired(weights, mid) > days)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};