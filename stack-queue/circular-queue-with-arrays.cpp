#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;      // Arreglo para almacenar los elementos
    int front;       // Índice del primer elemento
    int rear;        // Índice del último elemento
    int size;        // Tamaño máximo de la cola
    int capacity;    // Capacidad del arreglo

public:
    // Constructor
    CircularQueue(int capacity) {
        this->capacity = capacity;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~CircularQueue() {
        delete[] queue;
    }

    // Verifica si la cola está llena
    bool isFull() {
        return size == capacity;
    }

    // Verifica si la cola está vacía
    bool isEmpty() {
        return size == 0;
    }

    // Encolar un elemento
    void enqueue(int value) {
        if (isFull()) {
            cout << "Cola llena. No se puede encolar el elemento " << value << endl;
            return;
        }

        // Calcular la nueva posición de `rear`
        rear = (rear + 1) % capacity;
        queue[rear] = value;

        // Si es el primer elemento, actualizar `front`
        if (front == -1)
            front = rear;

        size++;
        cout << "Elemento " << value << " encolado.\n";
    }

    // Desencolar un elemento
    int dequeue() {
        if (isEmpty()) {
            cout << "Cola vacía. No se puede desencolar.\n";
            return -1;
        }

        int value = queue[front];

        // Calcular la nueva posición de `front`
        if (front == rear) { // Si la cola tiene un solo elemento
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        cout << "Elemento " << value << " desencolado.\n";
        return value;
    }

    // Obtener el elemento al frente de la cola
    int peek() {
        if (isEmpty()) {
            cout << "Cola vacía. No hay elementos para mostrar.\n";
            return -1;
        }
        return queue[front];
    }

    // Imprimir el contenido de la cola
    void display() {
        if (isEmpty()) {
            cout << "Cola vacía.\n";
            return;
        }

        cout << "Contenido de la cola: ";
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    cout << "Elemento al frente: " << cq.peek() << endl;

    return 0;
}
