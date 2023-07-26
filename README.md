## Readme.txt - Practice with Binary Search Tree (BST)

### Introduction

This repository contains a C program that implements a Binary Search Tree (BST) data structure. The program provides various functions for creating, manipulating, and displaying a balanced BST.

### Files

- `nodo.h`: Header file containing the structure definition for the BST node.

- `main.c`: The main C file with the implementation of various functions to manage the BST.

### BST Structure

The BST is represented by the `Arbol` structure, which consists of the following members:

```c
typedef struct arbol{
    int totalIzq;
    Nodo *raiz;
    int totalDer;
} Arbol;
```

- `totalIzq`: Represents the total number of nodes in the left subtree of the BST.
- `raiz`: Points to the root node of the BST.
- `totalDer`: Represents the total number of nodes in the right subtree of the BST.

### Functionality

1. `crearArbol()`: Creates an empty BST and returns its pointer.

2. `estaVacioElArbol(Arbol *a)`: Checks if the given BST is empty or not.

3. `preorden(Nodo *n)`, `enorden(Nodo *n)`, `postorden(Nodo *n)`: Traverses the BST and prints the nodes in Preorder, Inorder, and Postorder respectively.

4. `imprimirPreorden(Arbol *a)`, `imprimirEnorden(Arbol *a)`, `imprimirPostorden(Arbol *a)`: Print the entire BST in Preorder, Inorder, and Postorder respectively.

5. `buscarNodo(Arbol *a, int valor)`: Searches for a node with the given value in the BST and returns the pointer to it.

6. `insertarNodo(Arbol *a, Nodo *n)`: Inserts a new node into the BST.

7. `eliminarNodo(Arbol *a, int valor)`: Deletes a node with the given value from the BST.

### Contributing

This repository is for personal practice, but if you have any suggestions or improvements for the code or documentation, feel free to submit a pull request. Any constructive contributions are welcome.



### Resources

- [Binary Search Tree (Wikipedia)](https://en.wikipedia.org/wiki/Binary_search_tree)
- [GeeksforGeeks - Binary Search Trees](https://www.geeksforgeeks.org/binary-search-tree-data-structure/)
- [Introduction to Algorithms by Thomas H. Cormen](https://mitpress.mit.edu/books/introduction-algorithms-third-edition) (For in-depth understanding of algorithms and data structures)
