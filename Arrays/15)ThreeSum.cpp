#include <vector>
#include <set>

using namespace std;

//Hashmap solution which gave TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        const int size = nums.size();

        for(int i = 0; i < size; i++) {
            set<int> hash;
            for(int j = i + 1; j < size; j++) {
                int rem = - (nums[i] + nums[j]);
                if(hash.find(rem) != hash.end()) {
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hash.insert(nums[j]);
            }
        }

        vector<vector<int>> result {st.begin(), st.end()};
        return result;
    }
};

//Two pointer solution
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int size = nums.size();

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < size - 1; i++) {
            int low = i + 1;
            int high = size - 1;

            while(low < high) {
                if(nums[i] + nums[low] + nums[high] < 0)
                    low++;
                else if (nums[i] + nums[low] + nums[high] > 0) 
                    high--;
                else {
                    result.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low < high && nums[low] == nums[low - 1]) low++;
                    while(low < high && nums[high] == nums[high + 1]) high--;
                }
            }
            while(i < size - 1 && nums[i] == nums[i + 1]) i++;
        }
        return result;
    }
};