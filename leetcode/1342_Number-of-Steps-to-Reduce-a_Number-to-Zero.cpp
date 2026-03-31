/*
Given an integer num, return the number of steps to reduce it to zero.
In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/


#include <iostream>

class Solution {
public:
    int numberOfSteps(int num) {
        
        int cnt = 0;
        while (num != 0){
            if (num % 2 == 0){ num /= 2; cnt++; }
            else { num -= 1; cnt ++; }
            
        }
        
        return cnt;
    }
};

int main(){
    Solution sol;
    
    int testCases[] = {14, 8, 123};
    for (int num : testCases){
        std::cout << num << ": " << sol.numberOfSteps(num) << "\n";
    }
    
    return 0;
}


/*
14 -> 7 -> 6 -> 3 -> 2 -> 1
0    1    2    3    4    5
*/