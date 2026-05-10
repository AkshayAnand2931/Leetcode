#include <vector>

using namespace std;

class Solution {
public:
    long long timeTaken(vector<int>&piles, int k) {
        long long time = 0;
        for(const int& pile: piles) {
            if (pile % k == 0)
                time = time + (pile / k);
            else
                time = time + (pile / k) + 1;
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        const int size = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mini = high;

        while(low <= high) {
            long long mid = (low + high) / 2;

            long long time = timeTaken(piles, mid);
            if(time <= h)
                high = mid - 1;
            else
                low = mid + 1;;
        }

        return low;
    }
};