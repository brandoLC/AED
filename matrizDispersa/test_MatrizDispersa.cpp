#include "MatrizDispersa.h"
#include <gtest/gtest.h>

// Test: Insert and search elements
TEST(MatrizDispersaTest, InsertAndSearch) {
    MatrizDispersa matriz(5, 5);

    matriz.insertar(1, 1, 10);
    matriz.insertar(2, 2, 20);
    matriz.insertar(3, 3, 30);

    EXPECT_EQ(matriz.buscar(1, 1), 10);
    EXPECT_EQ(matriz.buscar(2, 2), 20);
    EXPECT_EQ(matriz.buscar(3, 3), 30);
    EXPECT_EQ(matriz.buscar(4, 4), 0);
}

// Test: Búsqueda de elementos
TEST(MatrizDispersaTest, BuscarElementos) {
    MatrizDispersa matriz(5, 5);

    matriz.insertar(1, 1, 10);
    matriz.insertar(2, 2, 20);
    matriz.insertar(3, 3, 30);

    // Verificar que los elementos insertados se encuentran correctamente
    EXPECT_EQ(matriz.buscar(1, 1), 10);
    EXPECT_EQ(matriz.buscar(2, 2), 20);
    EXPECT_EQ(matriz.buscar(3, 3), 30);

    // Verificar que la búsqueda de un elemento no insertado devuelve 0
    EXPECT_EQ(matriz.buscar(4, 4), 0);

    // Verificar que la búsqueda en una posición fuera de los límites devuelve 0
    EXPECT_EQ(matriz.buscar(6, 6), 0);
}

// Test: Eliminate elements
TEST(MatrizDispersaTest, EliminateElement) {
    MatrizDispersa matriz(5, 5);

    matriz.insertar(1, 1, 10);
    matriz.insertar(2, 2, 20);
    matriz.eliminar(1, 1);

    EXPECT_EQ(matriz.buscar(1, 1), 0);
    EXPECT_EQ(matriz.buscar(2, 2), 20);
}

// Test: Sum matrices
TEST(MatrizDispersaTest, SumMatrices) {
    MatrizDispersa matriz1(5, 5);
    MatrizDispersa matriz2(5, 5);

    matriz1.insertar(1, 1, 10);
    matriz2.insertar(1, 1, 20);

    MatrizDispersa resultado = matriz1.sumar(matriz2);

    EXPECT_EQ(resultado.buscar(1, 1), 30);
}

// Test: Subtract matrices
TEST(MatrizDispersaTest, SubtractMatrices) {
    MatrizDispersa matriz1(5, 5);
    MatrizDispersa matriz2(5, 5);

    matriz1.insertar(1, 1, 30);
    matriz2.insertar(1, 1, 20);

    MatrizDispersa resultado = matriz1.restar(matriz2);

    EXPECT_EQ(resultado.buscar(1, 1), 10);
}

// Test: Multiply matrices
TEST(MatrizDispersaTest, MultiplyMatrices) {
    MatrizDispersa matriz1(5, 5);
    MatrizDispersa matriz2(5, 5);

    matriz1.insertar(1, 1, 2);
    matriz1.insertar(1, 2, 3);
    matriz2.insertar(1, 1, 4);
    matriz2.insertar(2, 1, 5);

    MatrizDispersa resultado = matriz1.multiplicar(matriz2);

    EXPECT_EQ(resultado.buscar(1, 1), 23);
}

// Test: Multiply by constant
TEST(MatrizDispersaTest, MultiplyByConstant) {
    MatrizDispersa matriz(5, 5);

    matriz.insertar(1, 1, 10);
    matriz.insertar(2, 2, 20);

    MatrizDispersa resultado = matriz.multiplicarPorConstante(2);

    EXPECT_EQ(resultado.buscar(1, 1), 20);
    EXPECT_EQ(resultado.buscar(2, 2), 40);
}


