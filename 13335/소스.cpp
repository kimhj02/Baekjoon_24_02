#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    int truck_num, bridge_length, bridge_weight;
    cin >> truck_num >> bridge_length >> bridge_weight;

    vector<int> truck(truck_num); // Ʈ���� ���Ը� ����
    for (int i = 0; i < truck_num; i++) 
    {
        cin >> truck[i];
    }

    queue<int> bridge; // �ٸ� �� ����
    int current_weight = 0; // �ٸ� �� �� ����
    int time = 0; // ��� �ð�
    int index = 0; // ��� ���� Ʈ���� �ε���

    // �ʱ�ȭ: �ٸ� ���̸�ŭ 0���� ä��
    for (int i = 0; i < bridge_length; i++) 
    {
        bridge.push(0);
    }

    while (!bridge.empty())  //��� �ִٸ�
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
