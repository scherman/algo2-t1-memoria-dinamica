//
// Created by jscherman on 25/08/16.
//

#include "Pila.h"

Pila::Pila() {
    vacia();
}

Pila::~Pila() {
    Nodo* actual = this->prim;
    while (actual != NULL) {
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
}

void Pila::vacia() {
    tam = 0;
    prim = NULL;
}

void Pila::apilar(ElemPila &elem) {
    Nodo* aux = this->prim;

    Nodo* nuevo = new Nodo;
    nuevo->elem = elem;
    nuevo->sig = aux;

    this->prim = nuevo;
    this->tam++;
}

bool Pila::esVacia() {
    return this->tam == 0;
}

ElemPila &Pila::tope() {
    return this->prim->elem;
}

ElemPila &Pila::desapilar() {
    Nodo* tope = this->prim;
    this->prim = tope->sig;
    this->tam--;
    return tope->elem;
}

Nat Pila::tamanio() const {
    return this->tam;
}

Pila &Pila::operator=(const Pila &aCopiar) {
    if (aCopiar.prim == NULL) return *this;

    // Copio todo en una pila auxiliar, porque de entrada me quedan al revez los elementos
    Pila temp;
    for (Nodo* actual = aCopiar.prim; actual != NULL; actual = actual->sig) {
        temp.apilar(actual->elem);
    }

    // Voy apilando los nuevos nodos a la nueva pila, en efecto los invierte
    while (temp.tamanio() > 0) this->apilar(temp.desapilar());
    return *this;
}

void Pila::mostrar(ostream &os) const {
    os << "[";
    Nodo* actual = this->prim;
    if (actual != NULL) {
        os << actual->elem;
        actual=actual->sig;
    }
    while (actual != NULL) {
        os << ", " << actual->elem;
        actual = actual->sig;
    }
    os << "]";
}
