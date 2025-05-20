#include <iostream>
using namespace std;

struct NodoPila {
    int dato;
    NodoPila* next;
    NodoPila(int d) : dato(d), next(nullptr) {}
};

class Pila {
    NodoPila* top;
public:
    Pila() : top(nullptr) {}

    void push(int valor) {
        NodoPila* nuevo = new NodoPila(valor);
        nuevo->next = top;
        top = nuevo;
    }

    void pop() {
        if (!top) return;
        NodoPila* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() { return top ? top->dato : -1; }

    bool empty() { return top == nullptr; }
};
