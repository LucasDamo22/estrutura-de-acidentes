
#include <iostream>
#include <sstream>
using namespace std;

#include "LinkedListOfAcidente.h"

#define IndexOutOfBoundsException 0
/**
 * Construtor da lista.
 */
LinkedListOfAcidente::LinkedListOfAcidente()
{
  head = NULL;
  tail = NULL;
  count = 0;
}

/**
 * Impressão da lista.
 */
void LinkedListOfAcidente::ImprimeLista() {
    NodoAcidente *ptr;
    if (head == NULL) {
      cout << "--- Lista de Acidentes desta rua esta Vazia\n" << endl;
      return;
    }
    // Caso a lista nao esteja vazia
    ptr = head;
    while (true)
    {
      cout << ptr->toString() << endl;
      ptr = ptr->next;
      if (ptr==NULL)
        break;
    }
    cout << "--- Fim da lista ---" << endl;
}

/**
     * Retorna true se a lista nao contem elementos.
     * @return true se a lista nao contem elementos
     */
bool LinkedListOfAcidente::isEmpty() {
  return (head == NULL);
}
/**
     * Retorna o numero de elementos da lista.
     * @return o numero de elementos da lista
     */
int LinkedListOfAcidente::size() {
  return count;
}
/**
     * Esvazia a lista
     */

bool LinkedListOfAcidente::contains(string element){
  NodoAcidente *ptr;
  if (isEmpty())
    return false; // Lista Vazia

  // Caso a lista nao esteja vazia
  ptr = head;
  while (ptr != NULL) {
    if (ptr->TipoAcidente == element) // achou !!
      return true;               //
    else
      ptr = ptr->next; // avança para o próximo NodoSTR
  }
  return false;
}


void LinkedListOfAcidente::clear() {
  NodoAcidente *ptr;
  if (head == NULL) {
    cout << "--- Lista já estava Vazia\n";
    return;
  }
    // Caso a lista nao esteja vazia
    // Apaga cada elemento
  ptr = head;
  NodoAcidente *aux;
  while (true) {
    aux = ptr;
    ptr = ptr->next;
    delete aux;
    if (ptr==NULL)
      break;
    }
  
    head = NULL;
    tail = NULL;
    count = 0;
    
}
/**
     * Adiciona um elemento ao final da lista.
     */

void LinkedListOfAcidente::add(string dia, int nVeiculos, int nMotos, string TipoAcidente){
    NodoAcidente *n;
    n = new NodoAcidente(dia, nVeiculos, nMotos, TipoAcidente);

    if (head==NULL) // Lista Vazia??
      head = n;
    else {
      tail->next = n;
    }
    tail = n;
    count++;
}
/**
     * Retorna uma referencia para o elemento de uma determinada posicao da lista.
     * @param index a posição da lista
     * @return o elemento da posicao especificada
     * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
     */

NodoAcidente* LinkedListOfAcidente::get(int index) {
    if ((index < 0) || (index >= count)) {
      throw IndexOutOfBoundsException;
    }
    if (index == count-1)
      return tail;
    NodoAcidente *aux = head;
    int c = 0;
    while (c < index) {
      aux = aux->next;
      c++;
    }
    return aux;
}
/**
     * Gera uma string com itens da lista
     *  @return String com itens da lista separdos por vírgula
     */
string LinkedListOfAcidente::toString() {
  stringstream SS; // usado para converter inteiro para string
  string S;
    
  NodoAcidente *aux = head;

  if (isEmpty())
    return S; // retorna uma string vazia.
  for(int i=0; i<count-1; i++) {
    SS << aux->toString() << ", ";
    aux = aux->next;
  }
    
  SS << aux->toString();
    
  S = SS.str();
  return S;
}


/**
     * Substitui o elemento armazenado em uma determinada posicao da lista pelo elemento indicado.
     * @param index a posicao na lista
     * @param element o elemento a ser armazenado na lista
     * @return o elemento armazenado anteriormente na posicao da lista
     * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
     */

/**
 * Remove a primeira ocorrencia do elemento na lista, se estiver presente.
 * @param TipoAcidente o elemento a ser removido
 * @return true se a lista contem o elemento especificado
 */
bool LinkedListOfAcidente::remove(string TipoAcidente)
{
  // retorna false se a lista estiver vazia
    if (count == 0)
        return false;
    
    if(head->TipoAcidente == TipoAcidente) { // Esta' removendo o primeiro?
        NodoAcidente *aux = head;  // guarda um apontador para o 1o. elemento
        
        head = head->next; // ajusta o apontador do inicio
        if (count==1) // se tinha apenas um elemento na lista
            tail = NULL; // ajusta o apontador do fim
        count--;
        
        delete aux;// apaga o NodoSTR q esta' sendo retirado
        return true;
    }
    
    // Nao era o 1o. da lista
    NodoAcidente *aux = head->next;
    NodoAcidente *ant = head; // Guarda o anterior paa poder remover
    
    // Procura pelo elemento na lista
    while (aux != NULL) {
        if (aux->TipoAcidente == TipoAcidente) { // encontrou a 1a. ocorrencia?
            if (aux == tail) { // remocao do ultimo ??
                tail = ant;
                tail->next = NULL;
            }
            else { // remocao do meio
                ant->next = aux->next;
            }
            count--;
            delete aux; // apaga o NodoSTR q esta' sendo retirado
            return true;
        }
        // Avanca os dois apontadores para a próxima posicao da lista
        ant = ant->next;
        aux = aux->next;
    }
    
    return false;
  
}
int LinkedListOfAcidente::num_acid_moto(){
    int numAcidMoto = 0;
    NodoAcidente *ptr;
    ptr = head;
    while(ptr!=NULL){
        if(ptr->nMotos>0){
            numAcidMoto++;
        }
        ptr = ptr->next;
    }
    return numAcidMoto;
}

