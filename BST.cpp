#include <iostream>
using namespace std;

struct NodoBST {
    int dato;
    NodoBST* izq;
    NodoBST* der;
    NodoBST(int d) : dato(d), izq(nullptr), der(nullptr) {}
};

class BST {
    NodoBST* raiz;

    NodoBST* insertar(NodoBST* nodo, int valor) {
        if (!nodo) return new NodoBST(valor);
        if (valor < nodo->dato) nodo->izq = insertar(nodo->izq, valor);
        else nodo->der = insertar(nodo->der, valor);
        return nodo;
    }

    void inOrder(NodoBST* nodo) {
        if (!nodo) return;
        inOrder(nodo->izq);
        cout << nodo->dato << " ";
        inOrder(nodo->der);
    }

public:
    BST() : raiz(nullptr) {}

    void insertar(int valor) { raiz = insertar(raiz, valor); }
    void mostrarInOrder() { inOrder(raiz); cout << endl; }
};
