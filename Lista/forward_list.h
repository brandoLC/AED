#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stdexcept> 

template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* head;

public:
    ForwardList() : head(nullptr) {}
    ~ForwardList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    T& front();
    T& back();
    bool empty() const;
    void clear();
};

template <typename T>
ForwardList<T>::~ForwardList() {
    clear();
}

template <typename T>
void ForwardList<T>::push_front(const T& value) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
}

template <typename T>
void ForwardList<T>::push_back(const T& value) {
    Node* new_node = new Node(value);
    if (head == nullptr) {
        head = new_node;
    } else {
        Node* it = head;
        while (it->next != nullptr) {
            it = it->next;
        }
        it->next = new_node;
    }
}

template <typename T>
void ForwardList<T>::pop_front() {
    if (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
T& ForwardList<T>::front() {
    if (head) {
        return head->data;
    }
    throw std::out_of_range("List is empty");
}

template<typename T>
T& ForwardList<T>::back() {
    if (head) {
        Node* it = head;
        while (it->next != nullptr) {
            it = it->next;
        }
        return it->data;
    }
    throw std::out_of_range("List is empty");
}

template <typename T>
bool ForwardList<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void ForwardList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

#endif // FORWARD_LIST_H
