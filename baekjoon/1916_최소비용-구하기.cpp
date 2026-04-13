#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const int INF = 1e9;

int main() {
  // testcase
//   string tc = R"(5
// 8
// 1 2 2
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3
// 1 5)";

//   stringstream cin(tc);

  // input
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N_cities, M_buses;
  cin >> N_cities;
  cin >> M_buses;

  //   vector<pair<int, int>> buses[N_cities + 1];   // [] 안에는 상수로 입력을
  //   받는다.
  vector<vector<pair<int, int>>> buses(N_cities + 1);
  for (int i = 0; i < M_buses; i++) {
    int from_node, to_node, dist;
    cin >> from_node >> to_node >> dist;
    buses[from_node].push_back(pair<int, int>(dist, to_node));
  }

  int start, target;
  cin >> start >> target;

  // dijkstra
  vector<int> min_dists(N_cities + 1, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      to_visit;
  to_visit.push({0, start});
  min_dists[start] = 0;

  while (!to_visit.empty()) {
    int current_dist = to_visit.top().first;
    int current_node = to_visit.top().second;
    to_visit.pop();

    if (min_dists[current_node] < current_dist) {
      continue;
    }

    for (auto to_dist_to_node : buses[current_node]) {
      // for (auto& [to_dist, to_node] : buses[current_node]) {
      int to_dist = to_dist_to_node.first;
      int to_node = to_dist_to_node.second;

      int detouring_dist = current_dist + to_dist;

      if (detouring_dist < min_dists[to_node]) {
        min_dists[to_node] = detouring_dist;
        to_visit.push({detouring_dist, to_node});
      }
    }
  }

  cout << min_dists[target];
}