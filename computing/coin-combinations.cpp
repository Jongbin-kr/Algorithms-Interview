/*
유사한 문제: https://daddysjourney.tistory.com/92
n개의 서로 다른 동전 종류가 주어질 때, 해당 동전들을 사용해 합이 sum이 되는 모든 경우의 수를 구하라.
•	각 동전은 여러 번 사용 가능
•	동전의 순서가 다르면 다른 경우로 간주함
•	최종 결과는 INT_MAX로 나눈 나머지를 반환 (2,147,483,647)

*/



#include <iostream>
#include <vector>
#include <algorithm>

/*

using namespace std;

long coinCombinations(int n, int sum, vector<int> & coins){   
    // initialize DP table
    vector<long> memo(sum+1, 0);
    memo[0] = 1;   // memo[x]는 x원을 만들 수 있는 경우의 수. 0원은 빈 집합을 통해서 항상 1번 만들 수 있다.
    
    for (int step=1; step <= sum; ++step){
        for (int coin : coins){
            if (step >= coin){ memo[step] +=(memo[step - coin]) % INT_MAX; }
        }
        for(auto m: memo){ std::cout << m << " "; }
        cout << endl;
    }
    
    
    return memo[sum];
}
*/


long coinCombinations(int n, int sum, vector<int> & coins){
    // initialize DP table
    vector<long> memo(sum+1, 0);
    memo[0] = 1;   // memo[x]는 x원을 만들 수 있는 경우의 수. 0원은 빈 집합을 통해서 항상 1번 만들 수 있다.
    
    for (int step=0; step <= sum; ++step){
        for (int idx=0; idx < n; ++idx){
            if (step + coins[idx] <= sum){
                memo[step + coins[idx]] = (memo[step + coins[idx]] + memo[step]) % INT_MAX;
            }
            
        }
        for(auto m: memo){ std::cout << m << " "; }
        cout << endl;
        
    }
    
    return memo[sum];
}




int main(){

    int n = 3,  sum = 4;
    vector<int> coins = {1,2,3};
    

    std::cout << coinCombinations(n, sum, coins) << std::endl;
    
    return 0;
}
