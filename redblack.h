#ifndef REDBLACK_H
#define REDBLACK_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define BLACK 0
#define RED 1

int last;

typedef struct NoRedBlack{
    unsigned long naochave;
    noLista *regs;

	/* Campos especificos da Red-black */
    unsigned short int cor;
    struct NoRedBlack *esq, *dir, *pai;
}redblack;

noLista* buscaRedBlack(redblack *rbt, unsigned long naochave);
redblack* insereRedBlack(redblack *rbt, unsigned long naochave, unsigned long bloco, unsigned short int registro);

redblack* criaNoRedBlack(redblack *pai, unsigned long naochave, unsigned long bloco, unsigned short int registro);
redblack* noAvo(redblack *rbt);
redblack* noTio(redblack *avo, redblack *rbt);
redblack* corrigeRaiz(redblack *rbt);
void corrigirPropriedade(redblack *rbt);
void rotaciona_esq(redblack *rbt);
void rotaciona_dir(redblack *rbt);

#endif