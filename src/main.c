#include "aula.h"

int main(){
	Lista l;
	int opcao;
	FLVazia(&l);
	preencheLista(&l);
	do
	{
		printf("O que deseja fazer?\n\t1-Buscar Maior Soma\n\t2-Imprimir lista\n\t3-Busca Novo Arquivo\n\t0-Sair\n");
		scanf("%d",&opcao);
		switch (opcao)
		{
		case 1:
			maiorSoma(&l);
			break;
		case 2:
			printLista(&l);
			break;
		case 3:
			FLVazia(&l);
			preencheLista(&l);
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
