#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string result {};

        for(const char chr : s) {
            if(chr == '(') {
                counter++;
                if(counter > 1) result = result + chr;
            }     
            if(chr == ')') {
                counter--;
                if(counter > 0) result = result + chr;
            }
                
        }

        return result;
    }
};