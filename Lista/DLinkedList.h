//
// Created by brando on 1/13/25.
//

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <initializer_list>
#include <stdexcept>
#include <cstddef>
#include <functional>

template<typename T>
class DLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        explicit Node(const T& data) : data(data), next(nullptr), prev(nullptr){}
    };
    Node* head;
    Node* tail;
public:
    class iterator {
        Node* current;
        DLinkedList* list;
    public:
        iterator(Node* node,DLinkedList* list):current(node),list(list){}
        T& operator*() {
            if (!current) throw std::out_of_range("Dereferencing end iterator");
            return current->data;
        }
        iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        iterator& operator--() {
            if (!current){

                if (!list || !list->tail) throw std::out_of_range("Cannot decrement end() in an empty list");
                current=list->tail;
            }else {
                if (current == nullptr || current->prev == nullptr) {
                    throw std::out_of_range("Iterator cannot be decremented past the beginning of the list");
                }
                current = current->prev;
            }
            return *this;
        }
        bool operator==(const iterator& other) const {
            return current == other.current;
        }
        bool operator!=(const iterator& other) const {
            return current != other.current;
        }
    };
    DLinkedList() : head(nullptr), tail(nullptr) {}
    DLinkedList(std::initializer_list<T> init_list);
    ~DLinkedList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    const T& front() const;
    const T& back() const;
    std::size_t size() const;
    bool empty() const;
    void clear();
    void reverse();
    T& operator[](int index);
    const T& operator[](int index) const;
    iterator begin(){return iterator(head,this);}
    iterator end(){return iterator(nullptr,this);}

};

template<typename T>
DLinkedList<T>::DLinkedList(std::initializer_list<T> init_list):head(nullptr), tail(nullptr) {
    for ( const T& value : init_list) {
        push_back(value);
    }
}

template<typename T>
DLinkedList<T>::~DLinkedList() {
    clear();
}

template<typename T>
void DLinkedList<T>::push_front(const T &value) {
    Node* newNode = new Node(value);
    if (!head && !tail) {
        head =newNode;
        tail = newNode;
    }else {
        newNode->next = head;
        head->prev =newNode;
        head = newNode;
    }
}

template<typename T>
void DLinkedList<T>::reverse() {
    if (!head) return;

    std::function<Node*(Node*)> reverse_list = [&](Node* node) -> Node* {
        if (!node || !node->next) {
            return node;
        }
        Node* newHead = reverse_list(node->next);
        node->next->next = node;
        node->prev=node->next;
        node->next = nullptr;
        return newHead;
    };

    tail = head;
    head = reverse_list(head);
    head->prev=nullptr;
    tail->next = nullptr;
}


template<typename T>
void DLinkedList<T>::push_back(const T &value) {
    Node* newNode = new Node(value);
    if (!head && !tail) {
        head=newNode;
        tail = newNode;
    }else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template<typename T>
const T& DLinkedList<T>::front() const {
    if (!head) throw std::logic_error("Cannot access front of an empty list");

    return head->data;
}

template<typename T>
const T& DLinkedList<T>::back() const {
    if (!head) throw std::logic_error("Cannot access back of an empty list");

    return tail->data;
}

template<typename T>
void DLinkedList<T>::pop_front() {
    if (!head) throw std::logic_error("Cannot pop from an empty list");

    if (head==tail) {
        delete head;
        head=nullptr;
        tail=nullptr;
    }else {
        Node* temp=head->next;
        delete head;
        head=temp;
        head->prev=nullptr;
    }
}

template<typename T>
void DLinkedList<T>::pop_back() {
    if (!head) throw std::logic_error("Cannot pop from an empty list");

    if (head==tail) {
        delete tail;
        head=nullptr;
        tail=nullptr;
    }else {
        Node* temp = tail->prev;
        delete tail;
        tail=temp;
        tail->next=nullptr;
    }
}

template<typename T>
std::size_t DLinkedList<T>::size() const {
    if (!head) return 0;
    std::size_t size=0;
    Node* temp=head;
    while (temp) {
        size++;
        temp=temp->next;
    }
    return size;
}

template<typename T>
void DLinkedList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template<typename T>
bool DLinkedList<T>::empty() const {
    return !head;
}

template<typename T>
T& DLinkedList<T>::operator[](const int index) {
    if (index<0 ) throw std::out_of_range("Index is out of range");
    if (index>=size()) throw std::out_of_range("Index is out of range");

    Node* temp=head;
    for (int i=0; i<index; ++i) {
        if (!temp) throw std::out_of_range("Index is out of range");
        temp=temp->next;
    }
    return temp->data;
}

template<typename T>
const T &DLinkedList<T>::operator[](const int index) const {
    if (index<0 ) throw std::out_of_range("Index is out of range");
    if (index>=size()) throw std::out_of_range("Index is out of range");

    Node* temp=head;
    for (int i=0; i<index; ++i) {
        if (!temp) throw std::out_of_range("Index is out of range");
        temp=temp->next;
    }
    return temp->data;
}





#endif //DLINKEDLIST_H
