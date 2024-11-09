#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findRelationship(int start, int end, const vector<vector<int>>& relations, int n) {
    vector<int> visited(n + 1, -1); // 방문 여부 및 촌수 기록 (-1: 미방문)
    queue<int> q;

    q.push(start);
    visited[start] = 0; // 시작 지점 촌수 0

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : relations[current]) {
            if (visited[next] == -1) { // 방문하지 않은 노드라면
                visited[next] = visited[current] + 1;
                q.push(next);

                if (next == end) { // 도착 지점에 도달했을 때
                    return visited[next];
                }
            }
        }
    }

    return -1; // 연결되지 않았을 때
}

int main() {
    int n, a, b, m;
    cin >> n >> a >> b >> m;

    vector<vector<int>> relations(n + 1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        relations[x].push_back(y);
        relations[y].push_back(x);
    }

    int result = findRelationship(a, b, relations, n);
    cout << result << endl;

    return 0;
}
