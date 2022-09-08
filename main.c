#include <stdio.h>
#include <stdlib.h>

struct Node{
    char index;
    float importacao;
    float exportacao;
    int anoInicio;
    struct Node *prox;
};
typedef struct Node Node;

//********************************************

void verificarRelacao(int V, Node *G[V]){
    printf("Digite o índice da linha (pais): ");
    int l = scanf("%d",&l);
    printf("Digite o índice da coluna (pais relacionado): ");
    int c = scanf("%d",&c);
    
    if(G[l][c] == NULL){
        printf("Não existe relacao entre os paises digitados!\n");
    }else{
        printf("A relacao existe:\n");
        printf("1-Valor Importacao = %f.\n",G[l][c]->importacao);
        printf("2-Valor Exportacao = %f.\n",G[l][c]->exportacao);
        printf("3-Inicio relacao ano = %d.\n",G[l][c]->anoInicio);
    }
};

void criarRelacao(int V, Node *G[V]){
    printf("Digite o índice do pais 1: ");
    int p1 = scanf("%d",&p1);
    printf("Digite o índice do pais 2: ");
    int p2 = scanf("%d",&p2);

    // cria a adjacência p2 para encadear em p1
    Node* novoP2 = malloc(sizeof(Node));
    novoP2->index = p2;
    novoP2->prox = NULL;

    // cria a adjacência p1 para encadear em p2
    Node* novoP1 = malloc(sizeof(Node));
    novoP1->index = p1;
    novoP1->prox = NULL;

    // Preenche os dados da relação
    printf("\nDigite os dados da relacao:");
    printf("\nImportacoes = ");
    scanf("%f",&novoP2->importacao);
    novoP1->importacao=novoP2->importacao;
    printf("Exportacoes = ");
    scanf("%f",&novoP2->exportacao);
    novoP1->exportacao=novoP2->exportacao;
    printf("Ano inicio relacao = ");
    scanf("%d",&novoP2->anoInicio);
    novoP1->anoInicio=novoP2->anoInicio;
    
    /* INSERÇÃO DE P2 COMO ADJACÊNCIA DE P1 ------------------ */
    // verifica se as adjacências de p1 estão vazias (vértice sem ligação)
    if(G[p1]==NULL){
        G[p1] = novoP2;
    }

    Node* pont = G[p1]; // cria um apontador para as adjacências de p1
    while (pont!=NULL){
        pont = pont->prox;
    }

    /* INSERÇÃO DE P1 COMO ADJACÊNCIA DE P2 ------------------ */
}

void removerRelacao(int V, Node *G[V]){
    printf("Digite o índice da linha (pais): ");
    int l = scanf("%d",&l);
    printf("Digite o índice da coluna (pais relacionado): ");
    int c = scanf("%d",&c);
    free(G[l][c]);
}

//********************************************

int main(){
    // quantidade de vértices
    printf("Digite a quantidade de paises desejados: ");
    int V;
    scanf("%d",&V);
    // criação da matriz de adjacência
    Node *G[V];
    buildMatriz(V,G); // inicialização da matriz de adjacência

    int opt=1;
    do{
        printf("Escolha uma das opções abaixo:\n");
        printf("1 - Sair\n");
        printf("2 - Verificar relação\n");
        printf("3 - Criar relação\n");
        printf("4 - Remover relação\n");
        scanf("%d",&opt);
        if(opt==2){
            verificarRelacao(V,G);
        }else if(opt==3){
            criarRelacao(V,G);
        }else if(opt==4){
            removerRelacao(V,G);
        }
    }while(opt!=1);
    
    return 0;
}

