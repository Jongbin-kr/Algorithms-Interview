#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (const auto& command : commands){
        int i = command[0];
        int j = command[1];
        int k = command[2];
        // vector<int> sub = array[i-1:j];
        vector<int> sub(array.begin() + (i - 1), array.begin() + j);
        sort(sub.begin(), sub.end());
        answer.push_back(sub[k-1]);
        
    }
    return answer;
}