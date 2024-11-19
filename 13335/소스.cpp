#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int truck_num, bridge_length, bridge_weight;
    cin >> truck_num >> bridge_length >> bridge_weight;

    vector<int> truck(truck_num); // 트럭의 무게를 저장
    for (int i = 0; i < truck_num; i++) 
    {
        cin >> truck[i];
    }

    queue<int> bridge; // 다리 위 상태
    int current_weight = 0; // 다리 위 총 무게
    int time = 0; // 경과 시간
    int index = 0; // 대기 중인 트럭의 인덱스

    // 초기화: 다리 길이만큼 0으로 채움
    for (int i = 0; i < bridge_length; i++) 
    {
        bridge.push(0);
    }

    while (!bridge.empty())  //비어 있다면
    {
        time++;

        int exiting_truck = bridge.front();
        bridge.pop();
        current_weight -= exiting_truck;

        if (index < truck_num) 
        {
            if (current_weight + truck[index] <= bridge_weight) 
            {

                bridge.push(truck[index]);
                current_weight += truck[index];
                index++;
            }
            else 
            {

                bridge.push(0);
            }
        }
    }

    cout << time << endl;
    return 0;
}
