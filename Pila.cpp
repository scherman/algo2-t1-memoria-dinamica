//
// Created by jscherman on 25/08/16.
//

#include "Pila.h"

Pila::Pila() {
    vacia();
}

Pila::~Pila() {
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
    Pila pila;
    if (aCopiar.prim == NULL) return pila;
    for (Nodo* actual = aCopiar.prim; actual != NULL; actual = actual->sig) {
        pila.apilar(actual->elem);
    }
    return pila;
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
