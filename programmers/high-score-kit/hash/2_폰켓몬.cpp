#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{   
    unordered_set<int> types(nums.begin(), nums.end());
    return min((int)types.size(), (int)nums.size() / 2);
}