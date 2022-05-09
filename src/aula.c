#include "aula.h"
void FLVazia(Lista *l){
    // diz que a cabeça da lista é um espaço de memória que armazena um BLOCO
    l->cabeca=(Bloco*)malloc(sizeof(Bloco));
    // diz que o ultimo termo da lista é o primeiro
    l->cauda=l->cabeca;
    // diz que o proximo item depois do ultimo é nulo
    l->cauda->prox=NULL;
}
void preencheLista(Lista *l){
	char arquivo[80];
	fgets(arquivo,80,stdin);
	printf("Qual o nome do arquivo da lista dos numeros? (Max 80)\n");
	fgets(arquivo,80,stdin);
	arquivo[strlen(arquivo)-1]='\0';
    FILE *f;
    int item;
    Item aux;
    if(!(f=fopen(arquivo,"r"))){
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }
    while(!feof (f)){
        fscanf(f,"%d",&item);
        l->cauda->prox=(Bloco*)malloc(sizeof(Bloco));
        l->cauda=l->cauda->prox;
        aux.value=item;
        l->cauda->dado=aux;
        l->cauda->prox=NULL;
    }
    fclose(f);
}
void printLista(Lista *l){
    Bloco* aux;
    aux=l->cabeca;
    while (aux->prox!=NULL)
    {
        printf(" %d, ",aux->prox->dado.value);
        aux=aux->prox;
    }
    printf("\n");
}
void maiorSoma(Lista *l){
    Bloco *percorre, *percorreInterno;
    int soma=0,maxSum;
    //int cont=1,contmax=1;
    percorre=l->cabeca->prox;
    maxSum=percorre->dado.value;
    //maxSumPos=*percorre;
    while (percorre!=NULL){
        soma=percorre->dado.value;
        //cont=1;
        if (soma>maxSum){
            //maxSumPos=*percorre;
            //contmax=cont;
            maxSum=soma;
        }
        percorreInterno=percorre->prox;
        while (percorreInterno!=NULL)
        {
            soma+=percorreInterno->dado.value;
            if (soma>maxSum){
                //contmax+=cont;
                maxSum=soma;
            }
            //cont+=1;    
            percorreInterno=percorreInterno->prox;
        }
        percorre=percorre->prox;
    }
    printf("%d\n",maxSum);
    //return contmax;
}
// void printPos(Bloco *b,int cont){
//     Bloco* aux;
//     aux=b;
//     for (int i = 0; i < cont; i++)
//     {
//         printf("%d-",aux->dado.value);
//         aux=aux->prox;
//     }
//     printf("\n");
// }
//Comentários são tentativas de criar uma função para mostrar a posição dos componentes da máxima soma