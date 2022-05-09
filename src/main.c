#include "aula.h"

int main(){
	Lista l;
	char arquivo[80];
	int opcao;
	FLVazia(&l);
	printf("Qual o nome do arquivo da lista dos numeros? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
	preencheLista(&l,arquivo);
	do
	{
		printf("O que deseja fazer?\n\t1-Buscar Maior Soma\n\t2-Imprimir lista\n\t0-Sair\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			maiorSoma(&l);
			break;
		case 2:
			printLista(&l);
			break;
		// case 3:
		// 	printPos(&maxSumPos, cont);
		// 	break;
		case 0:
			printf("Saindo\n");
			break;
		default:
			break;
		}
	}while (opcao!=0);
	return 0;
}
