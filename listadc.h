#ifndef LISTADC_H
#define LISTADC_H

typedef struct NodoDC NodoDC;
typedef struct ListaDC ListaDC;

struct NodoDC{
    char* nombreCobertura;
    int sumaAsegurada;
    int prima;
    NodoDC* siguiente;
    NodoDC* anterior;
    NodoDC(char* nombreCobertura, int sumaAsegurada, int prima);
};

struct ListaDC{
    NodoDC* inicio;
    bool estaVacia();
    void insertar(char* nombreCobertura, int sumaAsegurada, int prima);
    void mostrarLista();
    bool eliminar(char* nombreCobertura);
    void modificar(char* clave, char* nombreCobertura, int sumaAsegurada, int prima);
    NodoDC* buscar(char* clave);
};

#endif // LISTADC_H
