#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);
        for(int i = 0; i < numRows; i++) {
            pascal[i] = vector<int>(i + 1);
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
                }
            }
        }

        return pascal;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i = 1; i <= numRows; i++) {
            result.push_back(generateRow(i));
        }

        return result;
    }

    vector<int> generateRow(int row) {
        vector<int> result;
        int ans = 1;
        result.push_back(ans);

        for(int i = 1; i < row; i++) {
            ans = ans * (row - i);
            ans = ans / i;
            result.push_back(ans);
        }
        return result; 
    }
};