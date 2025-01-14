# AED
## Descripción del Curso

Este repositorio contiene las tareas del curso de **Algoritmos y Estructura de Datos (AED)**. En este curso, implementaremos diversas estructuras de datos desde cero.

## Estructuras de Datos Implementadas

### Forward List
La Forward List es una lista enlazada simple donde cada nodo apunta al siguiente nodo en la secuencia. Esta estructura es útil para operaciones de inserción y eliminación rápidas.


#### Métodos

- **Constructor**: Inicializa una lista vacía o a partir de una lista de inicialización.
- **Destructor**: Libera la memoria utilizada por la lista.
- **push_front**: Inserta un elemento al inicio de la lista.
- **push_back**: Inserta un elemento al final de la lista.
- **pop_front**: Elimina el primer elemento de la lista.
- **pop_back**: Elimina el último elemento de la lista.
- **front**: Devuelve una referencia al primer elemento de la lista.
- **back**: Devuelve una referencia al último elemento de la lista.
- **size**: Devuelve el número de elementos en la lista.
- **empty**: Verifica si la lista está vacía.
- **clear**: Elimina todos los elementos de la lista.
- **operator[]**: Accede al elemento en la posición especificada.
- **reverse**: Invierte el orden de los elementos en la lista.
- **insertionSort**: Ordena los elementos de la lista utilizando el algoritmo de ordenación por inserción.
- **isPalindromo**: Verifica si la lista es un palíndromo.
- **remove**: Elimina el elemento en la posición especificada.
- **insert**: Inserta un elemento en la posición especificada.
- **mergeWith**: Fusiona la lista actual con otra lista.
- **intersectionWith**: Devuelve una nueva lista que contiene la intersección de la lista actual con otra lista.


### Doubly Linked List
Pendiente de implementación.

### Circular Linked List
Pendiente de implementación.

## Requisitos

Para compilar y ejecutar las pruebas, es necesario tener instalados los siguientes programas:

- **CMake**: Herramienta de construcción de software.
- **g++**: Compilador de C++.
- **Google Test (gtest)**: Biblioteca para pruebas unitarias en C++.

### Instalación de Requisitos en Ubuntu

```sh
sudo apt-get update
sudo apt-get install -y cmake g++ libgtest-dev
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo cp *.a /usr/lib
```
## Instalación de Requisitos en Windows

Para usuarios de Windows, se recomienda utilizar CLion, ya que facilita la instalación de Google Test con su manejador de paquetes integrado.

1. Descarga e instala CLion desde JetBrains.
2. Abre tu proyecto en CLion.
3. Sigue las instrucciones de CLion para instalar Google Test cuando se detecte que no está instalado en el sistema. CLion te ofrecerá instalar Google Test utilizando vcpkg automáticamente.

## Cómo Compilar y Ejecutar

### Instrucciones

1. Clona el repositorio:
    ```sh
    git clone https://github.com/brandoLC/AED.git
    cd AED
    ```

2. Crea un directorio de construcción y navega a él:
    ```sh
    mkdir build
    cd build
    ```

3. Configura el proyecto con CMake:
    ```sh
    cmake ..
    ```

4. Compila el proyecto:
    ```sh
    make
    ```

5. Ejecuta las pruebas:
    ```sh
    ./runTests
    ```

## Contribuciones

Las contribuciones son bienvenidas. Si deseas contribuir, por favor sigue los siguientes pasos:

1. Haz un fork del repositorio.
2. Crea una nueva rama (`git checkout -b feature/nueva_estructura`).
3. Realiza tus cambios y haz commit (`git commit -am 'Añadir nueva estructura de datos'`).
4. Sube los cambios a tu fork (`git push origin feature/nueva_estructura`).
5. Abre un Pull Request.


