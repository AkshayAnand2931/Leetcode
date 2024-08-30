/*
    The problem is to find the largest rectangle, that is, the rectangle that has the maximum area in a histogram.
    The solution is to find the previous smallest and next smallest elements and use them to calculate 
    the width of the rectangle.
    The previous smallest and next smallest element are found using monotonic stack.
*/

#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> stack;
        std::vector<int> left_small(heights.size(),0);
        std::vector<int> right_small(heights.size(),0);

        for(int i {0}; i < heights.size(); i++){

            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }

            if(stack.empty()){
                left_small[i] = 0;
            }
            else {
                left_small[i] = stack.top() + 1;
            }
            stack.push(i);
        }

        while(!stack.empty()){
            stack.pop();
        }

        for(int i {(int)heights.size() - 1}; i >= 0; i--){

            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }

            if(stack.empty()){
                right_small[i] = heights.size() - 1;
            }
            else {
                right_small[i] = stack.top() - 1;
            }
            stack.push(i);
        }
        
        int max_area{0};
        for(int i {0}; i < heights.size(); i++){
            max_area = std::max(max_area, heights[i] * (right_small[i] - left_small[i] + 1));
        }

        return max_area;
    }
};