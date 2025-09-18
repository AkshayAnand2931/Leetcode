/*
    The problem is to generate the fibonacci number for n
*/

#include<vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
        vector<int> vec;
        
        vec.push_back(0);
        vec.push_back(1);

        for(int i = 2; i <= n; i++) {
            int nextFib = vec[i - 1] + vec[i - 2];
            vec.push_back(nextFib);
        }

        return vec[n];
    }
};