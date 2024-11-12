#include <iostream>
#include <vector>
using namespace std;

// Ʈ�� ��带 ǥ���ϴ� ����ü ����
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// ���� �˻� Ʈ���� ��带 �����ϴ� �Լ�
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

// ���� ��ȸ�� Ʈ�� ����ϴ� �Լ�
void postOrder(TreeNode* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->value << '\n';
}

int main() {
    TreeNode* root = nullptr; // Ʈ���� ��Ʈ ���
    int num;

    // EOF�� �Է��� �����ϰ� Ʈ�� ����
    while (cin >> num)  //���ǹ����� �Է��� �޾� EOF�� ������ �Է� ����
    {
        if (root == nullptr) 
        {
            root = new TreeNode(num); // ù ��° ������ ��Ʈ ��� ����
        }
        else {
            insert(root, num); // Ʈ���� ��� ����
        }
    }

    // ���� ��ȸ ��� ���
    postOrder(root);

    return 0;
}
