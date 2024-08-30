/*
    The two sum problem requires you to find 2 numbers which exactly add up to give the target.
    The brute force solution can be to find every pair and check.
    The optimal solution is to find the number which is needed to add upto the target,
    and look up whether the number exists using hashmap.
*/


#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        std::vector<int> result {};
        std::map<int,int> hashMap;
        std::map<int,int>::iterator iter;

        for(int i = 0; i < nums.size(); i++){
            hashMap[nums[i]] = i; //Store a hashmap for value and the index where it is.
        }

        for(int i = 0; i < nums.size(); i++){
            int required {target - nums[i]};
            iter = hashMap.find(required);

            if((iter != hashMap.end()) && (hashMap[required] != i) ){
                result.push_back(i);
                result.push_back(hashMap[required]);
                break;
            }
        }

        std::sort(result.begin(),result.end());
        return result;
    }
};