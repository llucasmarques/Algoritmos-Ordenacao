/*
 * Ordenação por inserção(insert sort)
 * Neste metodo a medida que os valores sao inseridos, devem ocupar uma posição
que garanta a ordenação da lista.
Ex:
    vetor desordenado: [7,3,8,2,1,9]
    
    Passo 1: Inserção do 7
        vetor ordenado: [7,   ]
    Passo 2: Inserção do 3
            vetor ordenado: [3,7,...]
    Passo 3: Inserção do 8
                [3,7,8....]
    Passo 4: Inserção 2: 
                [2,3,7,8...]
    Passo 5: inserção 1
            [1,2,3,7,8...]
    Passo 6, inserção do 9
            [1,2,3,7,8,9]
*/

#define MAX 10

//estrutura com esses valores
struct vetor{
    int dado[MAX];
    int qtd;
    
};
typedef struct vetor tipoVetor;

//prototipo da função
void insere_inicio(tipoVetor *vet, int valor);
void insere_fim(tipoVetor *vet, int valor);
int ordencao(tipoVetor *vet);
void imprime_lista(tipoVetor vet);



#include <stdio.h>
#include <stdlib.h>

//Função principal
int main(){
    tipoVetor vet;
    vet.qtd = 0;
    
    //chamadas das funções, assim fazendo as inserçoes no inicio desse vetor
    insere_inicio(&vet, 5); //insere o valor 5 no início da lista
    insere_inicio(&vet, 1);
    insere_inicio(&vet, 3);
	
    insere_fim(&vet, 8);
    insere_fim(&vet, 2);
    
    printf("Vetor antes da ordenção: \n");
    imprime_lista(vet);
    printf("\n\n");
    
    printf("Vetor depois da ordenção: \n");
    ordencao(&vet);
    imprime_lista(vet);
    printf("\n\n");
    
    return 1;
}


/** Implementação da função de inserção no início */
void insere_inicio(tipoVetor *vet, int valor) {
	int i;
	//Verifica se ha espaço na lista
	if (vet->qtd < MAX) {
		//Reposiciona os valores da lista (uma posição à frente)
		for ( i = vet->qtd; i > 0; i-- ) {
			vet->dado[i] = vet->dado[i-1];
		}
		vet->dado[0] = valor;
		vet->qtd++;
	}
}

/** Implementação da função de inserção no fim da lista */
void insere_fim(tipoVetor *vet, int valor) {
	//Verifica se a lista tem espaço disponível
	if (vet->qtd < MAX)
		vet->dado[vet->qtd++] = valor;//depois da verificacao, insere na ultima posicao
}


//Função que realiza a ordenação 
int ordencao(tipoVetor *vet){
    int i,j,temporaria;
    temporaria = 0;
    //printf("Entrou!\n");
    for(i=1; i < vet->qtd;i++){
            j = i;
            /* comparação da posicao da frente com a posição anterior,se for menor ele troca*/
            while(vet->dado[j]  < vet->dado[j-1] && j > 0){
                //recebe o valor da posicao anterior
                temporaria = vet->dado[j-1];
                vet->dado[j-1] = vet->dado[j];/*a posicao anterior, recebe da posição posterior que eh menor*/
                vet->dado[j] = temporaria;//agora a posicao da frente recebe o valor maior que tem
                
                j--;//decrementação
            }
           
        }
        
}

/** Função que imprime a lista */
void imprime_lista(tipoVetor vet) {
	int i;
	printf("Qtd de elementos: %d\t", vet.qtd);
	for (i = 0; i < vet.qtd; i++ ){
		printf("[%d]", vet.dado[i]);
	
        }
        printf("\n\n");
}