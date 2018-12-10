#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct NoAVL{
	unsigned long naochave;
	noLista* regs; /* Campo para armazenar os registros com naochave repetidos em uma lista */

	/* Campos especificos da AVL */
	struct NoAVL * dir;
	struct NoAVL * esq;
	int fb;
};
typedef struct NoAVL avl;

noLista* buscaAVL(avl *r, unsigned long naochave);
int insereAVL(avl **r, unsigned long naochave, unsigned long bloco, unsigned short int registro);

avl *criaNoAVL(unsigned long naochave, unsigned long bloco, unsigned short int registro);
void rotacaoEsq(avl **r);
void rotacaoDir(avl **r);
int balanceamento(avl **r);

#endif