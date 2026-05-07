#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const long long size = grid.size();
        const long long length = size * size;

        long long expectedSum = (length) * (length + 1) / 2;
        long long expectedSquare = (length) * (length + 1) * (2*length + 1) / 6;
        
        long long actualSum = 0;
        long long actualSquare = 0;

        for(int i  = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                actualSum += grid[i][j];
                actualSquare += (long long)grid[i][j] * grid[i][j];
            }
        }

        long long diff = actualSum - expectedSum;
        long long sum = (actualSquare - expectedSquare) / diff;

        vector<int> result {(int)(sum + diff) / 2, (int)(sum - diff) / 2};
        return result;
    }
};