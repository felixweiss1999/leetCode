#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<int> searchRange(std::vector<int> &nums, int target)
    {
        if(nums.size() == 0)
            return {-1, -1};
        int upper = nums.size()-1, lower = 0;
        int lower_bound = 0, upper_bound = nums.size();
        while (upper != lower) //first search for lower bound
        {
            int mid = (upper - lower) / 2 + lower;
            if(nums.at(mid) >= target)
                upper = mid;
            else
                lower = mid + 1;
        }
        lower_bound = nums.at(upper) == target ? upper : -1;
        if(lower_bound == -1)
            return {-1, -1};
        upper = nums.size()-1, lower = 0;
        while (upper != lower)
        {
            int mid = (upper - lower + 1) / 2 + lower; //PROBLEM
            if(nums.at(mid) <= target)
                lower = mid;
            else 
                upper = mid-1;
        }
        upper_bound = nums.at(upper) == target ? upper : -1;

        return {lower_bound, upper_bound};
    }
};

int main()
{
    std::vector<int> nums{1};
    std::vector<int> range = Solution::searchRange(nums, 1);
}