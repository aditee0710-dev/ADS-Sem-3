#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(string infix)
{
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' and ')'
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Create stack
    stack<char> s;

    string postfix = "";

    // Step 4: Convert to postfix
    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }
        else
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) > precedence(c))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    // Step 5: Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    // Step 6: Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Prefix expression: "
         << infixToPrefix(infix);

    return 0;
}