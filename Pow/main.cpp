#include <iostream>
#include <limits.h>
#include <libFelix.hpp>

class Solution {
public:
    static double myPow(double x, int n) {
        long long int long_n = n < 0 ? -((long long int)n) : n;
        double ret_val = 1.0;
        while(long_n > 0){
            if(long_n & 1){
                ret_val *= x;
            }
            x *= x;
            long_n >>= 1;
        }
        
        return n < 0 ? 1/ret_val : ret_val;
    }
};

int main(){
    std::cout << Solution::myPow(2, -20) << '\n';
}