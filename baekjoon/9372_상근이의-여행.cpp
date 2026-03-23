#include <iostream>
#include <queue>
#include <climits>

using namespace std;


vector <int> primMST(const vector<vector<pair<int, int>>>& graph){
    int n_vertexs = graph.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> inMST(n_vertexs, false);
    vector <int> min_weights(n_vertexs, INT_MAX);
    
    min_weights[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()){
        int curr_node = pq.top().second;
        pq.pop();
        
        if (inMST[curr_node]) continue;
        inMST[curr_node] = true;
        
        for (auto [weight, adj_node]: graph[curr_node]){
            if (!inMST[adj_node] && weight < min_weights[adj_node]){
                min_weights[adj_node] = weight;
                pq.push({weight, adj_node});
            }
        }
    }
    
    return min_weights;
}


int main(){
    int T_testcases; cin >> T_testcases;
    
    for (int t=0; t < T_testcases; ++t){
        int N_countries; int M_flights;
        cin >> N_countries >> M_flights;
        
        // initialize graph
        vector<vector<pair<int, int>>> graph(N_countries, vector<pair<int, int>>());
        for (int m=0; m < M_flights; ++m){
            int a; int b; cin >> a >> b; a -= 1; b -= 1; 
            graph[a].push_back({1, b});
            graph[b].push_back({1, a});
        }
        
        
        vector<int> min_weights = primMST(graph);
        
        int result = 0;
        for (int weight: min_weights){
            result += weight;
        }
        cout << result << endl;
        
    }
    
    return 0;
}