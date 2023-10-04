#include <string>
#include <unordered_map>
#include <set>

class Solution {
public:
    static unsigned int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, unsigned int> last_occurence;
        unsigned int max_len = 0, base = 0, back = 0;
        for(; back < s.length(); back++){
            if(!(last_occurence.try_emplace(s[back], back)).second){ //detected duplicate -> move window base to the right by 1;
                max_len = std::max(back - base, max_len);
                base = std::max(last_occurence[s[back]] + 1, base); //move base just behind last occurence of s[back]!!
                last_occurence[s[back]] = back; //record new last occurence for later use
            }
        }
        return std::max(back - base, max_len);
    }
};

int main(){
    printf("%d\n", Solution::lengthOfLongestSubstring("abba"));
    return 0;
}