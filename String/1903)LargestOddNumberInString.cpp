#include <string>

using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        const int size = num.size();
        string result {""};
        
        int idx = size - 1;
        while(idx >= 0) {
            int digit = num[idx] - '0';
            if(digit % 2 == 1)
                break;
            idx--;
        }

        result = num.substr(0, idx + 1);

        return result;
    }
};