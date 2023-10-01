#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>
#include "libFelix.hpp"

class MaxSubArraySolver{
public:
    
    void runTests(){
        std::vector<std::vector<int>> test_suite = {Felix::VectorGenerator::getUniformVec(100, -10, 10), Felix::VectorGenerator::getUniformVec(100000, -10, 10), Felix::VectorGenerator::getUniformVec(100000000, -10, 10)};
        for(auto test : test_suite){
            linearSolution(test);
            betterSolution(test);
        }
    }
    int linearSolution(const std::vector<int>& nums){
        Felix::Timer _t("linearSolution");
        auto forward_it = nums.begin();
        auto reverse_it = nums.end();
        reverse_it--;
        int current_sum = std::accumulate(nums.begin(), nums.end(), 0);
        int largest_sum = current_sum;
        while(forward_it != reverse_it){
            if((*forward_it) < (*reverse_it)){
                current_sum -= *forward_it;
                largest_sum = std::max(current_sum, largest_sum);
                forward_it++;
            } else {
                current_sum -= *reverse_it;
                largest_sum = std::max(current_sum, largest_sum);
                reverse_it--;
            }
        }
        return largest_sum;
    }

    int betterSolution(const std::vector<int>& nums){
        Felix::Timer _t("betterSolution");
        int maxSum = INT_MIN;
        int currentSum = 0;
        
        for (long unsigned int i = 0; i < nums.size(); i++) {
            currentSum += nums[i];
            
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        
        return maxSum;
    }
};


int main(){
    MaxSubArraySolver s;
    s.runTests();
}