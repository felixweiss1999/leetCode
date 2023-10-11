#include <vector>
#include <algorithm>
#include <iostream>
class Solution
{
public:
    static int minOperations(std::vector<int> &nums)
    {
        // handle special case that nums only contains one number:
        if (nums.size() == 1)
            return 0;
        std::sort(nums.begin(), nums.end());
        // search for continuous sequence
        int seq_len = 1, max_seq_len = 1;
        for (auto it = ++nums.begin(); it != nums.end(); it++)
        {
            if (*it - *(it - 1) == 1)
            {
                seq_len++;
            }
            else
            {
                max_seq_len = std::max(max_seq_len, seq_len);
                seq_len = 1;
            }
        }
        return nums.size() - std::max(max_seq_len, seq_len);
    }
};

int main()
{
    std::vector<int> nums{1,2,3,5,6};
    std::cout << Solution::minOperations(nums) << '\n';
    return 0;
}

/*
    General approach:
        1. Sort vector
        2. Find longest continuous subarray, then simply count number of other elements (would have to replace those to get to a continues version)
            i.e. return nums.size() - subarray.size()

        The above approach does not take into account potential filling of holes in the sorted array by sacrificing other elements -> hard
*/