#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0;
    int max_h = 0;
    
    for (auto size : sizes){
        int w = size[0];
        int h = size[1];
        
        if (w < h){
            int temp = w;
            w = h;
            h = temp;
        }
        
        max_w = max(w, max_w);
        max_h = max(h, max_h);
    }
    
    int answer = max_w * max_h;
    return answer;
}