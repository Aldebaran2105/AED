#include <iostream>
using namespace std;

// struct NodoHash {
//     int key, value;
//     NodoHash* next;
//     NodoHash(int k, int v) : key(k), value(v), next(nullptr) {}
// };

// class HashTable {
//     static const int SIZE = 100;
//     NodoHash* table[SIZE];

//     int hash(int key) { return key % SIZE; }
// public:
//     HashTable() { for (int i = 0; i < SIZE; i++) table[i] = nullptr; }

//     void insert(int key, int value) {
//         int idx = hash(key);
//         NodoHash* head = table[idx];
//         while (head) {
//             if (head->key == key) {
//                 head->value = value;
//                 return;
//             }
//             head = head->next;
//         }
//         NodoHash* nuevo = new NodoHash(key, value);
//         nuevo->next = table[idx];
//         table[idx] = nuevo;
//     }

//     int get(int key) {
//         int idx = hash(key);
//         NodoHash* head = table[idx];
//         while (head) {
//             if (head->key == key) return head->value;
//             head = head->next;
//         }
//         return -1;
//     }
// };
class HashTable {
private:
    enum Estado { VACIO, OCUPADO, BORRADO };

    struct Entrada {
        int clave;
        int valor;
        Estado estado;

        Entrada() : clave(0), valor(0), estado(VACIO) {}
    };

    Entrada* tabla;
    int capacidad;
    int size;
    const double factorCargaMax = 0.6;

    int hash(int clave) {
        return clave % capacidad;
    }

    void rehash() {
        int viejaCapacidad = capacidad;
        capacidad *= 2;
        Entrada* viejaTabla = tabla;
        tabla = new Entrada[capacidad];
        size = 0;

        for (int i = 0; i < viejaCapacidad; ++i) {
            if (viejaTabla[i].estado == OCUPADO) {
                insertar(viejaTabla[i].clave, viejaTabla[i].valor);
            }
        }
        delete[] viejaTabla;
    }

public:
    HashTable(int cap = 8) {
        capacidad = cap;
        size = 0;
        tabla = new Entrada[capacidad];
    }

    ~HashTable() {
        delete[] tabla;
    }

    void insertar(int clave, int valor) {
        if ((double)size / capacidad >= factorCargaMax) {
            rehash();
        }

        int idx = hash(clave);
        while (tabla[idx].estado == OCUPADO) {
            if (tabla[idx].clave == clave) {
                tabla[idx].valor = valor;
                return;
            }
            idx = (idx + 1) % capacidad;
        }

        tabla[idx].clave = clave;
        tabla[idx].valor = valor;
        tabla[idx].estado = OCUPADO;
        size++;
    }

    bool buscar(int clave, int& valor) {
        int idx = hash(clave);
        int start = idx;

        while (tabla[idx].estado != VACIO) {
            if (tabla[idx].estado == OCUPADO && tabla[idx].clave == clave) {
                valor = tabla[idx].valor;
                return true;
            }
            idx = (idx + 1) % capacidad;
            if (idx == start) break;
        }
        return false;
    }

    bool eliminar(int clave) {
        int idx = hash(clave);
        int start = idx;

        while (tabla[idx].estado != VACIO) {
            if (tabla[idx].estado == OCUPADO && tabla[idx].clave == clave) {
                tabla[idx].estado = BORRADO;
                size--;
                return true;
            }
            idx = (idx + 1) % capacidad;
            if (idx == start) break;
        }
        return false;
    }

    void mostrar() {
        for (int i = 0; i < capacidad; ++i) {
            cout << i << ": ";
            if (tabla[i].estado == OCUPADO) {
                cout << "(" << tabla[i].clave << ", " << tabla[i].valor << ")";
            } else if (tabla[i].estado == BORRADO) {
                cout << "Borrado";
            } else {
                cout << "Vacío";
            }
            cout << endl;
        }
    }
};
