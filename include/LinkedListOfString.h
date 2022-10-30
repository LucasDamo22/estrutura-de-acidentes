#include "NodoSTR.h"
#ifndef _LISTASE
#define _LISTASE
// ****************************
// Lista Simplesmente Encadeada
class LinkedListOfString{
// Referência para o primeiro elemento da lista encadeada.
    NodoSTR *head;
    // Referência para o último elemento da lista encadeada.
    NodoSTR *tail;
    // Contador para a quantidade de elementos que a lista contem.
    int count;
    
public:
    LinkedListOfString();
    void ImprimeLista();
    bool isEmpty();
    int size();
    void clear();
    void add(string element);
    void add(string NomeDaRua, string dia, int nVeiculos, int nMotos, string TipoAcidente);
    
    string get(int index);
    string toString();
    string set(int index, string element);
    void add(int index, string element);
    bool remove(string element);
    string removeByIndex(int index);
    int indexOf(string element);
    bool contains(string element);
    NodoSTR* getRef(string element);
    string *subList(int fromIndex, int toIndex);
    void printBackToFront();
    void recursivePrintBackToFront();
    void recursivePrintBackToFront(NodoSTR* n) ;
    bool equals(LinkedListOfString *l);
    void addIncreasingOrder(string element);
    void imprimeMaiores(string n);
    NodoSTR* EncontraAnterior(NodoSTR* ptr);
    void removeMaiores(string n);
    void RemoveAcidentes(string tipo);
    
};

#endif
