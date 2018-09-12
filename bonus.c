#ifndef ARVBINARIA_H
#define ARVBINARIA_H

/*
* A menos que falado de forma diferente, considere que todas as árvores são de pesquisa.
*/

#include <stdlib.h>

struct NoArvBinaria
{
int chave;
struct NoArvBinaria * esq;
struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;


/*
* PROCEDIMENTOS DE BUSCA CLASSICOS
* devolve o endereco do no cujo valor chave eh k
* ou NULL caso tal no nao exista na arvore enraizada
* por raiz.
*/
NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k)
{
	if(raiz == NULL)
		return NULL;

	if(raiz->chave == k)
		return raiz;

	if (raiz->chave < k)
		return buscaArvBinRec(raiz->esq, k);
	else
		return buscaArvBinRec(raiz->dir, k);
}



NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k)
{
	if( raiz == NULL)
		return NULL;

	if (raiz->chave == k)
		return raiz;

	if(raiz->chave < k)

		return raiz->esq;
	else
		return raiz->dir;

}


/*
* Para a função de busca abaixo atente para o fato de que
* a árvore indicada NÃO é de pesquisa!
*/
NoArvBinaria *buscaAB(NoArvBinaria *raiz, int k)
{
	if(raiz == NULL)
		return NULL;
	if(raiz->chave == k)
		return raiz;
	if(raiz->chave != k)
		return buscaAB(raiz->esq, k); 
	else
		return buscaAB(raiz->dir, k);
}



/*
* PROCEDIMENTOS DE BUSCA DO MENOR/MAIOR
* 1) devolve o endereco do no cujo valor chave eh o
* menor da arvore dada ou NULL caso a arvore seja vazia.
*/

NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz) /*1*/
{
     if (raiz == NULL)
     	return NULL;
     if (raiz->esq == NULL)
     	return raiz;
     else
     	return buscaEnderecoDoMenor(raiz->esq);
}

/*
* 2) devolve o endereco do no cujo valor chave eh o
* maior da arvore dada ou NULL caso a arvore seja vazia.
*/

NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz)
{
	if( raiz == NULL)
		return NULL;
	if(raiz->dir == NULL)
		return raiz;
	else
		return buscaEnderecoDoMaior(raiz->dir);
}


/*
* PROCEDIMENTO DE BUSCA DO ENDERECO DO PONTEIRO DO NO k
* devolve o endereco onde está armazenado o endereco do no
* cujo valor chave eh k ou NULL caso tal no nao exista. O
* no raiz da arvore dada esta armazenado no endereco *raiz.
* Assuma que a arvore pode estar vazia, nesse caso *raiz==NULL.
* i.e.: Para arvores nao vazias, a funcao deve devolver um
* ponteiro x tal que a seguinte condicao seja satisfeita:
* (*x)->chave == k
*/
NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k)
{
	if(*raiz == NULL)
		return NULL;
	if((*raiz)->chave == k)
		return (&(*raiz)->chave);
	if((*raiz)->chave < k)
		return buscaEnderecoDoPonteiro(&((*raiz)->esq), k);

	else
		return buscaEnderecoDoPonteiro(&((*raiz)->dir), k);
}


/*
* PROCEDIMENTOS DE BUSCA DO ENDERECO DO PONTEIRO DO MENOR/MAIOR
* 1) devolve o endereco do ponteiro para o no cujo valor chave eh o
* menor da arvore dada ou NULL caso a arvore seja vazia.
* i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
tal que (*x)->chave eh o menor valor chave de toda a arvore dada
*/


NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz)
{
	if(*raiz == NULL)
		return NULL;
	if((*raiz)->esq == NULL)
		return raiz;
	else
		return buscaEnderecoDoPonteiroDoMenor(&((*raiz)->esq));
} /*1*/


/*
* 2) devolve o endereco do ponteiro para o no cujo valor chave eh o
* maior da arvore dada ou NULL caso a arvore seja vazia.
* i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
* tal que (*x)->chave eh o maior valor chave de toda a arvore dada
* O parametro de entrada raiz eh o endereco do ponteiro para o raiz
* da arvore.*/

NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz)
{
	if (*raiz == NULL)
		return NULL;
	if((*raiz)->dir == NULL)
		return raiz;
	else
		return buscaEnderecoDoPonteiroDoMaior(&((*raiz)->dir));
} /*2*/

/*
* Assume que *folha aponta para um no folha
* de uma arvore binaria de pesquisa qualquer.
* O procedimento deve remover tal no.
*/
void removeFolha(NoArvBinaria **folha)
{
	// no folhar aponta pra NULL campo esq e dir
	if( (*folha)->dir == NULL && (*folha)->esq == NULL)
	  free(*folha);
	   *folha == NULL;	

	   return 0;
	}
/*
* Assume que *raiz != NULL
* O no armazenado no endereco *raiz TEM NECESSARIAMENTE
* UM FILHO ARMAZENADO EM (*raiz)->esq OU (exclusivo) (*raiz)->dir.
* O procedimento deve remover o no armazenado em *raiz e
* fazer com que *raiz passe a apontar pelo filho do no a
* ser removido
*/
void removeNoComSomenteUmFilho(NoArvBinaria **raiz)
{
	NoArvBinaria *filho;
	NoArvBinaria  **aux;

	if(raiz == NULL)
		return NULL	

	if( ((*raiz)->dir == NULL) != ((*raiz)->esq == NULL) )

		filho = ((*aux)->esq) == NULL ? (*aux)->dir : (*aux)->esq;
		free(*aux);

		aux = filho;



return 0;
}



NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k)
{
	if(*raiz == NULL)
		*raiz = (NoArvBinaria)malloc(sizeof(NoArvBinaria));
		 *raiz->esq = NULL;
		 *raiz->dir = NULL;
		 *raiz->chave = k;

	if (k < raiz->chave)
		return insereArvBinRec(&((*raiz)->esq), k);
	else if (k > raiz ->chave)
		return insereArvBinRec(&((*raiz->dir), k);
	else
		return raiz;		

	
}















