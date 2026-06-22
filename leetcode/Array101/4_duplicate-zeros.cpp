/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:

Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 9
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        // find the actual last element
        int read = 0; // 다음에 읽을 후보의 위치
        int len = 0; // 복제까지 고려했을 때 차지하는 길이
        int idx = -1; // 실질적으로 읽는 후보
        
        while (read < arr.size() && len < arr.size()){
            idx = read;
            if (arr[read] == 0){
                len += 2;
            }
            else{
                len += 1;
            }
            read ++;
        }
        
        // replace the element
        for (int i=arr.size()-1; i>=0 ; i--){
            if (arr[idx] == 0){
                arr[i] = 0;
                arr[i-1] = 0;
                idx--;
                i--;
            }
            else{
                arr[i] = arr[idx];
                idx--;
            }
        }
    }
};