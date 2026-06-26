#include <iostream>
#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <vector>
#include "MutantStack.hpp"

int main()
{
    std::cout << "===== BASIC FUNCTIONALITY =====" << std::endl;

    MutantStack<int> st;

    st.push(1);
    st.push(56);
    st.push(11);
    st.push(37);
    st.push(41);
    st.push(89);
    st.push(101);

    std::cout << "Top: " << st.top() << std::endl;
    std::cout << "Size: " << st.size() << std::endl;

    std::cout << "\n===== ITERATION TEST =====" << std::endl;

    for (MutantStack<int>::iterator it = st.begin();
         it != st.end();
         ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "\n===== COPY TEST =====" << std::endl;

    MutantStack<int> copy = st;

    copy.push(999);

    std::cout << "Original top: " << st.top() << std::endl;
    std::cout << "Copy top: " << copy.top() << std::endl;

    std::cout << "\n===== POP TEST =====" << std::endl;

    st.pop();
    std::cout << "After pop top: " << st.top() << std::endl;
    std::cout << "After pop size: " << st.size() << std::endl;

    std::cout << "\n===== EMPTY STACK TEST =====" << std::endl;

    MutantStack<int> empty;

    std::cout << "Empty size: " << empty.size() << std::endl;

    if (empty.begin() == empty.end())
        std::cout << "Iterator range is empty (correct)" << std::endl;

    std::cout << "\n===== SINGLE ELEMENT EDGE CASE =====" << std::endl;

    MutantStack<int> one;

    one.push(42);

    std::cout << "Begin == end? " << (one.begin() == one.end()) << std::endl;
    std::cout << "Value: " << *one.begin() << std::endl;

    std::cout << "\n===== CONST ITERATOR TEST =====" << std::endl;

    const MutantStack<int> constStack(st);

    std::cout << "Const begin: " << *constStack.begin() << std::endl;

    std::cout << "\n===== STACK BEHAVIOR TEST =====" << std::endl;

    std::stack<int> s(st);

    std::cout << "Std stack top: " << s.top() << std::endl;
    std::cout << "Std stack size: " << s.size() << std::endl;

    std::cout << "\n===== BOUNDARY ITERATOR TEST =====" << std::endl;

    MutantStack<int>::iterator it = st.end();
    --it;

    std::cout << "Last element via --end(): " << *it << std::endl;

    return 0;
}
