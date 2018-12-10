#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "lista.h"
#include "avl.h"
#include "redblack.h"
/*
 * Registro de 1 KiB i.e. 1024 bytes
 */
#define QTD_REG 4

struct registro {
	unsigned long chave;//Campo chave. Valor nao se repete.
	unsigned long naochave;//Campo qualquer. Valor pode repetir.
	unsigned char outros[1008];//outros campos: 1008 bytes (dados)
};

typedef struct registro registro;

void *criarIndice(char nomeArq[], char modoArq[], avl** rAVL, redblack **rRBT);
void acessarRegistros(char nomeArq[], char modoArq[], noLista **head);

#endif