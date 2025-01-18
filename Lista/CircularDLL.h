//
// Created by brano on 17/01/2025.
//

#ifndef CIRCULARDLL_H
#define CIRCULARDLL_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
struct ListNode {
    T data;
    ListNode* next;
    ListNode* prev;

    ListNode(T value) : data(value), next(nullptr), prev(nullptr) {}
    ListNode(T value, ListNode* nextListNode, ListNode* prevListNode) : data(value), next(nextListNode), prev(prevListNode) {}
    ListNode() : next(nullptr), prev(nullptr) {}
};


template <typename T>
class List {
private:
    int count;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    List() : head(nullptr), count(0), tail(nullptr) {}
    ~List() {
        clear();
    }

    T front() {
        if (empty()) {
            throw runtime_error("Lista vacía");
        }
        return head->data;
    }

    T back() {
        if (empty()) {
            throw runtime_error("Lista vacía");
        }
        return tail->data;
    }

    void push_front(T input) {
        ListNode<T>* nodo = new ListNode<T>(input);
        if (empty()) {
            head = tail = nodo;
            head->next = head->prev = head;  // Circularidad
        } else {
            nodo->next = head;
            nodo->prev = tail;
            head->prev = nodo;
            tail->next = nodo;
            head = nodo;
        }
        count++;
    }

    void push_back(T input) {
        ListNode<T>* nodo = new ListNode<T>(input);
        if (empty()) {
            head = tail = nodo;
            head->next = head->prev = head;  // Circularidad
        } else {
            nodo->prev = tail;
            nodo->next = head;
            tail->next = nodo;
            head->prev = nodo;
            tail = nodo;
        }
        count++;
    }


    T pop_front() {
        if (empty()) {
            throw runtime_error("Lista vacia");
        }
        ListNode<T>* temp = head;
        T output = temp->data;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        }else {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
        count--;
        return output;
    }

    T pop_back() {
        if (empty()) {
            throw runtime_error("Lista vacia");
        }
        ListNode<T>* temp = tail;
        T output= temp->data;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        delete temp;
        count--;
        return output;
    }


    T operator[](int index) {
        if (index < 0 || index >= count) {
            throw out_of_range("Indice fuera de rango");
        }
        ListNode<T>* temp=nullptr;
        if(index < count/2) {
            temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
        } else {
           temp = tail;
            for (int i = count-1; i > index; i--) {
                temp = temp->prev;
            }
        }

        return temp->data;
    }


    bool empty() {
        return count == 0;
    }

    int size() {
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
        count = 0;
        head=nullptr;
        tail=nullptr;
    }


    void print() {
        if (empty()) {
            cout << "Lista vacía" << endl;
            return;
        }

        ListNode<T>* temp = head;
        cout << "Lista [" << count << " elementos]: ";
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " <-> ";
        } while (temp != head);
        cout << endl;
    }



    void insertAt(T value, int position) {
        if (position < 0 || position > count-1) {
            throw out_of_range("Posicion fuera de rango");
        }
        if (position == 0) {
            push_front(value);
            return;
        }
        if (position == count-1) {  // Caso borde
            push_back(value);
            return;
        }

        ListNode<T>* nodo = new ListNode<T>(value);
        ListNode<T>* temp = (position < count / 2) ? head : tail;

        if (position < count / 2) {
            for (int i = 0; i < position - 1; i++) temp = temp->next;
        } else {
            for (int i = count - 1; i >= position; i--) temp = temp->prev;
        }

        nodo->next = temp->next;
        nodo->prev = temp;
        temp->next->prev = nodo;
        temp->next = nodo;
        count++;
    }






    T valueAt(int position) {
        return (*this)[position];
    }


    void rotateRight(int total) {

        if (head == nullptr || tail == nullptr || total <= 0 || count <= 1) {
            return; // No hay nada que rotar.
        }
        total %= count;
        if (total == 0) {
            return; // La lista no necesita rotarse.
        }

        for (int i = 0; i < total; i++) {
            push_front(pop_back());
        }
    }

    void reverse() {
        if (empty() || count == 1) return;

        ListNode<T>* current = head;
        ListNode<T>* temp = nullptr;
        do {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        } while (current != head);

        temp = head;
        head = tail;
        tail = temp;
    }



    T remove(int position) {
        if (position < 0 || position >= count) { // Cambié > por >=
            throw out_of_range("Posicion fuera de rango");
        }
        if (position == count - 1) {
            return pop_back();
        }
        if (position == 0) {
            return pop_front();
        }

        ListNode<T>* temp = nullptr;

        if (position < count / 2) {
            temp = head;
            for (int i = 0; i < position; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = count - 1; i > position; i--) {
                temp = temp->prev;
            }
        }

        // Actualizar los enlaces de los nodos vecinos
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        // Ajustar head o tail si es necesario
        if (temp == head) {
            head = temp->next;
        }
        if (temp == tail) {
            tail = temp->prev;
        }

        T value = temp->data;
        delete temp;
        count--;
        return value;
    }
    void removeDuplicates() {
        if (head == nullptr || head->next == nullptr) {
            return; // Lista vacía o con un solo elemento, no hay duplicados.
        }

        ListNode<T>* current = head;

        while (current != tail) {
            ListNode<T>* runner = current->next;
            while (runner != tail) {
                if (runner->data == current->data) {
                    // Nodo duplicado encontrado
                    ListNode<T>* duplicate = runner;
                    runner = runner->next; // Avanzar antes de eliminar

                    // Actualizar punteros de los nodos vecinos
                    if (duplicate->prev != nullptr) {
                        duplicate->prev->next = duplicate->next;
                    }
                    if (duplicate->next != nullptr) {
                        duplicate->next->prev = duplicate->prev;
                    }

                    // Si el duplicado es tail, actualizar tail
                    if (duplicate == tail) {
                        tail = duplicate->prev;
                    }

                    delete duplicate;
                    count--;
                } else {
                    runner = runner->next; // Avanzar al siguiente nodo
                }
            }
            current = current->next; // Avanzar al siguiente nodo principal
        }
    }

};
#endif //CIRCULARDLL_H
