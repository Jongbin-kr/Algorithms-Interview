#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

int main(){
    
    int N; cin >> N;
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    for (int i=0; i < N; ++i) dist[i][i] = 0;
    while (true){
        int a, b; cin >> a >> b; a -= 1; b-= 1;
        if (a == -2 && b == -2) break;
        dist[a][b] = 1;
        dist[b][a] = 1;
        
    }
    
    
    for (int k=0; k < N; ++k){
        for (int i=0; i < N; ++i){
            for (int j=0; j < N; ++j){
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                    if (dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    
    vector<int> max_dists(N, 0);
    for (int i=0; i < N; ++i){
        int max_dist = 0;
        for (int j=0; j < N; ++j){
            max_dist = max(max_dist, dist[i][j]);
        }
        max_dists[i] = max_dist;
    }
    int min_value = *min_element(max_dists.begin(), max_dists.end());
    
    int min_cnt = 0;
    vector<int> min_idx;
    for (int i=0; i < N; ++i){
        if (max_dists[i] == min_value){
            min_cnt++;
            min_idx.push_back(i+1);
        }
    }
    
    
    cout << min_value << " " << min_cnt << endl;
    for (auto idx : min_idx){ cout << idx << " ";}
    
    return 0;
}