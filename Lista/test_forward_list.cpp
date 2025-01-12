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

void test_pop_back(){
    ForwardList<int> list_empty;
    ForwardList<int> list={1,2,3,4,5};

    try{
        list_empty.pop_back();
        assert(false);
    }catch(const std::out_of_range& e){
        assert(true);
    }

    list.pop_back();
    assert(list.back()==4);

    std::cout<<"test_pop_back passed"<<std::endl;

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

void test_operator_brackets(){
    ForwardList<int> list={1,2,3,4,5};

    assert(list[0]==1);
    assert(list[1]==2);
    assert(list[2]==3);
    assert(list[3]==4);
    assert(list[4]==5);
    
    list[2]=10;
    assert(list[2]==10);

    list.pop_back();

    try{
        list[4];
        assert(false);
    }catch(const std::out_of_range& e){
        assert(true);
    }

    std::cout<<"test_operator_brackets passed"<<std::endl;

}
void test_size() {
    ForwardList<int> list = {1, 2, 3};
    assert(list.size() == 3); 

    list.push_front(0);
    assert(list.size() == 4); 

    list.pop_front();
    assert(list.size() == 3); 

    list.clear();
    assert(list.size() == 0); 

    // Prueba con un objeto constante
    const ForwardList<int> const_list = {4, 5, 6};
    assert(const_list.size() == 3); 
    std::cout << "test_size passed\n";
}

void test_reverse() {

    ForwardList<int> list = {1, 2, 3, 4, 5};
    list.reverse();
    assert(list[0] == 5);
    assert(list[1] == 4);
    assert(list[2] == 3);
    assert(list[3] == 2);
    assert(list[4] == 1);

    std::cout << "test_reverse passed\n";
}

void test_insertionSort() {
    ForwardList<int> list = {5, 2, 4, 3, 1};
    list.insertionSort();
    assert(list[0] == 1);
    assert(list[1] == 2);
    assert(list[2] == 3);
    assert(list[3] == 4);
    assert(list[4] == 5);
    std::cout << "test_insertionSort passed\n";
}

void test_mergeWith() {
    ForwardList<int> list1 = {1, 3, 5};
    ForwardList<int> list2 = {2, 4, 6};
    ForwardList<int> mergedList = list1.mergeWith(list2);
    assert(mergedList[0] == 1);
    assert(mergedList[1] == 2);
    assert(mergedList[2] == 3);
    assert(mergedList[3] == 4);
    assert(mergedList[4] == 5);
    assert(mergedList[5] == 6);
    std::cout << "test_mergeWith passed\n";
}

void test_intersectionWith() {
    ForwardList<int> list1 = {1, 2, 3, 4, 5};
    ForwardList<int> list2 = {3, 4, 5, 6, 7};
    ForwardList<int> intersectionList = list1.intersectionWith(list2);
    assert(intersectionList[0] == 3);
    assert(intersectionList[1] == 4);
    assert(intersectionList[2] == 5);
    std::cout << "test_intersectionWith passed\n";
}

void test_isPalindromo() {
    try {
        ForwardList<int> list1 = {1, 2, 3, 2, 1};
        assert(list1.isPalindromo() == true);
        assert(list1[0] == 1);
        assert(list1[1] == 2);
        assert(list1[2] == 3);
        assert(list1[3] == 2);
        assert(list1[4] == 1);

        ForwardList<int> list2 = {1, 2, 2, 1};
        assert(list2.isPalindromo() == true);
        assert(list2[0] == 1);
        assert(list2[1] == 2);
        assert(list2[2] == 2);
        assert(list2[3] == 1);

        ForwardList<int> list3 = {1, 2, 3};
        assert(list3.isPalindromo() == false);
        assert(list3[0] == 1);
        assert(list3[1] == 2);
        assert(list3[2] == 3);

        ForwardList<int> list4;
        assert(list4.isPalindromo() == true);

        ForwardList<int> list5 = {1};
        assert(list5.isPalindromo() == true);
        assert(list5[0] == 1);

        std::cout << "test_isPalindromo passed\n";
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

int main() {
    test_initializer_list();
    test_push_front();
    test_push_back();
    test_pop_front();
    test_pop_back();
    test_front();
    test_back();
    test_empty();
    test_clear();
    test_size();
    test_operator_brackets();
    test_reverse();
    test_insertionSort();
    test_intersectionWith();
    test_mergeWith();
    test_isPalindromo();
    std::cout << "All tests passed\n";
    return 0;
}
