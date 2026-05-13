#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int rows = matrix.size();
        const int columns = matrix[0].size();

        int row = 0;
        int column = columns - 1;

        while(row < rows && column >= 0) {
            if(matrix[row][column] == target)
                return true;

            if(target > matrix[row][column])
                row = row + 1;
            else
                column = column - 1;
        }

        return false;
    }
};