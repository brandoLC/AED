#include "forward_list.h"
#include <iostream>
#include <cassert>


void test_initializer_list() {
    ForwardList<int> list = {1, 2, 3, 4, 5};

    assert(list.front() == 1);
    assert(list.back() == 5);

    list.pop_front();
    assert(list.front() == 2);

    std::cout << "test_initializer_list passed\n";
}


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

void test_back() {
    ForwardList<int> list={1,3,5,2,4};
    assert(list.back()==4);
    list.push_back(5);
    assert(list.back()==5);
    std::cout << "test_back passed"<<std::endl;
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
    test_initializer_list();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_front();
    test_back();
    test_empty();
    test_clear();
    std::cout << "All tests passed\n";
    return 0;
}
