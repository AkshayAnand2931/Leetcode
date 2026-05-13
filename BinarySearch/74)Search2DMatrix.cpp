#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        const int columns = matrix[0].size();

        int low = 0;
        int high = (rows * columns) - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int row = mid / columns;
            int column = mid % columns; 

            if(matrix[row][column] == target)
                return true;

            if(target > matrix[row][column])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};