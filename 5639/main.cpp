#include <iostream>
#include <vector>
using namespace std;

// 트리 노드를 표현하는 구조체 정의
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 이진 검색 트리에 노드를 삽입하는 함수
TreeNode* insert(TreeNode* node, int value) 
{
    if (node == nullptr) 
    {
        return new TreeNode(value);
    }
    if (value < node->value) 
    {
        node->left = insert(node->left, value);
    }
    else 
    {
        node->right = insert(node->right, value);
    }
    return node;
}

// 후위 순회로 트리 출력하는 함수
void postOrder(TreeNode* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << '\n';
}

int main() {
    TreeNode* root = nullptr; // 트리의 루트 노드
    int num;

    // EOF로 입력을 중지하고 트리 구축
    while (cin >> num)  //조건문에서 입력을 받아 EOF가 나오면 입력 중지
    {
        if (root == nullptr) 
        {
            root = new TreeNode(num); // 첫 번째 값으로 루트 노드 설정
        }
        else {
            insert(root, num); // 트리에 노드 삽입
        }
    }

    // 후위 순회 결과 출력
    postOrder(root);

    return 0;
}
