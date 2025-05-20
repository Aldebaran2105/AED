struct NodoCola {
    int dato;
    NodoCola* next;
    NodoCola(int d) : dato(d), next(nullptr) {}
};

class Cola {
    NodoCola* frente;
    NodoCola* final;
public:
    Cola() : frente(nullptr), final(nullptr) {}

    void enqueue(int valor) {
        NodoCola* nuevo = new NodoCola(valor);
        if (!final) frente = final = nuevo;
        else {
            final->next = nuevo;
            final = nuevo;
        }
    }

    void dequeue() {
        if (!frente) return;
        NodoCola* temp = frente;
        frente = frente->next;
        if (!frente) final = nullptr;
        delete temp;
    }

    int peek() { return frente ? frente->dato : -1; }

    bool empty() { return frente == nullptr; }
};
