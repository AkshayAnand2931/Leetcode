#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        
        std::vector<int> left_max(height.size(),0);
        std::vector<int> right_max(height.size(),0);

        int max = 0;
        for(int i {0}; i < height.size(); i++){
            left_max[i] = max;
            if(height[i] > max){
                max = height[i];
            }
        }

        max = 0;
        for(int i {(int)height.size() - 1}; i >= 0; i--){
            right_max[i] = max;
            if(height[i] > max){
                max = height[i];
            }
        }

        int result {0};
        for(int i {0}; i < height.size(); i++){
            int possible_height = std::min(left_max[i],right_max[i]);

            if(possible_height > height[i]){
                result = result + (possible_height - height[i]);
            }
        }

        return result;
    }
};