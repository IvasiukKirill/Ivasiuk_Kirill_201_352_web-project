#include <stack>
#include <iostream>
#include <string>

int main()
{
    std::stack<char> st;// объявляем char стек(FILO)

    std::string expr;
    std::cout << "Input expression:";
    std::cin >> expr;
    for (int i = 0; i < expr.size(); i++) {
        switch (expr[i]) {
        case '(':
            st.push(expr[i]);//Функция push () используется для вставки элемента вверху стека
            break;

        case '[':
            st.push(expr[i]);
            break;

        case '{':
            st.push(expr[i]);
            break;

        case ')':
            if (!st.empty()) {//проверка на пустоту
                if (st.top() == '(')//top используется для ссылки на верхний элемент стека 
                    st.pop();//Функция pop () используется для удаления элемента с вершины стека (самый новый элемент в стеке)
            }
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;

        case ']':
            if (!st.empty()) {
                if (st.top() == ']')
                    st.pop();
            }
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;

        case '}':
            if (!st.empty()) {
                if (st.top() == '}')
                    st.pop();
            }
            else {
                std::cout << "Incorrect expression\n";
                return 0;
            }
            break;

        }
    }
    if (!st.empty())
        std::cout << "Incorrect expression\n";
    else
        std::cout << "Correct expression\n";
    return 0;
}