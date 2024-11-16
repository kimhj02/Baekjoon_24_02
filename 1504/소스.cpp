#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[8001]; // �׷��� ���� ����Ʈ (���, ����ġ)

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.emplace(0, start); // (�Ÿ�, ���)

    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        pq.pop();

        int cur_dist = current.first;  // ���� �Ÿ�
        int cur_node = current.second; // ���� ���

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
        graph[v].emplace_back(u, w); // ����� �׷���
    }

    int v1, v2;
    cin >> v1 >> v2;

    // ���ͽ�Ʈ��� �� ����� �ּ� �Ÿ� ���
    vector<int> dist_from_1 = dijkstra(1, n);  // 1������ ����
    vector<int> dist_from_v1 = dijkstra(v1, n); // v1���� ����
    vector<int> dist_from_v2 = dijkstra(v2, n); // v2���� ����

    // 1 -> v1 -> v2 -> N
    long long path1 = (long long)dist_from_1[v1] + dist_from_v1[v2] + dist_from_v2[n];

    // 1 -> v2 -> v1 -> N
    long long path2 = (long long)dist_from_1[v2] + dist_from_v2[v1] + dist_from_v1[n];

    // �ִ� ��� ���
    long long result = min(path1, path2);
    if (result >= INF) cout << -1 << endl;
    else cout << result << endl;

    return 0;
}
