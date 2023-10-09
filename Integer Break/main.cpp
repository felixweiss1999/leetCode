#include <iostream>
#include <cmath>
class Solution
{
public:
    static int integerBreak(int n)
    {
        int k = (int)std::exp(std::log(n) - 1);
        std::cout << k;
        return (int)std::pow((int)n / k, k - (n % k)) * (int)std::pow((int)((double)n / k + 1.0), n % k);
    }
    // next step: round k up and down, return max result of both
    static int integerBreakDumb(int n)
    {
        int max = 0;
        for (int k = 2; k <= n; k++)
        {
            max = std::max(max, (int)std::pow((int)n / k, k - (n % k)) * (int)std::pow((int)((double)n / k + 1.0), n % k));
        }
        return max;
    }
};

int main()
{
    std::cout << Solution::integerBreak(10) << '\n';
    std::cout << Solution::integerBreakDumb(10) << '\n';

}