#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int size = s.size();

        unordered_map<char, int> string1 {};
        unordered_map<char, int> string2 {};

        for(int i = 0; i < size; i++) {
            if(string1.find(s[i]) == string1.end())
                string1[s[i]] = i;
            if(string2.find(t[i]) == string2.end())
                string2[t[i]] = i;

            if(string1[s[i]] != string2[t[i]])
                return false;
        }

        return true;
    }
};