#include"header.hpp"
static bool checkparentheses(std::string in);
static bool is_p(char s);
static bool is_operator(std::string str);

bool is_infix(std::string in)
{
    if (!checkparentheses(in))
    {
        return false;
    }
    for (auto &i : in)
    {
        if (is_p(i))
        {
            i = ' ';
        }
    }
    Stack st(in);
    std::string t = st.pop();
    if (is_operator(t))
    {
        return false;
    }
    bool op = true;
    while (!st.isEmpty())
    {
        t = st.pop();
        if (is_operator(t) != op)
        {
            return false;
        }
        op = !op;
    }
    return true;
}
static bool is_p(char s)
{
    return (s == '(' || s == ')');
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
static bool checkparentheses(std::string in)
{
    Stack st(in);
    Stack p;
    while (!st.isEmpty())
    {
        std::string t = st.pop();
        if (t == "(")
        {
            p.push(t);
        }
        else if (t == ")")
        {
            t = p.pop();
            if (!(t == "("))
            {
                return false;
            }
        }
    }
    if (p.isEmpty())
    {
        return true;
    }
    return false;
}
// int main(int argc, char const *argv[])
// {

//     std::cout << is_infix("( ( ( 1  +  ( 25  + + 6 ) ) ) )");
//     return 0;
// }