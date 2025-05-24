#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

int main()
{
    string expr = "a+(b*c-(d/e^f)*g)*h";
    stack<char> st;
    string postfix = "";

    for (char ch : expr)
    {
        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(ch) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
