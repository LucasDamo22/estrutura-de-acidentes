
#include <iostream>
#include <sstream>
using namespace std;

#include "LinkedListOfString.h"

#define IndexOutOfBoundsException 0
/**
 * Construtor da lista.
 */
LinkedListOfString::LinkedListOfString()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

/**
 * Impressão da lista.
 */
void LinkedListOfString::ImprimeLista()
{
    NodoSTR *ptr;
    if (head == NULL)
    {
        // printf("--- Lista Vazia\n");
        return;
    }
    // Caso a lista nao esteja vazia
    ptr = head;
    while (true)
    {
        cout << ptr->element << endl;
        ptr->AcidentesNaRua.ImprimeLista();
        ptr = ptr->next;
        if (ptr == NULL)
            break;
    }
    cout << "--- Fim da lista ---" << endl;
}

/**
 * Retorna true se a lista nao contem elementos.
 * @return true se a lista nao contem elementos
 */
bool LinkedListOfString::isEmpty()
{
    return (head == NULL);
}
/**
 * Retorna o numero de elementos da lista.
 * @return o numero de elementos da lista
 */
int LinkedListOfString::size()
{
    return count;
}
/**
 * Esvazia a lista
 */
void LinkedListOfString::clear()
{
    NodoSTR *ptr;
    if (head == NULL)
    {
        printf("--- Lista já estava Vazia\n");
        return;
    }
    // Caso a lista nao esteja vazia
    // Apaga cada elemento
    ptr = head;
    NodoSTR *aux;
    while (true)
    {
        cout << "Apagando " << ptr->element << endl;
        aux = ptr;
        ptr = ptr->next;
        delete aux;
        if (ptr == NULL)
            break;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}
/**
 * Adiciona um elemento ao final da lista.
 * @param element elemento a ser adicionado ao final da lista
 */
// Exercício A.2)
// Evitar a inserção de ruas duplicadas

void LinkedListOfString::add(string element)
{
    NodoSTR *ptr;
    NodoSTR *n = new NodoSTR(element);
    if (head == NULL)
    {
        head = n;
        tail = n;
        count++;
        return;
    }
    else
    {

        ptr = head;

        while (true)
        {
            if (element == ptr->element)
            {
                delete n;
                return;
            }
            else
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {
                break;
            }
        }

        tail->next = n;
        tail = n;
        count++;
    }
}

// Exercício D.1)
// Analise o código do método addIncreasingOrder
// e altere o método add a seguir.

void LinkedListOfString::add(string NomeDaRua, string dia, int nVeiculos,
                             int nMotos, string TipoAcidente)
{
    // Exercício C.3)
    // Crie o código para este novo método ADD da lista
    // Se a rua não existe ainda, insere um nodo na lista de ruas
    // Independente disto, depois, insere os dados do acidente na
    // lista AcidentesNaRua
    // Sugestão: veja o metodo getRef
    NodoSTR *ptr;
    NodoSTR *n = new NodoSTR(NomeDaRua);
    n->AcidentesNaRua.add(dia, nVeiculos, nMotos, TipoAcidente);

    if (head == NULL)
    {
        head = n;
        tail = n;
        count++;
        return;
    }
    else
    {
        int i;
        NodoSTR *aux = head;
        for (i = 0; i < count; i++)
        {
            if(aux->element==NomeDaRua)
            break;
            if (aux->element > NomeDaRua){
                add(i, NomeDaRua);
                break;
            }
                
            aux = aux->next;
        }
        

        ptr = head;

        while (true)
        {
            if (NomeDaRua == ptr->element)
            {
                ptr->AcidentesNaRua.add(dia, nVeiculos, nMotos, TipoAcidente);
                delete n;
                return;
            }
            else
            {
                ptr = ptr->next;
            }
            if (ptr == NULL)
            {

                break;
            }
        }

        tail->next = n;
        tail = n;
        count++;
    }
}

/**
 * Retorna o elemento de uma determinada posicao da lista.
 * @param index a posição da lista
 * @return o elemento da posicao especificada
 * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
 */

string LinkedListOfString::get(int index)
{
    if ((index < 0) || (index >= count))
    {
        throw IndexOutOfBoundsException;
    }
    if (index == count - 1)
        return tail->element;

    NodoSTR *aux = head;
    int c = 0;
    while (c < index)
    {
        aux = aux->next;
        c++;
    }
    return (aux->element);
}
/**
 * Gera uma string com itens da lista
 *  @return String com itens da lista separdos por vírgula
 */
string LinkedListOfString::toString()
{
    stringstream SS; // usado para converter inteiro para string
    string S;

    NodoSTR *aux = head;

    if (isEmpty())
        return S; // retorna uma string vazia.

    for (int i = 0; i < count - 1; i++)
    {
        SS << aux->element << ", ";
        aux = aux->next;
    }
    SS << aux->element;

    S = SS.str();
    return S;
}

/**
 * Insere um elemento em uma determinada posicao da lista.
 * @param index a posicao da lista onde o elemento sera inserido
 * @param element elemento a ser inserido
 * @throws IndexOutOfBoundsException se (index < 0 || index > size())
 */
void LinkedListOfString::add(int index, string element)
{
    if ((index < 0) || (index > count))
    {
        throw IndexOutOfBoundsException;
    }

    // Criar o NodoSTR
    NodoSTR *n = new NodoSTR(element);
    // Incrementar count
    count++;

    // "Encadear" o NodoSTR criado na lista
    if (index == 0)
    { // Insercao no inicio
        if (head == NULL)
        { // se a lista estiver vazia
            tail = n;
        }
        else
        { // se a lista não estiver vazia
            n->next = head;
        }
        head = n;
    }
    else if (index == count)
    {                   // Insercao no final
        tail->next = n; // "conecta" o NodoSTR na lista
        tail = n;       // atualiza tail
    }
    else
    { // Insercao no meio
        // caminha ate a posicao anterior a posicao onde se
        // desenha inserir
        NodoSTR *ant = head;
        for (int i = 0; i < index - 1; i++)
            ant = ant->next;

        n->next = ant->next; // "conecta" o NodoSTR na lista
        ant->next = n;
    }
}
/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo elemento indicado.
 * @param index a posicao na lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
 */
string LinkedListOfString::set(int index, string element)
{
    if ((index < 0) || (index >= count))
    {
        throw IndexOutOfBoundsException;
    }
    // Verifica se eh a ultima posicao
    if (index == count - 1)
    {
        string num = tail->element;
        tail->element = element;
        return num;
    }

    // "caminha" ate a posicao index
    NodoSTR *aux = head;
    for (int i = 0; i < index; i++)
    {
        aux = aux->next;
    }
    // guarda o elemento que esta na posicao index
    string num = aux->element;

    // coloca "element" na posicao index
    aux->element = element;

    // retorna o elemento guardado
    return num;
}
/**
 * Remove a primeira ocorrencia do elemento na lista, se estiver presente.
 * @param element o elemento a ser removido
 * @return true se a lista contem o elemento especificado
 */
bool LinkedListOfString::remove(string element)
{
    // retorna false se a lista estiver vazia
    if (count == 0)
        return false;

    if (head->element == element)
    {                        // Esta' removendo o primeiro?
        NodoSTR *aux = head; // guarda um apontador para o 1o. elemento

        head = head->next; // ajusta o apontador do inicio
        if (count == 1)    // se tinha apenas um elemento na lista
            tail = NULL;   // ajusta o apontador do fim
        count--;

        delete aux; // apaga o NodoSTR q esta' sendo retirado
        return true;
    }

    // Nao era o 1o. da lista
    NodoSTR *aux = head->next;
    NodoSTR *ant = head; // Guarda o anterior paa poder remover

    // Procura pelo elemento na lista
    while (aux != NULL)
    {
        if (aux->element == element)
        { // encontrou a 1a. ocorrencia?
            if (aux == tail)
            { // remocao do ultimo ??
                tail = ant;
                tail->next = NULL;
            }
            else
            { // remocao do meio
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
/**
 * Remove o elemento de uma determinada posicao da lista.
 * @param index a posicao da lista
 * @return o elemento que foi removido da lista
 * @throws IndexOutOfBoundsException se (index < 0 || index >= size())
 */
string LinkedListOfString::removeByIndex(int index)
{
    if ((index < 0) || (index >= count))
    {
        throw IndexOutOfBoundsException;
    }

    // Remocao do primeiro elemento da lista
    if (index == 0)
    {
        string elem = head->element; // guarda o elemento que sera' removido
        NodoSTR *aux = head;         // guarda um apontador para o 1o. elemento

        head = head->next;
        if (count == 1) // se tinha apenas um elemento na lista
            tail = NULL;
        count--;
        delete aux;  // apaga o NodoSTR q esta' sendo removido
        return elem; // retorna o elemento removido
    }

    // Remove do meio ou do final
    NodoSTR *aux = head;
    NodoSTR *ant = NULL;
    for (int i = 0; i < index; i++)
    {
        ant = aux;
        aux = aux->next;
    }
    // Se for remocao do ultimo
    if (tail == aux)
    {
        tail = ant;
        tail->next = NULL;
    }
    else
    { // remocao do meio
        ant->next = aux->next;
    }
    count--;
    delete aux; // apaga o NodoSTR q esta' sendo removido
    return aux->element;
}
/**
 * Retorna o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento.
 * @param element o elemento a ser buscado
 * @return o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento
 */
int LinkedListOfString::indexOf(string element)
{
    NodoSTR *aux = head;
    for (int i = 0; i < count; i++)
    {
        if (aux->element == element)
            return i;
        aux = aux->next;
    }
    return -1;
}
/**
 * Informa se o elemento especificado existe
 * @param element o elemento a ser buscado
 * @return uma referencia para o nodo que contem o elemento especificado.
 * @return null caso a lista não contem o elemento especificado
 */
bool LinkedListOfString::contains(string element)
{
    NodoSTR *ptr;
    if (isEmpty())
        return false; // Lista Vazia

    // Caso a lista nao esteja vazia
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->element == element) // achou !!
            return true;             //
        else
            ptr = ptr->next; // avança para o próximo NodoSTR
    }
    return false;
}

/**
 * Retorna uma referencia para o nodo que contem o elemento especificado.
 * @param element o elemento a ser buscado
 * @return uma referencia para o nodo que contem o elemento especificado.
 * @return null caso a lista não contem o elemento especificado
 */
NodoSTR *LinkedListOfString::getRef(string element)
{
    NodoSTR *ptr;
    if (isEmpty())
        return NULL; // Lista Vazia

    // Caso a lista nao esteja vazia
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->element == element) // achou !!
            return ptr;              //
        else
            ptr = ptr->next; // avança para o próximo NodoSTR
    }
    return NULL;
}

/**
 * Retorna um arranjo com os elementos da lista original entre
 * fromIndex (inclusivo) e toIndex (exclusivo).
 * @param fromIndex posicao a partir da qual os elementos serao inseridos no
 * arranjo a ser retornado
 * @param toIndex indica a posicao final dos elementos que devem ser
 * inseridos
 * @return Um arranjo com um subconjunto dos elementos da lista.
 * @throws IndexOutOfBoundsException se (fromIndex < 0 || toIndex > size())
 * @throws IllegalArgumentException se (fromIndex > toIndex)
 */
string *LinkedListOfString::subList(int fromIndex, int toIndex)
{
    // Primeiro verifica se os indices sao validos
    if (fromIndex < 0 || toIndex > size())
    {
        cout << "Indices invalidos!" << endl;
        throw IndexOutOfBoundsException;
    }
    if (fromIndex >= toIndex) //
    {
        cout << "fromIndex deve ser menor que toIndex!" << endl;
        throw IndexOutOfBoundsException;
    }

    // Instancia o arranjo
    string *a = new string[toIndex - fromIndex];

    // Percorre a lista ate a posicao fromIndex
    NodoSTR *aux = head;
    for (int i = 0; i < fromIndex; i++)
    { // para "chegar" ate a posicao fromIndex
        aux = aux->next;
    }

    // Percorre a lista de fromIndex a toIndex copiando os elementos para o arranjo
    int pos = 0;
    for (int i = fromIndex; i < toIndex; i++)
    {
        a[pos] = aux->element;
        aux = aux->next;
        pos++;
    }

    // Retorna o arranjo
    return a;
}

// Metodo que imprime a lista de trás para frente, não recursivo
void LinkedListOfString::printBackToFront()
{ // O(n)
    string *a = new string[count];
    NodoSTR *aux = head;
    for (int i = 0; i < count; i++)
    {
        a[i] = aux->element;
        aux = aux->next;
    }
    for (int i = count - 1; i >= 0; i--)
        cout << a[i] << endl;
    delete[] aux;
}

// Metodo que imprime a lista de trás para frente, recursivo
void LinkedListOfString::recursivePrintBackToFront()
{ // O(n)
    if (count != 0)
        recursivePrintBackToFront(head);
}

void LinkedListOfString::recursivePrintBackToFront(NodoSTR *n)
{
    if (n == tail)
    {
        cout << n->element << endl;
    }
    else
    {
        recursivePrintBackToFront(n->next);
        cout << n->element << endl;
    }
}

bool LinkedListOfString::equals(LinkedListOfString *l)
{
    if (count != l->count) // se as listas possuem tamanhos diferentes
        return false;      // retorna falso

    NodoSTR *aux = head;
    NodoSTR *auxL = l->head;

    for (int i = 0; i < count; i++)
    {
        if (!(aux->element == auxL->element))
        {
            return false;
        }
        aux = aux->next;
        auxL = auxL->next;
    }

    return true;
}

void LinkedListOfString::addIncreasingOrder(string element)
{
    int i;
    NodoSTR *aux = head;
    for (i = 0; i < count; i++)
    {
        if (aux->element > element)
            break;
        aux = aux->next;
    }
    add(i, element);
    aux = getRef(element);                                 // obtem uma referencia para o nodo dentro da lista
    cout << "Elemento inserido: " << aux->element << endl; // imprime o nodo
}

void LinkedListOfString::imprimeMaiores(string n)
{
    NodoSTR *ptr;
    if (isEmpty())
        return; // Lista Vazia
                // Caso a lista nao esteja vazia
    cout << "Elementos maiores que " << n << ": ";
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->element > n)            // achou !!
            cout << ptr->element << " "; //
        ptr = ptr->next;                 // avança para o próximo NodoSTR
    }
    cout << endl;
}
NodoSTR *LinkedListOfString::EncontraAnterior(NodoSTR *ptr)
{
    if (ptr == head) // o 1o. nao tem anterior
        return NULL;
    NodoSTR *aux;
    aux = head;
    while (aux != NULL)
    {
        if (aux->next == ptr)
            break;
        aux = aux->next;
    }
    return aux;
}

