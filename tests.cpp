#include "Pila.h"
#include "mini_test.h"

// para compilar:$ g++ -g tests.cpp Pila.cpp -o Pila
// para ejecutar con valgrind:$ valgrind --leak-check=full -v ./Pila

ElemPila &elemento1();
ElemPila &elemento2();

void test_vacia() {
    Pila p;
    ASSERT_EQ(p.tamanio(), 0);
}

void test_apilar() {
    Pila p;
    p.apilar(elemento1());
    p.apilar(elemento2());
    ASSERT_EQ(p.tamanio(), 2);
}


void test_mostrar() {
    Pila pila;
    pila.apilar(elemento1());
    pila.apilar(elemento2());
    std::cout << "Deberia tener 2 elementos: " << pila;
}

void test_tope() {
    Pila p;
    p.apilar(elemento1());
    p.apilar(elemento2());
    ASSERT(p.tope().id == elemento2().id);
    ASSERT(p.tope().nombre == elemento2().nombre);
    ASSERT(p.tope().descripcion == elemento2().descripcion);
}

void test_desapilar() {
    Pila pila;
    pila.apilar(elemento1());
    pila.apilar(elemento2());
    pila.desapilar();
    ASSERT_EQ(pila.tamanio(), 1);
    ASSERT(pila.tope().id == elemento1().id);
    ASSERT(pila.tope().nombre == elemento1().nombre);
    ASSERT(pila.tope().descripcion == elemento1().descripcion);
}

void test_asignacion() {
    Pila pila;
    pila.apilar(elemento1());
    pila.apilar(elemento2());

    Pila copia;
    copia = pila;
    ASSERT(pila.tamanio() == copia.tamanio());
}


ElemPila &elemento1() {
    ElemPila *elem = new ElemPila;
    elem->id = 1;
    elem->nombre = "Ramon";
    elem->descripcion = "Tiene todo lo que quieren las wachas";
    return *elem;
}

ElemPila &elemento2() {
    ElemPila *elem = new ElemPila;
    elem->id = 2;
    elem->nombre = "Jorge";
    elem->descripcion = "No tiene descripcion";
    return *elem;
}

int main() {
    RUN_TEST(test_vacia);
    RUN_TEST(test_apilar);
    RUN_TEST(test_mostrar);
    RUN_TEST(test_tope);
    RUN_TEST(test_desapilar);
    RUN_TEST(test_asignacion);

    return 0;
}
