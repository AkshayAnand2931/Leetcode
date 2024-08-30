/*
    The problem is to find the largest rectangle, that is, the rectangle that has the maximum area in a histogram.
    The modified solution using only a single pass and calculates the area only when item is popped out.
*/

#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        int max_area {0};
        int i {0};
        
        for(; i < heights.size(); i++){

            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                int height = heights[stack.top()];
                stack.pop();
                int width {};
                if(stack.empty()){
                    width = i;
                }
                else {
                    width = i - stack.top() -1;
                }

                int area = width * height;
                max_area = std::max(max_area,area);
            }

            stack.push(i);
        }

        while(!stack.empty()){
            
            int height = heights[stack.top()];
            stack.pop();
            int width {};
            if(stack.empty()){
                width = i;
            }
            else {
                width = i - stack.top() -1;
            }

            int area = width * height;
            max_area = std::max(max_area,area);
        }

        return max_area;
    }
};