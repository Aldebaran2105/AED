#include <iostream>
using namespace std;

struct NodoAVL {
    int dato, altura;
    NodoAVL* izq;
    NodoAVL* der;
    NodoAVL(int d) : dato(d), altura(1), izq(nullptr), der(nullptr) {}
};

class AVL {
    NodoAVL* raiz;

    int altura(NodoAVL* nodo) { return nodo ? nodo->altura : 0; }

    int balance(NodoAVL* nodo) {
        return nodo ? altura(nodo->izq) - altura(nodo->der) : 0;
    }

    NodoAVL* rotarDerecha(NodoAVL* y) {
        NodoAVL* x = y->izq;
        NodoAVL* T2 = x->der;

        x->der = y;
        y->izq = T2;

        y->altura = 1 + max(altura(y->izq), altura(y->der));
        x->altura = 1 + max(altura(x->izq), altura(x->der));

        return x;
    }

    NodoAVL* rotarIzquierda(NodoAVL* x) {
        NodoAVL* y = x->der;
        NodoAVL* T2 = y->izq;

        y->izq = x;
        x->der = T2;

        x->altura = 1 + max(altura(x->izq), altura(x->der));
        y->altura = 1 + max(altura(y->izq), altura(y->der));

        return y;
    }

    NodoAVL* insertar(NodoAVL* nodo, int valor) {
        if (!nodo) return new NodoAVL(valor);

        if (valor < nodo->dato) nodo->izq = insertar(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = insertar(nodo->der, valor);
        else return nodo;

        nodo->altura = 1 + max(altura(nodo->izq), altura(nodo->der));
        int b = balance(nodo);

        if (b > 1 && valor < nodo->izq->dato)
            return rotarDerecha(nodo);
        if (b < -1 && valor > nodo->der->dato)
            return rotarIzquierda(nodo);
        if (b > 1 && valor > nodo->izq->dato) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }
        if (b < -1 && valor < nodo->der->dato) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }

        return nodo;
    }

    void inOrder(NodoAVL* nodo) {
        if (!nodo) return;
        inOrder(nodo->izq);
        cout << nodo->dato << " ";
        inOrder(nodo->der);
    }

public:
    AVL() : raiz(nullptr) {}

    void insertar(int valor) { raiz = insertar(raiz, valor); }
    void mostrarInOrder() { inOrder(raiz); cout << endl; }
};
