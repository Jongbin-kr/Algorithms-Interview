#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(){
    
    int n_operations; cin >> n_operations;
    vector<int> operations;
    for (int i=0; i < n_operations; ++i){
        int operation; cin >> operation;
        operations.push_back(operation);
    }
    
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<>> pq;
    for (auto operation : operations){
        if (operation == 0){
            if (pq.empty()) {cout << 0 << endl;}
            else{
                auto [priority, value] = pq.top(); pq.pop();    
                cout << value << endl;
            }
        }
        else{
            float priority = abs(operation);
            if(operation < 0){ priority -= 0000.1; }
            pq.push({priority, operation});
        }
    }   
}