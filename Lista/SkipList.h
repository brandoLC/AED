//
// Created by brano on 28/01/2025.
//

#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <iostream>
#include <vector>
#include <random>

struct Node{
    int value;
    std::vector<Node*> next;
    explicit Node( int value, const int level):value(value),next(level,nullptr){};
};

class SkipList{
private:
    Node* head;
    int level;
    int max_level;

    int randomLevel() const;
public:
    explicit SkipList(const int max_level=16):max_level(max_level){
        level = 1;
        head = new Node(-1,max_level);
    }

    bool search(int target) const;

    void insert(int value);

    void remove(int value);

    ~SkipList();

};


inline int SkipList::randomLevel() const{
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> distribution(0, 1);
    int nivel = 1;
    while (distribution(generator) == 0 && nivel < max_level) {
        nivel++;
    }
    return nivel;
}

inline bool SkipList::search(int target) const{
    Node* current=head;

    for (int i=level-1 ; i>=0 ; i--){
        while (current->next[i] && current->next[i]->value < target){
            current=current->next[i];
        }
    }
    current=current->next[0];
    if (current && current->value==target) return true;

    return false;
}

inline void SkipList::insert(int value){
    std::vector<Node*> update(max_level,nullptr);
    Node* current=head;

    for (int i=level-1 ; i>=0 ; i--){
        while (current->next[i] && current->next[i]->value < value){
            current=current->next[i];
        }
        update[i]=current;
    }

    int newLevel=randomLevel();

    if (newLevel>level)
    {
        for (int i = level; i < newLevel; i++)
        {
            update[i] = head;
        }
        level=newLevel;
    }

    Node* newNode= new Node(value,newLevel);

    for (int i=0 ; i<newLevel ; i++){
        newNode->next[i]=update[i]->next[i];
        update[i]->next[i]=newNode;
    }
}

inline void SkipList::remove(const int value) {
    Node* current = head;
    std::vector<Node*> update(max_level, nullptr);

    for (int i = level - 1; i >= 0; i--) {
        while (current->next[i] && current->next[i]->value < value) {
            current = current->next[i];
        }
        update[i] = current;
    }

    current = current->next[0];

    if (current && current->value == value) {
        for (int i = 0; i < level; i++) {
            if (update[i]->next[i] != current) break;
            update[i]->next[i] = current->next[i];
        }
        delete current;

        while (level > 1 && head->next[level - 1] == nullptr) {
            level--;
        }
    }
}

inline SkipList::~SkipList()
{
    Node* current = head;
    while (current)
    {
        Node* next=current->next[0];
        delete current;
        current = next;
    }
}


#endif //SKIPLIST_H
