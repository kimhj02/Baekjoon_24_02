#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    while (true) 
    {
        string list;
        getline(cin, list);

        // 종료 조건
        if (list == ".") 
        {
            break;
        }

        stack<char> Stack;
        bool result = true;

        for (char ch : list) 
        {
            if (ch == '(' || ch == '[') 
            {
                Stack.push(ch);
            }
            else if (ch == ')') 
            {
                if (!Stack.empty() && Stack.top() == '(') 
                {
                    Stack.pop();
                }
                else 
                {
                    result = false;
                    break;
                }
            }
            else if (ch == ']') 
            {
                if (!Stack.empty() && Stack.top() == '[') 
                {
                    Stack.pop();
                }
                else 
                {
                    result = false;
                    break;
                }
            }
        }
        if (!Stack.empty()) 
        {
            result = false;
        }

        // 결과 출력
        if (result) 
        {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
