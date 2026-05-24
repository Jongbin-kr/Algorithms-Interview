#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> res;   // 이렇게 하면 빈 벡터.
//         // vector<int> res(nums.size());  이렇게 하면 0으로 채워진 벡터가 만들어짐. 
        
        
//         for (auto num : nums){
//             res.push_back(num * num);
//         }
        
//         sort(res.begin(), res.end());
        
        
//         return res;
//     }
// };



// 투 포인터로 구현
// 핵심은 left, right 포인터. 배열 자체를 바꾸진 말자.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;   // 이렇게 하면 빈 벡터.
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right){
            int l_sqrd = nums[left] * nums[left];
            int r_sqrd = nums[right] * nums[right];
            
            if (l_sqrd <= r_sqrd){
                res.push_back(r_sqrd);
                right --;
            } else {
                res.push_back(l_sqrd);
                left ++;
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};