#include <array>
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 128> lastIndex;
        lastIndex.fill(-1);
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            left = max(left, lastIndex[s[right]] + 1);
            maxLen = max(maxLen, right - left + 1);
            lastIndex[s[right]] = right;
        }

        return maxLen;
    }
};

