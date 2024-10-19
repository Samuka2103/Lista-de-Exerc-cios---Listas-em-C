#include <stdio.h>
#include <stdlib.h>

#define MAX_VISITANTES 100

typedef struct visitante {
    char nome[50];
    struct visitante *proximo;
} Visitante;

Visitante *novo_visitante(char nome[50]) {
    Visitante *novo = (Visitante *)malloc(sizeof(Visitante));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->proximo = NULL;
    return novo;
}

void inserir_visitante(Visitante **inicio, char nome[50]) {
    Visitante *novo = novo_visitante(nome);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        Visitante *atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    printf("Visitante %s adicionado à fila.\n", nome);
}

void remover_visitante(Visitante **inicio) {
    if (*inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    Visitante *removido = *inicio;
    *inicio = removido->proximo;
    printf("Visitante %s removido da fila.\n", removido->nome);
    free(removido);
}

void exibir_fila(Visitante *inicio) {
    if (inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Visitantes na fila:\n");
    Visitante *atual = inicio;
    while (atual != NULL) {
        printf("- %s\n", atual->nome);
        atual = atual->proximo;
    }
}

int main() {
    Visitante *inicio_fila = NULL;
    int opcao;
    char nome[50];

    do {
        printf("\nMenu:\n");
        printf("1. Inserir visitante na fila\n");
        printf("2. Remover visitante da fila\n");
        printf("3. Exibir fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do visitante: ");
                scanf("%s", nome);
                inserir_visitante(&inicio_fila, nome);
                break;
            case 2:
                remover_visitante(&inicio_fila);
                break;
            case 3:
                exibir_fila(inicio_fila);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    Visitante *atual = inicio_fila;
    while (atual != NULL) {
        Visitante *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}