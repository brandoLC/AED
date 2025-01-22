//
// Created by brando on 1/22/25.
//
#include "BinarySearchTree.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

// Test: Inserción de elementos y recorridos
TEST(BinarySearchTreeTest, InsertAndTraversal) {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    // Prueba del recorrido inorden (debe estar ordenado)
    std::vector<int> expectedInorder = {3, 5, 7, 10, 15};
    EXPECT_EQ(bst.inorder(), expectedInorder);

    // Prueba del recorrido preorden
    std::vector<int> expectedPreorder = {10, 5, 3, 7, 15};
    EXPECT_EQ(bst.preorder(), expectedPreorder);

    // Prueba del recorrido postorden
    std::vector<int> expectedPostorder = {3, 7, 5, 15, 10};
    EXPECT_EQ(bst.postorder(), expectedPostorder);
}

/*
TEST(BinarySearchTreeTest, IsMirrorTreeManualConstruction) {
    // Crear un árbol simétrico usando inserciones
    BinarySearchTree<int> symmetricTree;

    // Insertar elementos en el árbol para hacerlo simétrico
    symmetricTree.insert(10);    // Raíz
    symmetricTree.insert(5);     // Subárbol izquierdo
    symmetricTree.insert(5);     // Subárbol derecho
    symmetricTree.insert(3);     // Subárbol izquierdo
    symmetricTree.insert(7);     // Subárbol izquierdo
    symmetricTree.insert(7);     // Subárbol derecho
    symmetricTree.insert(3);     // Subárbol derecho

    // Verificar si el árbol es un espejo
    EXPECT_TRUE(symmetricTree.isMirror());

    // Crear un árbol NO simétrico
    BinarySearchTree<int> asymmetricTree;

    // Insertar elementos en el árbol para hacerlo asimétrico
    asymmetricTree.insert(10);    // Raíz
    asymmetricTree.insert(5);     // Subárbol izquierdo
    asymmetricTree.insert(15);    // Subárbol derecho
    asymmetricTree.insert(3);     // Subárbol izquierdo
    asymmetricTree.insert(7);     // Subárbol derecho

    // Verificar si el árbol NO es un espejo
    EXPECT_FALSE(asymmetricTree.isMirror());
}
*/


// Test: Búsqueda en el árbol
TEST(BinarySearchTreeTest, SearchElement) {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    EXPECT_TRUE(bst.search(10));  // El valor está en el árbol
    EXPECT_TRUE(bst.search(5));
    EXPECT_TRUE(bst.search(15));
    EXPECT_FALSE(bst.search(20)); // El valor no está en el árbol
}

// Test: Eliminación de elementos
TEST(BinarySearchTreeTest, RemoveElement) {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    // Eliminar un nodo hoja
    bst.remove(3);
    std::vector<int> expectedAfterRemoveLeaf = {5, 7, 10, 15};
    EXPECT_EQ(bst.inorder(), expectedAfterRemoveLeaf);

    // Eliminar un nodo con un solo hijo
    bst.remove(5);
    std::vector<int> expectedAfterRemoveOneChild = {7, 10, 15};
    EXPECT_EQ(bst.inorder(), expectedAfterRemoveOneChild);

    // Eliminar un nodo con dos hijos
    bst.remove(10);
    std::vector<int> expectedAfterRemoveTwoChildren = {7, 15};
    EXPECT_EQ(bst.inorder(), expectedAfterRemoveTwoChildren);
}

// Test: Altura del árbol
TEST(BinarySearchTreeTest, HeightOfTree) {
    BinarySearchTree<int> bst;

    EXPECT_EQ(bst.height(), 0); // Árbol vacío

    bst.insert(10);
    EXPECT_EQ(bst.height(), 1); // Solo raíz

    bst.insert(5);
    bst.insert(15);
    EXPECT_EQ(bst.height(), 2); // Dos niveles

    bst.insert(3);
    bst.insert(7);
    EXPECT_EQ(bst.height(), 3); // Tres niveles
}

// Test: Anchura máxima del árbol
TEST(BinarySearchTreeTest, WidthOfTree) {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);

    EXPECT_EQ(bst.width(), 2); // Nivel con mayor anchura tiene 2 nodos (nivel 2)
}

// Test: Árbol vacío
TEST(BinarySearchTreeTest, IsEmptyTree) {
    BinarySearchTree<int> bst;

    EXPECT_TRUE(bst.isEmpty()); // Árbol recién creado está vacío

    bst.insert(10);
    EXPECT_FALSE(bst.isEmpty()); // Después de insertar, ya no está vacío

    bst.remove(10);
    EXPECT_TRUE(bst.isEmpty()); // Después de eliminar el único elemento, está vacío
}

// Test: Operaciones con diferentes tipos de datos
TEST(BinarySearchTreeTest, HandleDifferentDataTypes) {
    BinarySearchTree<std::string> bst;

    bst.insert("apple");
    bst.insert("banana");
    bst.insert("cherry");

    EXPECT_TRUE(bst.search("apple"));
    EXPECT_TRUE(bst.search("banana"));
    EXPECT_FALSE(bst.search("grape"));

    std::vector<std::string> expectedInorder = {"apple", "banana", "cherry"};
    EXPECT_EQ(bst.inorder(), expectedInorder);
}
