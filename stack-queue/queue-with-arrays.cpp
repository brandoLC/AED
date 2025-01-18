#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    // Constructor para inicializar la cola con un tamaño
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor para liberar la memoria
    ~Queue() {
        delete[] arr;
    }

    // Método para verificar si la cola está vacía
    bool isEmpty() {
        return front == -1;
    }

    // Método para verificar si la cola está llena
    bool isFull() {
        return rear == capacity - 1;
    }

    // Método para agregar un elemento a la cola
    void enqueue(int value) {
        if (isFull()) {
            cout << "La cola está llena. No se puede agregar el valor " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0; // La primera vez que agregamos un elemento
        }
        arr[++rear] = value;
    }

    // Método para eliminar un elemento de la cola
    void dequeue() {
        if (isEmpty()) {
            cout << "La cola está vacía. No se puede eliminar un elemento." << endl;
            return;
        }
        cout << "Se eliminó el valor: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1; // La cola queda vacía
        } else {
            front++;
        }
    }

    // Método para obtener el primer elemento de la cola
    int peek() {
        if (isEmpty()) {
            cout << "La cola está vacía." << endl;
            return -1;
        }
        return arr[front];
    }

    // Método para mostrar los elementos de la cola
    void display() {
        if (isEmpty()) {
            cout << "La cola está vacía." << endl;
            return;
        }
        cout << "Elementos en la cola: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Creamos una cola de tamaño 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display(); // Muestra los elementos

    q.dequeue();
    q.display(); // Muestra los elementos después de eliminar uno

    cout << "Primer elemento en la cola: " << q.peek() << endl; // Muestra el primer elemento

    q.enqueue(60);
    q.display(); // Muestra los elementos después de agregar uno

    return 0;
}
