#include "redblack.h"

// Todas as funções implementadas por Leandro Chesini

noLista* buscaRedBlack(redblack *rbt, unsigned long naochave) {
	if(rbt == NULL) 
		return NULL;
	if (naochave == rbt->naochave){
		return rbt->regs;
	}

	if (naochave < rbt->naochave)
		buscaRedBlack(rbt->esq, naochave);
	else
		buscaRedBlack(rbt->dir, naochave);
}

redblack* insereRedBlack(redblack *rbt, unsigned long naochave, unsigned long bloco, unsigned short int registro) {

	if (rbt == NULL){
		rbt = criaNoRedBlack(NULL, naochave, bloco, registro);
		rbt->cor = BLACK;
		return rbt;
	}

	redblack *head = rbt;
	while(rbt->naochave != naochave){

		if(naochave < rbt->naochave){
			if(rbt->esq != NULL){
				rbt = rbt->esq;
			}else{
				rbt->esq = criaNoRedBlack(rbt, naochave, bloco, registro);
				break;
			}
		}else{
			if(naochave == rbt->naochave){
				insereNoLista(&(rbt->regs), naochave, bloco, registro);
			}else{
				if (rbt->dir != NULL){
					rbt = rbt->dir;
				}else{
					rbt->dir = criaNoRedBlack(rbt, naochave, bloco, registro);
					break;
				}
			}
		}
	}
	if (rbt->naochave == naochave){
		insereNoLista(&(rbt->regs), naochave, bloco, registro);
		return head;
	}

	if (rbt->esq != NULL && rbt->esq->naochave == naochave)
		corrigirPropriedade(rbt->esq);
	else
		corrigirPropriedade(rbt->dir);

	return corrigeRaiz(head);
}

redblack* criaNoRedBlack(redblack *pai, unsigned long naochave, unsigned long bloco, unsigned short int registro){

	redblack* rbt = (redblack*)malloc(sizeof(redblack));
	if (rbt == NULL)
		return NULL;

	rbt->naochave = naochave;
	rbt->regs = NULL;
	insereNoLista(&(rbt->regs), naochave, bloco, registro);
	rbt->cor = RED;
	rbt->pai = pai;
	rbt->esq = rbt->dir = NULL;
	return rbt;
}

redblack* noAvo(redblack *rbt){
	if(rbt != NULL && rbt->pai != NULL) 
		return rbt->pai->pai;
	return NULL;
}

redblack* noTio(redblack *avo, redblack *rbt){
	if (avo->esq == rbt->pai) 
		return avo->dir;
	return avo->esq;
}

redblack* corrigeRaiz(redblack *rbt){
	if (rbt == NULL) 
		return NULL;
	
	while(rbt->pai != NULL) 
		rbt = rbt->pai;
	return rbt;
}


void rotacao_esq(redblack *rbt){
	if (rbt->pai != NULL){
		if (rbt == rbt->pai->esq)
			rbt->pai->esq = rbt->dir;
		else
			rbt->pai->dir = rbt->dir;
	}
	rbt->dir->pai = rbt->pai;
	rbt->pai = rbt->dir;
	rbt->dir = rbt->dir->esq;
	rbt->pai->esq = rbt;
	if (rbt->dir) 
		rbt->dir->pai = rbt;
}

void rotacao_dir(redblack *rbt){
	if (rbt->pai != NULL){
		if (rbt == rbt->pai->esq)
			rbt->pai->esq = rbt->esq;
		else
			rbt->pai->dir = rbt->esq;
	}
	rbt->esq->pai = rbt->pai;
	rbt->pai = rbt->esq;
	rbt->esq = rbt->esq->dir;
	rbt->pai->dir = rbt;
	if (rbt->esq)
		rbt->esq->pai = rbt;
}

void corrigirPropriedade(redblack *rbt){
	if (rbt->pai == NULL){
		rbt->cor = BLACK;
		return;
	}

	if (rbt->pai->cor == BLACK)
		return;

	redblack *avo = noAvo(rbt);
	redblack *tio = noTio(avo, rbt);

	if (tio != NULL && tio->cor == RED){
		tio->cor = rbt->pai->cor = BLACK;
		avo->cor = RED;
		corrigirPropriedade(avo);
		return;
	}

	if (rbt == rbt->pai->dir && rbt->pai == avo->esq){
		rotacao_esq(rbt->pai);
		rbt = rbt->esq;
	}else{
		if (rbt == rbt->pai->esq && rbt->pai == avo->dir){
			rotacao_dir(rbt->pai);
			rbt = rbt->dir;
		}
	}

	rbt->pai->cor = BLACK;
	avo->cor = RED;
	if (rbt == rbt->pai->esq)
		rotacao_dir(avo);
	else
		rotacao_esq(avo);
}