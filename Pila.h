//
// Created by jscherman on 25/08/16.
//

#ifndef ALGO2_T1_MEMORIA_DINAMICA_PILA_H
#define ALGO2_T1_MEMORIA_DINAMICA_PILA_H

typedef unsigned long Nat;

#include <string>
#include <ostream>
#include <iostream>
using namespace std;

// Los datos de un elemento de pila
struct ElemPila {
public:
    int id;
    string nombre;
    string descripcion;

    // Como mostrar un elemento de pila
    friend ostream& operator<<(ostream& os, const ElemPila& a) {
        os << "{Id:" << a.id << ", " << "Nombre:" << a.nombre << ", Descripción:" << a.descripcion <<"}";
        return os;
    }

};

class Pila {

private:

    struct Nodo {
        ElemPila elem;
        Nodo* sig;
    };

    Nodo* prim;
    Nat tam;

public:

    // Constructor y destructor
    Pila();
    ~Pila();

    // Generadores
    void vacia();
    void apilar(ElemPila& elem);

    // Observadores básicos
    bool esVacia();
    ElemPila& tope();
    ElemPila& desapilar();

    // Otras operaciones
    Nat tamanio() const;

    // Asignacion
    Pila& operator=(const Pila & aCopiar);

    // Muestra la lista en un ostream
    // formato de salida: [e_0, e_1, e_2, ...]
    // donde e_i es el resultado del "mostrar" del ElemPila i
    void mostrar(ostream& os) const;

    friend ostream& operator<<(ostream& os, const Pila &p) {
        p.mostrar(os);
        return os;
    }

};

#endif //ALGO2_T1_MEMORIA_DINAMICA_PILA_H
