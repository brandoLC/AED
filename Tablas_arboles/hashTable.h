#ifndef HASHTABLE_H
#define HASHTABLE_H

/*#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>

template <typename KeyType, typename ValueType>
class UniversalHashTable {
private:
    struct KeyValuePair {
        KeyType key;
        ValueType value;
    };

    int tableSize;                       // Tamaño de la tabla (número de buckets)
    int prime;                           // Número primo mayor que cualquier clave
    int a, b;                            // Constantes aleatorias para la función hash
    std::vector<std::list<KeyValuePair>> table; // Tabla hash (listas enlazadas)

    // Generar un número aleatorio en un rango
    int randomInt(const int min, const int max) {
        return min + rand() % (max - min + 1);
    }

    // Función hash personalizada para claves tipo `std::string`
    int customHashFunction(const std::string& key) const {
        int hashValue = 0;
        int p = 31; // Número primo para ponderar caracteres
        int m = 1e9 + 9; // Otro número primo grande
        long long power = 1;

        for (char c : key) {
            hashValue = (hashValue + (c - 'a' + 1) * power) % m;
            power = (power * p) % m;
        }

        return hashValue;
    }

    // Función hash universal (usa la función hash personalizada)
    int hashFunction(const KeyType& key) const {
        int keyHash = std::hash<KeyType>{}(key); // Usa std::hash para claves numéricas
        return ((a * keyHash + b) % prime) % tableSize;
    }

public:
    // Constructor
    UniversalHashTable(int size, int primeNumber)
        : tableSize(size), prime(primeNumber), table(size) {
        srand(static_cast<unsigned>(time(0))); // Semilla aleatoria

        // Generar valores aleatorios para 'a' y 'b'
        a = randomInt(1, prime - 1); // 'a' debe ser diferente de 0
        b = randomInt(0, prime - 1);

        std::cout << "Hash function parameters: a = " << a
                  << ", b = " << b << ", prime = " << prime << std::endl;
    }

    // Insertar un par clave-valor en la tabla
    void insert(const KeyType& key, const ValueType& value) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.key == key) {
                pair.value = value; // Actualizar si la clave ya existe
                return;
            }
        }
        table[index].emplace_back(KeyValuePair{key, value});
    }

    // Buscar un valor por su clave
    bool search(const KeyType& key, ValueType& valueOut) const {
        int index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                valueOut = pair.value;
                return true;
            }
        }
        return false;
    }

    // Eliminar un par clave-valor
    bool remove(const KeyType& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                return true;
            }
        }
        return false;
    }

    // Mostrar la tabla hash
    void display() const {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "[" << i << "]: ";
            for (const auto& pair : table[i]) {
                std::cout << "(" << pair.key << ", " << pair.value << ") ";
            }
            std::cout << std::endl;
        }
    }
};*/

#endif // HASHTABLE_H