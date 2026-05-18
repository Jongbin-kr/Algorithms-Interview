#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int findNumbers(vector<int> &nums) {
    int n_evens = 0;
    for (auto &num : nums) {
      if (to_string(num).size() % 2 == 0) {
        n_evens++;
      }
    }

    return n_evens;
  }
};