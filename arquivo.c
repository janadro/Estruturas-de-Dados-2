#include "arquivo.h"

// Autor Leandro Chesini
void *criarIndice(char nomeArq[], char modoArq[], avl** rAVL, redblack **rRBT) {
	FILE *arq = fopen(nomeArq, modoArq);
	if(arq == NULL)
		return NULL;
	printf("Arquivo %s aberto...\n", nomeArq);

	registro leitura[QTD_REG];
	unsigned long int i = 0;
	int j, n;
	j = n = 0;

	printf("Criar indice em RAM...\n");
	while(!feof(arq)){
		n = fread(&leitura, sizeof(registro), QTD_REG, arq);

		if(n > 0){
			for (j = 0; j < n; j++){
				insereAVL(rAVL, leitura[j].naochave, i, j);
				*rRBT = insereRedBlack(*rRBT, leitura[j].naochave, i, j);

			}
			i++;
		}
	}
	fclose(arq);

	return *rAVL;
}

// Autora: Jaine Rodrigues
void acessarRegistros(char nomeArq[], char modoArq[], noLista **head) {
	if(*head == NULL){
		printf("Registro nao existe.\n");
		return;
	}

	FILE *arq = fopen(nomeArq, modoArq);
	if(arq == NULL)
		return;


	registro leitura[QTD_REG];
	unsigned long int i = 0;
	int j, n;
	j = n = 0;


	while(*head != NULL){
		fseek(arq, ((*head)->bloco * sizeof(registro) * QTD_REG), SEEK_SET);
		n = fread(&leitura, sizeof(registro), QTD_REG, arq);

		if(n > 0){
			for(j = 0; j < n; j++){
				if (leitura[j].naochave == (*head)->naochave){
					printf("_\nRegistro chave: %lu\n", leitura[j].chave);
					printf("naochave: %lu\n", leitura[j].naochave);
/*					printf("outros: %s\n", leitura[j].outros);
*/					printf("Em %s: bloco %lu, registro %u\n", nomeArq, (*head)->bloco, j);

				}
			}
			
		}
		*head = (*head)->prox;
	}
	fclose(arq);

}
