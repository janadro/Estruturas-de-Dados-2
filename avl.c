#include "avl.h"

// Todas as funções implementadas por Janaine Rodrigues

noLista* buscaAVL(avl *r, unsigned long naochave) {

	if(r == NULL)
		return NULL;

	if(naochave == r->naochave)
		return r->regs;

	if(naochave < r->naochave)
		return buscaAVL(r->esq, naochave);
	else
		return buscaAVL(r->dir, naochave);
}

int insereAVL(avl **r, unsigned long naochave, unsigned long bloco, unsigned short int registro) {
	if((*r) == NULL){ //arvore vazia cria novo nó
		*r = criaNoAVL(naochave, bloco, registro);
		return 1; //retorna 1 para informar que a subarvore cresceu.
	}
	int temp = 0;

	if(naochave == (*r)->naochave){
/*		printf("naochave repetido: %lu\n", naochave);
*/		insereNoLista(&((*r)->regs), naochave, bloco, registro);
	}

	if(naochave < (*r)->naochave)
		temp -= insereAVL(&((*r)->esq), naochave, bloco, registro); //Cresce para a esquerda
	else
		temp = insereAVL(&((*r)->dir), naochave, bloco, registro); //Cresce para a direita

	if(temp){//Se houve crescimento
		(*r)->fb += temp; //Atualiza fb do no
		return balanceamento(r); //Realiza balanceamento da arvore
	}
	return 0;
}

avl *criaNoAVL(unsigned long naochave, unsigned long bloco, unsigned short int registro) {
	avl *newNode = malloc(sizeof(avl));
	newNode->naochave = naochave;
	newNode->regs = NULL;
	insereNoLista(&(newNode->regs), naochave, bloco, registro);

	newNode->dir = NULL;
	newNode->esq = NULL;
	newNode->fb = 0;
	return newNode;
}

int balanceamento(avl **r) {
	if((*r)->fb == 2){
		if(((*r)->dir)->fb == -1){ 
			rotacaoDir(&((*r)->dir));
		}
		rotacaoEsq(r);
	}else{
		if((*r)->fb == -2){ 
			if(((*r)->esq)->fb > 0) 
				rotacaoEsq(&((*r)->esq));
			rotacaoDir(r);
		}else{
			if((*r)->fb != 0)
				return 1;
		}
	}
	return 0;
}

void rotacaoEsq(avl **r) {
	if((*r) == NULL) 
		return;
	avl *aux = (*r)->dir;
	(*r)->dir = aux->esq;
	aux->esq = *r;

	if ((*r)->fb == 2) {//Rotacao simples
		if (aux->fb == 2) {
			(*r)->fb = -1;
			aux->fb = 0;
		}else if (aux->fb == 1) {
			(*r)->fb = 0;
			aux->fb = 0;
		}else{
			(*r)->fb = 1;
			aux->fb = -1;
		}
	}else{ //Rotacao dupla
		if (aux->fb == -1) {
			(*r)->fb = 0;
			aux->fb = -2;
		}else if (aux->fb == 1){
			(*r)->fb = -1;
			aux->fb = -1;
		}else{
			(*r)->fb = 0;
			aux->fb = -1;
		}
	}
	(*r) = aux;
}

void rotacaoDir(avl **r) {
	if((*r) == NULL)
		return;
	avl *aux = (*r)->esq;
	(*r)->esq = aux->dir;
	aux->dir = *r;
	if ((*r)->fb == -2) { //Rotacao simples
		if (aux->fb == -2){
			(*r)->fb = 1;
			aux->fb = 0;
		}else if (aux->fb == -1) {
			(*r)->fb = 0;
			aux->fb = 0;
		}else{
			(*r)->fb = -1;
			aux->fb = 1;
		}
	}else{ //Rotacao dupla		
		if (aux->fb == 1) {
			(*r)->fb = 0;
			aux->fb = 2;
		}else if (aux->fb == -1) {
			(*r)->fb = 1;
			aux->fb = 1;
		}else{
			(*r)->fb = 0;
			aux->fb = 1;
		}
	}
	(*r) = aux;
}