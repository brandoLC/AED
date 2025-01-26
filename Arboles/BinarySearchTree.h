//
// Created by brando on 1/22/25.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <queue>
#include <algorithm> // Para std::max
#include <vector>    // Para almacenar niveles


template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    explicit TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree {
private:
    TreeNode<T>* root;


    TreeNode<T>* insert(TreeNode<T>* node, T value) {
        if (!node) return new TreeNode<T>(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }
    bool isMirror(TreeNode<T>* left, TreeNode<T>* right) {
        if (!left && !right) return true;   // Ambos son nulos, es un espejo
        if (!left || !right) return false; // Solo uno es nulo, no es un espejo
        return (left->data == right->data) // Raíz igual
            && isMirror(left->left, right->right)  // Subárbol izquierdo de "left" con subárbol derecho de "right"
            && isMirror(left->right, right->left); // Subárbol derecho de "left" con subárbol izquierdo de "right"
    }
    TreeNode<T>* findMin(TreeNode<T>* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    TreeNode<T>* remove(TreeNode<T>* node, T value) {
        if (!node) return nullptr;

        if (value < node->data) {
            node->left = remove(node->left, value);
        } else if (value > node->data) {
            node->right = remove(node->right, value);
        } else {
            // Nodo encontrado
            if (!node->left) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            // Nodo con dos hijos: encontrar el sucesor en inorden
            TreeNode<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    bool search(TreeNode<T>* node, T value) {
        if (!node) return false;
        if (value == node->data) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    void inorder(TreeNode<T>* node, std::vector<T>& result) {
        if (node) {
            inorder(node->left, result);
            result.push_back(node->data);
            inorder(node->right, result);
        }
    }

    void preorder(TreeNode<T>* node, std::vector<T>& result) {
        if (node) {
            result.push_back(node->data);
            preorder(node->left, result);
            preorder(node->right, result);
        }
    }

    void postorder(TreeNode<T>* node, std::vector<T>& result) {
        if (node) {
            postorder(node->left, result);
            postorder(node->right, result);
            result.push_back(node->data);
        }
    }

    int height(TreeNode<T>* node) {
        if (!node) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    int width(TreeNode<T>* node) {
        if (!node) return 0;

        int maxWidth = 0;
        std::queue<TreeNode<T>*> q;
        q.push(node);

        while (!q.empty()) {
            int count = q.size(); // Número de nodos en este nivel
            maxWidth = std::max(maxWidth, count);

            for (int i = 0; i < count; ++i) {
                TreeNode<T>* temp = q.front();
                q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return maxWidth;
    }

    void destroy(TreeNode<T>* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Destructor
    ~BinarySearchTree() {
        destroy(root);
    }

    // Métodos públicos
    void insert(T value) {
        root = insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    bool search(T value) {
        return search(root, value);
    }

    std::vector<T> inorder() {
        std::vector<T> result;
        inorder(root, result);
        return result;
    }

    bool isMirror() {
        return isMirror(root->left, root->right);
    }

    std::vector<T> preorder() {
        std::vector<T> result;
        preorder(root, result);
        return result;
    }

    std::vector<T> postorder() {
        std::vector<T> result;
        postorder(root, result);
        return result;
    }

    int height() {
        return height(root);
    }

    int width() {
        return width(root);
    }

    bool isEmpty() {
        return root == nullptr;
    }
};
#endif //BINARYSEARCHTREE_H
