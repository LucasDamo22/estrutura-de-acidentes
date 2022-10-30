
#include <iostream>
using namespace std;
#include "NodoSTR.h"
NodoSTR::NodoSTR() {
    this->next = NULL;
}
NodoSTR::NodoSTR(string i) {
    this->element = i;
    this->next = NULL;
}
NodoSTR::NodoSTR(string i, NodoSTR *next)
{
    this->element = i;
    this->next = next;
}
