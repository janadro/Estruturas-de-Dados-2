#include "lista.h"

// Autor: Leandro Chesini

noLista *alocaNoLista(unsigned long naochave, unsigned long bloco, unsigned short int registro) {
    noLista *reg = malloc(sizeof(noLista));
    if (reg == NULL)
        return NULL;
    reg->naochave = naochave;
    reg->bloco = bloco;
    reg->registro = registro;
    reg->prox = NULL;
    return reg;
}

// Autora: Janaine Rodrigues
void insereNoLista(noLista **h, unsigned long naochave, unsigned long bloco, unsigned short int registro) {
	if((*h) == NULL)
		*h = alocaNoLista(naochave, bloco, registro);
	else
		insereNoLista(&((*h)->prox), naochave, bloco,registro);
}