void LinkedListOfString::removeMaiores(string n)
{
    // Implemente o algoritmo
    NodoSTR *ptr;
    cout << "Remove maiores que " << n << ": " << endl;
    if (isEmpty())
        return; // Lista Vazia
    // Caso a lista nao esteja vazia
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->element > n) // achou um menor!!
        {
            NodoSTR *antes = EncontraAnterior(ptr);
            if (antes == NULL)    // eh o 1o. !
                head = ptr->next; // refaz o encadeamento
            else
            {
                antes->next = ptr->next; // refaz o encadeamento
                if (ptr->next == NULL)   // removendo o último?
                    tail = antes;        // ajusta o tail
            }
            // apaga o NodoSTR
            NodoSTR *aux = ptr->next;
            delete ptr;
            ptr = aux;
            count--;
        }
        else
            ptr = ptr->next; // avança para o próximo NodoSTR
    }
}

// Exercício E.1)
void LinkedListOfString::RemoveAcidentes(string tipo)
{
    NodoSTR *ptr;
    ptr = head;
    if (isEmpty())
        return; // encerra

    for (int i = 0; i < count - 1; i++) // passe em cada rua
    {
        // Passa em cada rua e verifica cada acidente
        // Se o tipo de acidente for igual ao "tipo"
        // então remove o acidente.
        // Olhe o codigo do metodo ImprimeLista
        ptr->AcidentesNaRua.remove(tipo);
        ptr = ptr->next;
        
    }
    NodoSTR *ptr2;
    ptr2 = head;
    int i = 0;
    while(ptr2->next != NULL){
        i++;
        if(ptr2->AcidentesNaRua.isEmpty()){
            removeByIndex(i);
        }
        ptr2 = ptr2->next;
    }
    // Testa se a lista de acidentes ficou vazia.
    // Se ficou, eh preciso remover a rua
}
