#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <stdexcept> 
#include <initializer_list>
#include <cstddef>
template <typename T>
class ForwardList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* head;

    typename ForwardList<T>::Node* sortedInsert(typename ForwardList<T>::Node* sorted, typename ForwardList<T>::Node* newNode);

public:
    ForwardList() : head(nullptr) {}
    ForwardList(std::initializer_list<T> init_list);
    ~ForwardList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    const T& front() const;
    const T& back() const;
    std::size_t size() const;
    bool empty() const;
    void clear();
    T& operator[](int index);
    const T& operator[](int index) const;
    void reverse();
    void insertionSort();
    bool isPalindromo();
    ForwardList<T> mergeWith(const ForwardList<T>& other) const; 
    ForwardList<T> intersectionWith(const ForwardList<T>& other) const;
};

template<typename T>
ForwardList<T>::ForwardList(std::initializer_list<T> init_list):head(nullptr){
    for(const T& value : init_list){
        push_back(value);
    }
}

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
void ForwardList<T>::pop_back(){
    if(!head) throw std::out_of_range("List is empty");

    if(!head->next){
        delete head;
        head=nullptr;
        return;
    }

    Node* temp=head;
    while(temp->next->next){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;
}

template <typename T>
const T& ForwardList<T>::front() const{
    if(!head){
        throw std::out_of_range("List is empty");
    }

    return head->data;
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

template <typename T>
const T& ForwardList<T>::back() const {
    if(!head) throw std::out_of_range("List is empty");

    Node* temp=head;

    while(temp->next){ 
        temp=temp->next;
    }

    return temp->data;
}

template<typename T>
std::size_t ForwardList<T>::size() const{
    size_t size=0;
    Node* temp=head;
    while(temp){
        size++;
        temp=temp->next;
    }
    return size;
}

template<typename T>
T& ForwardList<T>::operator[](int index){
    if(index<0) throw std::out_of_range("Index is out of range");

    Node* temp=head;
    for(int i=0; i<index ; ++i){
        if(!temp){
            throw std::out_of_range("Index is out of range");
        }
        temp=temp->next;
    }

    if(!temp) throw std::out_of_range("Index is out of range");

    return temp->data;

}

template<typename T>
const T& ForwardList<T>::operator[](int index) const {
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        if (!current) {
            throw std::out_of_range("Index is out of range");
        }
        current = current->next;
    }
    if (!current) {
        throw std::out_of_range("Index is out of range");
    }
    return current->data;
}

template <typename T>
void ForwardList<T>::reverse(){
    if (!head || !head->next) {
        return; 
    }
    
    Node* prev=nullptr;
    Node* current=head;
    while(current){
        Node* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

template <typename T>
typename ForwardList<T>::Node* ForwardList<T>::sortedInsert(Node* sorted,Node* newNode){
    
    if(!sorted || sorted->data>=newNode->data){
        newNode->next=sorted;
        return newNode;
    }else{
        Node* current=sorted;
        while(current->next && current->next->data < newNode->data){
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
    return sorted;
}

template <typename T>
void ForwardList<T>::insertionSort(){
    if(!head || !head->next){
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }

    head = sorted;
}

template <typename T>
ForwardList<T> ForwardList<T>::intersectionWith(const ForwardList<T>& other) const {
    ForwardList<T> result;
    Node* current1 = head;
    Node* current2 = other.head;
    Node** lastPtrRef = &result.head;

    while (current1 && current2) {
        if (current1->data < current2->data) {
            current1 = current1->next;
        } else if (current1->data > current2->data) {
            current2 = current2->next;
        } else {
            *lastPtrRef = new Node(current1->data);
            lastPtrRef = &((*lastPtrRef)->next);
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    return result;
}

template <typename T>
ForwardList<T> ForwardList<T>::mergeWith(const ForwardList<T>& other) const {
    ForwardList<T> result;
    Node* current1 = head;
    Node* current2 = other.head;
    Node** lastPtrRef = &result.head;

    while (current1 && current2) {
        if (current1->data <= current2->data) {
            *lastPtrRef = new Node(current1->data);
            current1 = current1->next;
        } else {
            *lastPtrRef = new Node(current2->data);
            current2 = current2->next;
        }
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (current1) {
        *lastPtrRef = new Node(current1->data);
        current1 = current1->next;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    while (current2) {
        *lastPtrRef = new Node(current2->data);
        current2 = current2->next;
        lastPtrRef = &((*lastPtrRef)->next);
    }

    return result;
}

template<typename T>
bool ForwardList<T>::isPalindromo() {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* prev = nullptr;
    Node* curr = slow;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* left = head;
    Node* ride = prev;
    while (ride) {
        if (left->data != ride->data) {
            curr = prev;
            prev = nullptr;
            while (curr) {
                Node* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            Node* mid = head;
            while (mid->next != slow) {
                mid = mid->next;
            }
            mid->next = prev;
            return false;
        }
        left = left->next;
        ride = ride->next;
    }

    curr = prev;
    prev = nullptr;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    Node* mid = head;
    while (mid->next != slow) {
        mid = mid->next;
    }
    mid->next = prev;

    return true;
}
#endif // FORWARD_LIST_H
