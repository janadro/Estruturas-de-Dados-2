#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include "arquivo.h"


int main() {

	char nomeArq[] = "base.bin";
	char modoArq[] = "rb";
	int menu = -1;
	int i = 0;
	unsigned long int chaveBusca = 0;

	clock_t Ticks[2];
    double Tempo = 0.0;
    
	avl* arvore_avl = NULL;
	redblack* arvore_rb = NULL;
	noLista* noBusca = NULL;

	if(!criarIndice(nomeArq, modoArq, &arvore_avl, &arvore_rb))
		return 1;

	do{
		system("clear");
		printf("Busca em memoria externa\n");
		printf("Arquivo aberto: %s\n", nomeArq);
		printf("Tamanho do registro (em bytes): %ld\n", sizeof(registro));
		printf("Indice criado em RAM com as estruturas de dados abaixo\n");
		printf("Escolha a estrutura de dados para realizar uma busca\n");
		printf("	1 - Red-Black Tree\n");
		printf("	2 - AVL\n");
		printf("	3 - Ambas (comparacao)\n");
		printf("   -1 - Encerrar\n");
		printf("Digite uma opcao: ");
		scanf("%d", &menu);
		if(menu == -1)
			break;

		printf("Digite um valor naochave para realizar a busca: ");
		scanf("%lu", &chaveBusca);

		switch(menu){

			case 1:
				Ticks[0] = clock();
				noBusca = buscaRedBlack(arvore_rb, chaveBusca);
				Ticks[1] = clock();
		    	Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
				printf("\n\nBusca na Red-Black. Tempo gasto: %g ms.\n", Tempo);
				acessarRegistros(nomeArq, modoArq, &noBusca);

			break;

			case 2:
				Ticks[0] = clock();
				noBusca = buscaAVL(arvore_avl, chaveBusca);
				Ticks[1] = clock();
		    	Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
				printf("\n\nBusca na AVL. Tempo gasto: %g ms.\n", Tempo);
		    	acessarRegistros(nomeArq, modoArq, &noBusca);

			break;

			case 3:
				Ticks[0] = clock();
				noBusca = buscaAVL(arvore_avl, chaveBusca);
				Ticks[1] = clock();
		    	Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
				printf("\n\nBusca na AVL. Tempo gasto: %g ms.\n", Tempo);
		    	acessarRegistros(nomeArq, modoArq, &noBusca);

				Ticks[0] = clock();
				noBusca = buscaRedBlack(arvore_rb, chaveBusca);
				Ticks[1] = clock();
		    	Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
				printf("\n\nBusca na Red-Black. Tempo gasto: %g ms.\n", Tempo);
				acessarRegistros(nomeArq, modoArq, &noBusca);


			break;

			default:
			break;
		}

		printf("Encerrar (-1) / continuar (0)? ");
		scanf("%d", &menu);

	}while(menu != -1);

	return 0;
}
