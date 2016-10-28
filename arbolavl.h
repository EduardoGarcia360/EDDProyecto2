#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"

typedef struct NodoAVL NodoAVL;
typedef struct ArbolAVL ArbolAVL;

struct NodoAVL{
    char* placa;
    char* marca;
    char* modelo;
    int anio;
    char* color;
    int precio;
    char* transmision;
    int fe;
    NodoAVL* hijoIzquierdo;
    NodoAVL* hijoDerecho;
    NodoAVL(char* placa, char* marca, char* modelo, int anio, char* color, int precio, char* transmision);
};

struct ArbolAVL{
    NodoAVL* raiz;
    NodoAVL* obtenerRaiz();
    NodoAVL* buscar(char* placa, NodoAVL* r);
    int obtenerFE(NodoAVL* x);
    NodoAVL* rotacionIzquierda(NodoAVL* c);
    NodoAVL* rotacionDerecha(NodoAVL* c);
    NodoAVL* rotacionDobleIzquierda(NodoAVL* c);
    NodoAVL* rotacionDobleDerecha(NodoAVL* c);
    NodoAVL* insertarAVL(NodoAVL* nuevo, NodoAVL* subAr);
    NodoAVL* obtenerNodoReemplazo(NodoAVL* aux);
    void insertar(char* placa, char* marca, char* modelo, int anio, char* color, int precio, char* transmision);
    void preOrden(NodoAVL* r);
    void graficar(NodoAVL* r);
    bool eliminar(char* placa);
};

#endif // ARBOLAVL_H
