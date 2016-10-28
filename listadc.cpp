#include "listadc.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "iostream"
#include "sstream"
#include "QString"

using namespace std;
bool cima=false;

NodoDC::NodoDC(char *nombreCobertura, int sumaAsegurada, int prima){
    this->nombreCobertura = nombreCobertura;
    this->sumaAsegurada = sumaAsegurada;
    this->prima = prima;
    this->siguiente = this;
    this->anterior = this;
}

bool ListaDC::estaVacia(){
    return inicio==NULL;
}

void ListaDC::insertar(char *nombreCobertura, int sumaAsegurada, int prima){
    NodoDC* nuevo = new NodoDC(nombreCobertura, sumaAsegurada, prima);
    if(cima==false){
        inicio = nuevo;
        cima=true;
    }else{
        NodoDC* aux = inicio;
        while(aux->siguiente != inicio){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
        nuevo->siguiente = inicio;
        inicio->anterior = nuevo;
    }
}

void ListaDC::mostrarLista(){
    cout<<"==============================="<<endl;
    if(cima==false){
        cout<<"<===vacio===>"<<endl;
    }else{
        NodoDC* aux = inicio;
        do{
            char* dato_nodo = (char*)malloc(6);
            strcpy(dato_nodo, aux->nombreCobertura);
            QString texto_n = QString::fromStdString(dato_nodo);
            cout<<texto_n.toStdString()<<endl;

            aux = aux->siguiente;
        }while(aux!=inicio);
    }
    cout<<"==============================="<<endl;
}

void ListaDC::modificar(char *clave, char *nombreCobertura, int sumaAsegurada, int prima){
    if(inicio!=NULL){
        NodoDC* aux = inicio;
        while(aux->siguiente!=inicio){
            if(strcmp(aux->nombreCobertura, clave)==0){
                aux->nombreCobertura = nombreCobertura;
                aux->sumaAsegurada = sumaAsegurada;
                aux->prima = prima;
                break;
            }else{
                aux = aux->siguiente;
            }
        }
    }
}

NodoDC* ListaDC::buscar(char *clave){
    if(inicio!=NULL){
        NodoDC* aux = inicio;
        while(aux->siguiente!=inicio){
            if(strcmp(aux->nombreCobertura, clave)==0){
                return aux;
            }else{
                aux = aux->siguiente;
            }
        }
    }else{
        return NULL;
    }
}

bool ListaDC::eliminar(char *nombreCobertura){
    bool encontrado=false;
    if(inicio!=NULL){
        NodoDC* aux = inicio;
        NodoDC* ant = NULL;
        if(aux->siguiente==inicio){
            /*solo hay un nodo*/
            aux->anterior = NULL;
            aux->siguiente = NULL;
            inicio = NULL;
            free(aux);
            cima=false;
            encontrado=true;
        }else{
            while(aux->siguiente!=inicio){
                if(strcmp(aux->nombreCobertura, nombreCobertura)==0){
                    if(ant==NULL){
                        if(aux->siguiente!=inicio){
                            /*es el "primer" nodo de la lista*/
                            NodoDC* tmp=aux;
                            ant = aux->anterior;
                            ant->siguiente = aux->siguiente;
                            aux = aux->siguiente;
                            aux->anterior = ant;
                            inicio=aux;
                            free(tmp);
                            encontrado=true;
                            break;
                        }
                    }else{
                        /*esta en medio de dos nodos*/
                        NodoDC* tmp = aux;
                        aux->anterior = NULL;
                        ant->siguiente = aux->siguiente;
                        aux = aux->siguiente;
                        aux->anterior = ant;
                        free(tmp);
                        encontrado=true;
                        break;
                    }
                }else{
                    /*si no es igual avanza*/
                    ant = aux;
                    aux = aux->siguiente;
                }
            }//fin while
        }
    }
    return encontrado;
}
