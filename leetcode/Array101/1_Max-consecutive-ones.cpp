#include <vector>
using namespace std;

class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int max_streak = 0;
    int curr_streak = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        curr_streak++;
        max_streak = max(max_streak, curr_streak);
      } else {
        curr_streak = 0;
      }
    }

    return max_streak;
  }
};