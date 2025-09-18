/*
    The problem is convert the given string in lower case alphanumerics,
    and then return if the string is a valid palindrome.
*/
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(!isalnum(s[i])) {
                s.erase(i, 1);
                i--;
            }
            else {
                s[i] = tolower(s[i]);
            }
        }
        int begin = 0;
        int last = s.size() - 1;

        while(begin <= last) {
            if(s[begin] != s[last]) {
                return false;
            }
            begin++;
            last--;
        }
        return true;
    }
};