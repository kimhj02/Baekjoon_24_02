#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[8001]; // 그래프 인접 리스트 (노드, 가중치)

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start); // (거리, 노드)

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int cur_dist = current.first;  // 현재 거리
        int cur_node = current.second; // 현재 노드

        if (cur_dist > dist[cur_node]) continue;

        for (const pair<int, int>& neighbor : graph[cur_node]) 
        {
            int next_node = neighbor.first;
            int weight = neighbor.second;

            if (cur_dist + weight < dist[next_node]) {
                dist[next_node] = cur_dist + weight;
                pq.emplace(dist[next_node], next_node);
            }
        }
    }
    return dist;
}


int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // 양방향 그래프
    }

    int v1, v2;
    cin >> v1 >> v2;

    // 다익스트라로 각 경로의 최소 거리 계산
    vector<int> dist_from_1 = dijkstra(1, n);  // 1번에서 시작
    vector<int> dist_from_v1 = dijkstra(v1, n); // v1에서 시작
    vector<int> dist_from_v2 = dijkstra(v2, n); // v2에서 시작

    // 1 -> v1 -> v2 -> N
    long long path1 = (long long)dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[n];

    // 1 -> v2 -> v1 -> N
    long long path2 = (long long)dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[n];

    // 최단 경로 계산
    long long result = min(path1, path2);
    if (result >= INF) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
