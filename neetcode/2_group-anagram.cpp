#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> seen;
    for (const string &st : strs) {
      // c++에서는 string을 포함한 모든 객체들이 mutable하므로, 복사본을
      // 만들어서 정렬 수행. 파이썬은 =로 하면 referencing하지만, c++은
      // 복사한다. 복사를 피하려면 &
      string key = st;
      sort(key.begin(), key.end());
      seen[key].push_back(st);
    }

    vector<vector<string>> res;
    for (auto &pair : seen) {
      res.push_back(pair.second);
    }

    return res;
  }
};
