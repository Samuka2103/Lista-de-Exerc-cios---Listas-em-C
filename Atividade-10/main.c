#include <stdio.h>
#include <stdlib.h>

typedef struct encomenda {
    char destinatario[50];
    int distancia; 
    struct encomenda *proximo;
} Encomenda;

Encomenda *nova_encomenda(char destinatario[50], int distancia) {
    Encomenda *novo = (Encomenda *)malloc(sizeof(Encomenda));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo->destinatario, destinatario);
    novo->distancia = distancia;
    novo->proximo = NULL;
    return novo;
}


void inserir_encomenda(Encomenda **cabeca, char destinatario[50], int distancia) {
    Encomenda *novo = nova_encomenda(destinatario, distancia);
    Encomenda *atual = *cabeca;
    Encomenda *anterior = NULL;

    while (atual != NULL && distancia > atual->distancia) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;
    if (anterior == NULL) {
        *cabeca = novo;
    } else {
        anterior->proximo = novo;
    }
}

void exibir_encomendas(Encomenda *cabeca) {
    if (cabeca == NULL) {
        printf("Não há encomendas para entrega.\n");
        return;
    }
    printf("Encomendas:\n");
    Encomenda *atual = cabeca;
    while (atual != NULL) {
        printf("Destinatário: %s (Distância: %d km)\n", atual->destinatario, atual->distancia);
        atual = atual->proximo;
    }
}

void remover_encomenda(Encomenda **cabeca, char destinatario[50]) {
    Encomenda *atual = *cabeca;
    Encomenda *anterior = NULL;

    while (atual != NULL && strcmp(atual->destinatario, destinatario) != 0) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            *cabeca = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        printf("Encomenda para %s removida.\n", destinatario);
    } else {
        printf("Encomenda para %s não encontrada.\n", destinatario);
    }
}

int main() {
    Encomenda *inicio_encomendas = NULL;
    int opcao, distancia;
    char destinatario[50];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir encomenda\n");
        printf("2. Exibir encomendas\n");
        printf("3. Remover encomenda\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do destinatário: ");
                scanf(" %[^\n]", destinatario); 
                printf("Digite a distância (km): ");
                scanf("%d", &distancia);
                inserir_encomenda(&inicio_encomendas, destinatario, distancia);
                break;
            case 2:
                exibir_encomendas(inicio_encomendas);
                break;
            case 3:
                printf("Digite o nome do destinatário da encomenda a ser removida: ");
                scanf(" %[^\n]", destinatario); 
                remover_encomenda(&inicio_encomendas, destinatario);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    Encomenda *atual = inicio_encomendas;
    while (atual != NULL) {
        Encomenda *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}