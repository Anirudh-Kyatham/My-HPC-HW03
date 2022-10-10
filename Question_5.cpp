#include<iostream>
#include<stack>
#include<string>

bool solution(std::string& s) {
    std::stack<char> store;
    for (char ch : s) {
        switch (ch)
        {
        case '[':
        case '{':
        case '(':
            store.push(ch);
            break;
        case ']':
            if (store.top() != '[')
                return false;
            store.pop();
            break;
        case '}':
            if (store.top() != '{')
                return false;
            store.pop();
            break;
        case ')':
            if (store.top() != '(')
                return false;
            store.pop();
            break;
        }
    }
    return store.empty();
}


int main(int argc, char const* argv[]) {

    std::string s{ "{{}[]}(" };

    std::cout<< std::boolalpha << solution(s) << std::endl;

    return 0;
}
