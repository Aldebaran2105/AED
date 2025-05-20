#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo* next;
    Nodo* prev;
};

class DoubleLinkedList{
    Nodo* head;
    Nodo* tail;
public:
    DoubleLinkedList(){
        this -> head = nullptr;
        this -> tail = nullptr;
    }

    Nodo* getHead() const{
        return head;
    }

    void pushFront(int n){
        Nodo* newNodo = new Nodo();
        newNodo -> dato = n;
        newNodo -> next = head;
        newNodo -> prev = nullptr;
        if(head != nullptr){
            head -> prev = newNodo;
        }
        head = newNodo;
        if(tail == nullptr){
            tail = newNodo;
        }
    }

    void pushBack(int n){
        if(head == nullptr){
            pushFront(n);
            return;
        }
        Nodo* newNodo = new Nodo();
        newNodo -> dato = n;
        newNodo -> next = nullptr;
        newNodo -> prev = tail;
        tail -> next = newNodo;
        tail = newNodo;
    }

    int pop_front(){
        if(head == nullptr){
            return -1;
        }
        Nodo* aux = head;
        int value = head -> dato;
        head = head -> next;
        if(head != nullptr){
            head -> prev = nullptr;
        }else{
            tail = nullptr;
        }
        delete aux;
        return value;
    }

    int pop_back(){
        if(head == nullptr){
            return -1;
        }
        Nodo* aux = tail;
        int value = tail -> dato;
        if(tail -> prev != nullptr){
            tail = tail -> prev;
            tail -> next = nullptr;
        }else{
            head = nullptr;
            tail = nullptr;
        }
        delete aux;
        return value;
    }

    void insert(int v, int pos){
        if(pos == 0){
            pushFront(v);
            return;
        }
        Nodo* newNodo = new Nodo();
        newNodo -> dato = v;
        Nodo* temp = head;
        int cont = 0
        ;
        while(head != nullptr && cont != pos - 1){
            temp = temp -> next;
            cont++;
        }
        if(temp == nullptr){
            pushBack(v);
        }else{
            newNodo -> next = temp -> next;
            newNodo -> prev = temp;
            if(temp -> next != nullptr){
                temp -> next -> prev = newNodo;
            }
            temp -> next = newNodo;
        }
    }

    int size(){
        int count = 0;
        Nodo* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }
        return count;
    }

    void clear(){
        while(head != nullptr){
            pop_front();
        }
    }

    void reverse(){
        Nodo* temp = nullptr;
        Nodo* current = head;

        while(current != nullptr){
            temp = current -> prev;
            current -> prev = current -> next;
            current -> next = temp;
            current = current -> prev;
        }
        if(temp != nullptr){
            head = temp -> prev;
        }
    }

    void reverseSublist(int m, int n){
        if(m >= n || head == nullptr){
            return;
        }
    
        Nodo* temp = head;
        Nodo* start = nullptr;
        Nodo* end = nullptr;
        int index = 1;
        
        while(temp != nullptr && index <= n){
            if(index == m - 1) start = temp;
            if(index == n) end = temp;
            temp = temp -> next;
            index++;
        }

        if(start == nullptr || end == nullptr) return;
    
        Nodo* sublistStart = start == nullptr ? head : start -> next;
        Nodo* sublistEnd = end;
        if(start != nullptr) start -> next = end -> next;
        if(end -> next != nullptr) end -> next -> prev = start;

        Nodo* prev = nullptr;
        Nodo* curr = sublistStart;
        Nodo* next = nullptr;

        while(curr != nullptr && curr != end -> next){
            next = curr -> next;
            curr -> next = prev;
            curr -> prev = next;
            prev = curr;
            curr = next;
        }
        if(start == nullptr) head = prev;
        else start -> next = prev;
    }

};

ostream &operator<<(ostream& os, const DoubleLinkedList& list){
    Nodo* temp = list.getHead();
    while(temp != nullptr){
        os << temp -> dato << " ";
        temp = temp -> next;
    }
    return os;
}

int main(){
    DoubleLinkedList list;
    list.pushFront(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushBack(40);
    list.pushBack(50);
    list.pushBack(60);
    list.pushBack(70);
    list.pushBack(80);
    list.pushBack(90);
    list.pushBack(100);

    cout << "Lista original: " << list << endl;

    list.reverseSublist(2, 8);

    cout << "Lista luego de revertir: " << list << endl;

    
}