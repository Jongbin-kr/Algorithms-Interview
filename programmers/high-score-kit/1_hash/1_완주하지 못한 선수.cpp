#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// 
// string solution(vector<string> participant, vector<string> completion) {
//     // counter처럼 처리하기 
//     unordered_map<string, int> ctr;
    
//     for (const auto& part : participant){
//         ctr[part]++;
//     }
    
//     for (const auto& comp : completion){
//         ctr[comp]--;
//     }
    
//     // 출력
//     for (const auto& [name, cnt] : ctr){
//         if (cnt > 0) { return name; }
//     }
    
//     return "";
// }