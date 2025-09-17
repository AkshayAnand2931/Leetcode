/*
    The problem is to check if the number is a palindrome or not
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        long num = x;
        long reverse = 0;
        while(num > 0) {
            reverse = reverse * 10;
            reverse = reverse + (num % 10);
            num = num / 10;
        }

        return reverse == x;
    }
};