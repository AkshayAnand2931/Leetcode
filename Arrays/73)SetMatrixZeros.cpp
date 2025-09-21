#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowCount = matrix.size();
        int columnCount = matrix[0].size();
        bool col1 = false;

        for(int i = 0; i < rowCount; i++) {
            for(int j = 0; j < columnCount; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0) col1 = true;
                    else matrix[0][j] = 0;
                }
            }
        }

        for(int i = rowCount - 1; i >= 0; i--) {
            for(int j= columnCount - 1; j >= 0; j--) {
                bool colCondition = j == 0 ? col1 : matrix[0][j] == 0;
                if(matrix[i][0] == 0 || colCondition) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};