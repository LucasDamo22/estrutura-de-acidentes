#include "NodoAcidente.h"
#ifndef _LISTAAC
#define _LISTAAC
// ****************************
// Lista Simplesmente Encadeada
class LinkedListOfAcidente{
// Referência para o primeiro elemento da lista encadeada.
    NodoAcidente *head;
    // Referência para o último elemento da lista encadeada.
    NodoAcidente *tail;
    // Contador para a quantidade de elementos que a lista contem.
    int count;
    
public:
    LinkedListOfAcidente();
    void ImprimeLista();
    bool isEmpty();
    int size();
    void clear();
    
    NodoAcidente* get(int index);
    string toString();
    void add(string dia, int nVeiculos, int nMotos, string TipoAcidente);
    NodoAcidente* removeByIndex(int index);
    bool remove(string TipoAcidente);
};

#endif
