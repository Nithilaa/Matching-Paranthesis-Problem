#include <iostream>
#include <stack>
using namespace std;

void matching_parentheses();

int main()
{
    cout << "Enter number of times you want to check : ";
    int times;
    cin >> times;

    for (int i = 0; i < times; i++) {
        matching_parentheses();
    }

    return 0;
}

void matching_parentheses()
{
    stack<char> a;
    string s;
    cout << "Enter the string you want to check : ";
    cin >> s;

    int check = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            a.push(s[i]);
            check = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    if ((a.empty()) && (check == 1))
        cout << "MATCHING" << endl;
    else
        cout << "NOT MATCHING" << endl;
}
