# MÁXIMA SOMA
Em uma lista A temos um conjunto de elementos inteiros positivos ou não <a<sub>1</sub>; a<sub>2</sub>; ... ; a<sub>n</sub>>. Elabore uma função que consiga encontrar neste conjunto a máxima soma.
# Logica
Foi-se feito um programa com a seguinte lógica:    
Existe uma lista dinâmica **l** da maneira (Baseado de : [vide git](https://github.com/mpiress/dynamic_list)):
><p align="justify">
>A lista dinâmica é uma variante do modelo estático [vide git](https://github.com/mpiress/linear_list). Assim, antes de apresentar as modificações existêntes nessa implementação, vejamos uma representação gráfica do modelo dinâmico em questão. Observe as nomenclaturas utilizadas na figura, essas são utilizadas na implementação fornecida, as quais podem estar definidas/parametrizadas no idioma inglês.
></p>
><p align="center">
>	<img src="imgs/lista.png"/> 
></p>
><p align="justify">
>Note pela figura que, o primeiro bloco armazenado em RAM não apresenta o tipo dado como parte da estrutura, mas sim um valor 0 <b>"simbólico"</b>. Isso porque é >preciso inserir na estrutura o que chamaremos de cabeça da lista. A cabeça de uma lista nada mais é que um ponteiro <i>vazio</i> (i.e., um tipo similar ao void) que >indica qual posição de memória será utilizada como base/início da lista. 
></p>
><p align="justify">
>Uma outra nomenclatura a ser observada na figura é a existência de um ponteiro <b>prox</b>. Este tem por objetivo apontar para o próximo bloco de memória que conterá >o novo dado ou para NULL, o que facilita a navegação entre os blocos e a idenficação do fim da lista. Este ponteiro se mostra imprescindível, uma vez que abandonamos >o modelo sequencial de memória e adotamos um conceito cujos blocos estão em endereços aleatórios. Nesse novo modelo, inserções, remoções, pesquisas e impressões da >lista são apoiadas por dois outros ponteiros, o <b>primeiro</b> e o <b>último</b>, conforme representação da figura.
></p>
>Qual a função dos ponteiros <b>primeiro</b> e <b>ultimo</b>?
>
>Como a lista é composta de blocos espalhados na memória, torna-se necessário identificar qual bloco representa a cabeça da lista. Para isso, é utilizado o ponteiro primeiro. Da mesma forma, identificar o último bloco também se torna importante, uma vez que, novas inserções são realizadas sempre no final dessa estrutura com o objetivo de facilitar sua manipulação.
><p align="justify">
>Se considerarmos um computador hipotético com 8Mb de RAM distribuídos em dois pentes de 4Mb cada, uma representação da lista dinâmica poderia ser compreendida da seguinte forma:
></p>
><p align="center">
>	<img src="imgs/memoria.png"/> 
></p> 

1) Ao entrar no programa a primeira função encontrada é *FLVazia(&l)* (Baseado de : [vide git](https://github.com/mpiress/dynamic_list)):
>Função responsável por criar um espaço de memória para ser a cabeça da lista. Para tanto, é utilizado a chamada de função nativa do C/C++ malloc, o qual recebe como referência o espaço a ser reservado por meio da diretriz sizeof. Nesse primeiro momento, o casting (i.e., conversão de um tipo void criado pelo malloc para um tipo específico) se torna opcional, sendo utilizado na codificação apenas para manter um único padrão de definição de função. Como pode ser observado no código disponibilizado, o endereço produzido pela execução do malloc é copiado para o ponteiro primeiro e último, mantendo ambos no mesmo endereço. O que significará que a lista se encontra vazia. Por fim, apontamos o prox de ambos os ponteiros para NULL.    

2) A segunda função *preencheLista(&l)* tem o objetivo de preencher **l**, pegando o nome de um arquivo de formato;
>a<sub>1</sub><br>
>a<sub>2</sub><br>
>a<sub>3</sub><br>
>a<sub>...</sub><br>
>a<sub>n</sub><br>
>
>onde *a* é um inteiro

percorrendo o mesmo (caso válido, caso inválido da exit) e inserindo elementos na lista, a primeira ação a ser realizada é reservar espaço em memória para esse novo dado. Para isso, o apontador cauda deve apontar em memória para o endereço do novo bloco cujo prox apontará para NULL.

3) A seguir é apresentado um menu para o usuário com as seguintes opções:    
- Buscar Maior Soma:
    1. O programa seta uma ponteiro *percorre* igual ao primeiro elemento da lista (l->cabeca->prox), seta tamebém a máxima soma da lista como o valor desse elemento, entra-se então em um loop que irá igualar *percorre=percorre->prox* a cada iteração enquanto *percorre* não for nulo (uma maneira de percorre a lista), para compararmos cada soma de cada intervalo de posições, usamos uma variável *soma* temporária, e no começo do loop a igualamos ao valor de percorre e comparamos à máxima soma, caso seja maior, igualamos a máxima soma a *soma*, logo após setamos um ponteiro *percorreInterno=percorre->prox* e começamos um loop interno da mesma maneira do externo que soma o valor de *percorreInterno* à variável *soma* e a compara novamente à máxima soma, caso seja maior substitui o valor da máxima soma pela *soma*. Ao final dos loops a máxima soma é imprimida;    

- Imprimir lista:
    1. Imprime a lista de inteiros obtidos no arquivo;

- Busca Novo Arquivo:
    1. Repete *1)* e *2)* para pegar um valor de uma nova lista; 

- Sair:
    1. Sair do programa.

Obs.:    
- O arquivo deve ser dado na mesma maneira que o apresentado e deve conter apenas números inteiros
- Ao iniciar o programa deve-se entrar com alguma palavra que não será utilizada, isso é feito para que seja possível entrar com outro arquivo durante a execução do programa

# Compilação e Execução

O programa possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
