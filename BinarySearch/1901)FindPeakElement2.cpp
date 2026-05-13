#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int rows = mat.size();
        const int columns = mat[0].size();

        int low = 0;
        int high = rows - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            pair<int, int> ans = maxElementInRow(mat, mid, columns);
            int max = ans.first;
            int column = ans.second;

            int up = mid - 1 >= 0 ? mat[mid - 1][column] : -1;
            int down = mid + 1 < rows ? mat[mid + 1][column] : -1;

            if(mat[mid][column] > up && mat[mid][column] > down)
                return {mid, column};

            if(mat[mid][column] < up)
                high = mid - 1;
            else
                low = mid + 1;

        }

        return {-1, -1};
    }

private:
    pair<int, int> maxElementInRow(vector<vector<int>>& mat, int row, int columns) {
        int max = mat[row][0];
        int idx = 0;

        for(int i = 1; i < columns; i++) {
            if(mat[row][i] > max) {
                max = mat[row][i];
                idx = i;
            }
        }

        return {max, idx};
    }
};