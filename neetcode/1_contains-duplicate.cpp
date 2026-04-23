/*
Contains Duplicate
Easy
Topics
Company Tags
Hints
Given an integer array nums, return true if any value appears more than once in
the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true

Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
*/



/*
생각
반복하면서 중복 체크하거나
set으로 풀어도 될 것 같은데 구현을 어떻게?
*/



#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;


// sol 1: comparing the size off set vs. vector
// class Solution {
// public:
//   bool hasDuplicate(vector<int> &nums) {

//     // convert vector into set
//     // 1. set으로 변환 (자동 정렬됨, 탐색/삽입 O(log N))
//     set<int> s(nums.begin(), nums.end());

//     // 2. unordered_set으로 변환 (정렬 안 됨, 파이썬의 set과 가장 유사, 탐색/삽입 O(1))
//     // unordered_set<int> s(nums.begin(), nums.end());

//     // compare size
//     return s.size() != nums.size();
//   }
// };



// sol 2: early stop if duplicated
// class Solution {
// public:
//     bool hasDuplicate(vector<int>& nums) {
        
//         unordered_set<int> seen;
        
//         // for (auto num : nums){         // 매번 값을 복사해서 메모리 낭비
//         for (const auto& num : nums){     // 원본을 참조만 한다
//             if (seen.find(num) == seen.end()){
//             // if (seen.count(num) == 0){
//                 seen.insert(num);
//             }
            
//             else{ 
//                 return true;
//             }
//         }
        
//         return false;
//     }
// };



// sol3: set insert returns pair (iterator, bool)
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (const auto& num : nums){
            if (seen.insert(num).second == false){
                return true;
            }
        }
        
        return false;
    }
};