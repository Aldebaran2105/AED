#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* next;
};

class LinkedList{
    Nodo* head;
public:
    LinkedList(){
        this->head = nullptr;
    }

    void pushFront(int n){
        Nodo* newNodo = new Nodo();
        newNodo -> dato = n;
        newNodo -> next = head;
        head = newNodo;
    }

    Nodo* getHead() const{
        return head;
    }

    void pushBack(int n){
        Nodo* actual = head;
        Nodo* newNodo = new Nodo();
        newNodo -> dato = n;
        while(actual -> next != nullptr){
            actual = actual -> next;
        }
        actual -> next = newNodo;
        newNodo -> next = nullptr;
    }

    int getNum(int n){
        if(head == nullptr){
            return -1;
        }
        Nodo* actual = head;
        while(actual != nullptr && actual -> dato != n){
            actual = actual -> next;
        }
        if(actual -> dato == n){
            return actual -> dato;
        }else{
            return -1;
        }
    }

    void deleteNum(int n){
        if(head == nullptr){
            return;
        }

        if(head -> dato == n){
            Nodo* eliminar = head;
            head = head -> next;
            delete eliminar;
            return;
        }

        Nodo* aux = nullptr;
        Nodo* temp = head;
        while(temp != nullptr && temp -> dato != n){
            aux = temp;
            temp = temp -> next;
        }
        if(temp == nullptr){
            return;
        }
        aux -> next = temp -> next;
        delete temp;
    }

    bool hasCycle() const{
        if(head == nullptr){
            return false;
        }
        Nodo* slow = head;
        Nodo* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        if(slow == fast){
            return true;
        }
        return false;
    }


};

ostream &operator<<(ostream& os, const LinkedList& list){
    Nodo* newNodo = list.getHead();
    while(newNodo != nullptr){
        os << newNodo -> dato << " ";
        newNodo = newNodo -> next;
    }
    return os;
}

// ostream &operator<<(ostream& os, const LinkedList& list){
//     Nodo* slow = list.getHead();
//     Nodo* fast = list.getHead();
//     if (slow == nullptr || slow == fast || !list.hasCycle()) {
//         Nodo* newNodo = list.getHead();
//         while (newNodo != nullptr){
//             os << newNodo -> dato << " ";
//             newNodo = newNodo -> next;
//         }
//     } else {
//         os << "La lista tiene un ciclo, no se puede imprimir." << endl;
//     }
//     return os;
// }

int main(){
    LinkedList list;
    list.pushFront(40);
    list.pushBack(50);
    list.pushBack(60);
    list.pushBack(70);
    list.pushBack(80);
    list.pushBack(90);
    list.pushBack(100);

    // Nodo* temp = list.getHead();
    // while (temp->next != nullptr) {
    //     temp = temp->next;
    // }

    // temp -> next = list.getHead() -> next;

    // cout << list << endl;

    // if(list.hasCycle()){
    //     cout << "La lista tiene un ciclo" << endl;
    // }else{
    //     cout << "La lista no tiene un ciclo" << endl;
    // }
}

/*
#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <utility>
template <class T>
class LinkedList{
    struct Nodo{
        T data;
        Nodo* next;
    };

    Nodo* head;
public:
    LinkedList() : head(nullptr){}
    ~LinkedList();

    T front();
    T back();
    void push_front(T);
    void push_back(T);
    T pop_front();
    T pop_back();
    bool empty();
    int size();
    void clear();
    void sort();
    void reverse();

    void print() {
        Nodo* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

template<class T>
LinkedList<T>::~LinkedList(){
    while(head){
        Nodo* temp = head;
        head = head -> next;
        delete temp;
    }
}

template<class T>
T LinkedList<T>::front(){
    if(head == NULL){
        cout << "Lista vacia";
        return;
    }
    
    if(head){
        return head -> data;
    }
}

template<class T>
T LinkedList<T>::back(){
    if(head == NULL){
        cout << "Lista vacia" << endl;
        return;
    }

    Nodo *temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }
    return temp -> data;
}


template<class T>
void LinkedList<T>::push_front(T n){
    Nodo *nodo = new Nodo();
    nodo -> data = n;
    nodo -> next = head;
    head = nodo;
}

template<class T>
void LinkedList<T>::push_back(T n){
    Nodo *lista = new Nodo();
    lista -> data = n;
    lista -> next = nullptr;

    if(head == NULL){
        head = lista;
        return;
    }

    Nodo *temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = lista;
}

template<class T>
T LinkedList<T>::pop_front(){    
    if(head == NULL){
        return;
    }
    Nodo *temp = head;
    head = head -> next;
    delete temp;
}

template<class T>
T LinkedList<T>::pop_back(){
    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        delete head;
        head = nullptr;
        return;
    }

    Nodo *current = head;
    while(current -> next -> next){
        current = current -> next;
    }
    delete current -> next;
    current -> next = nullptr;

}

//Sobrecarga de []

template<class T>
bool LinkedList<T>::empty(){
    return head == nullptr;
}

template<class T>
int LinkedList<T>::size(){
    int contador = 0;
    Nodo *current = head;
    while(current){
        ++contador;
        current = current -> next;
    }
    return contador;
}

template<class T>
void LinkedList<T>::clear(){
    while(head != NULL){
        Nodo *temp = head;
        head = head -> next;
        delete temp;
    }
}

template<class T>
void LinkedList<T>::sort(){
    if(head == NULL !! head -> next == NULL){
        return;
    }

    bool swapped;
    do{
        swapped = false;
        Nodo *current = head;
        while(current -> next){
            if(current -> data > current -> next -> data){
                swap(current -> data, current -> next -> data);
                swapped = true;
            }
        }
    }while(swapped);
}

template<class T>
void LinkedList<T>::reverse(){
    Nodo* prev = nullptr;
    Nodo* current = head;
    Nodo* next = nullptr;

    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}
#endif
*/



