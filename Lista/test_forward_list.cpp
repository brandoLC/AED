#include "forward_list.h"
#include <iostream>
#include <cassert>

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.front() == 1);
    list.push_front(2);
    assert(list.front() == 2);
    std::cout << "test_push_front passed\n";
}

void test_push_back() {
    ForwardList<int> list;
    list.push_back(1);
    assert(list.front() == 1);
    list.push_back(2);
    list.pop_front();
    assert(list.front() == 2);
    std::cout << "test_push_back passed\n";
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.pop_front();
    assert(list.front() == 1);
    list.pop_front();
    assert(list.empty());
    std::cout << "test_pop_front passed\n";
}

void test_front() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.front() == 1);
    list.push_front(2);
    assert(list.front() == 2);
    std::cout << "test_front passed\n";
}

void test_empty() {
    ForwardList<int> list;
    assert(list.empty());
    list.push_front(1);
    assert(!list.empty());
    std::cout << "test_empty passed\n";
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.clear();
    assert(list.empty());
    std::cout << "test_clear passed\n";
}

int main() {
    test_push_front();
    test_push_back();
    test_pop_front();
    test_front();
    test_empty();
    test_clear();
    std::cout << "All tests passed\n";
    return 0;
}
