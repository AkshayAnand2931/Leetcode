#include <vector>

using namespace std;

class Solution {
public:
    bool canMakeBouqets(vector<int>& bloomDay, long long day, int m, int k) {
        int adjacent = 0;
        for(const int& bloom: bloomDay) {
            if(adjacent == k) {
                m--;
                adjacent = 0;
            }

            if(day >= bloom) adjacent++;
            else adjacent = 0;
        }
        if(adjacent == k) m--;
        return m <= 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        const int size = bloomDay.size();
        if((long long)m * k > size) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high) {
            long long mid = (low + high) / 2;

            bool condition = canMakeBouqets(bloomDay, mid, m, k);

            if(condition)
                high = mid - 1;
            else
                low = mid + 1;

        }

        return low;
    }
};