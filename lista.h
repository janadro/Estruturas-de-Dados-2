#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{
	unsigned long naochave;
	unsigned long bloco;
	unsigned short int registro;

	unsigned long chave;
	struct noLista *prox;
}noLista;

noLista *alocaNoLista(unsigned long naochave, unsigned long bloco, unsigned short int registro);
void insereNoLista(noLista **h, unsigned long naochave, unsigned long bloco, unsigned short int registro);

#endif