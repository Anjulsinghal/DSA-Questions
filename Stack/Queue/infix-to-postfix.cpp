// GFG infix-to-postfix

// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

class Solution
{
public:
    int priorty(char opr)
    {
        if (opr == '^')
            return 3;
        else if (opr == '*' || opr == '/')
            return 2;
        else if (opr == '+' || opr == '-')
            return 1;
        else
            return -1;
    }

public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        stack<char> st; // For stack operations, we are using C++ built in stack
        string result;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            // If the scanned character is
            // an operand, add it to output string.
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
                result += c;

            // If the scanned character is an
            // ‘(‘, push it to the stack.
            else if (c == '(')
                st.push('(');

            // If the scanned character is an ‘)’,
            // pop and to output string from the stack
            // until an ‘(‘ is encountered.
            else if (c == ')')
            {
                while (st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                st.pop();
            }

            // If an operator is scanned
            else
            {
                while (!st.empty() && priorty(s[i]) <= priorty(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop all the remaining elements from the stack
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }

        //   cout << "Prefix expression: " << result << endl;
        return result;
    }
};