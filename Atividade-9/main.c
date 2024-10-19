#include <stdio.h>
#include <stdlib.h>

typedef struct pontuacao {
    int jogador;
    int pontuacao;
    struct pontuacao *proximo;
} Pontuacao;

Pontuacao *nova_pontuacao(int jogador, int pontuacao) {
    Pontuacao *novo = (Pontuacao *)malloc(sizeof(Pontuacao));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->jogador = jogador;
    novo->pontuacao = pontuacao;
    novo->proximo = NULL;
    return novo;
}

void inserir_pontuacao(Pontuacao **cabeca, int jogador, int pontuacao) {
    Pontuacao *novo = nova_pontuacao(jogador, pontuacao);
    Pontuacao *atual = *cabeca;
    Pontuacao *anterior = NULL;

    while (atual != NULL && pontuacao > atual->pontuacao) {
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

void exibir_pontuacoes(Pontuacao *cabeca) {
    if (cabeca == NULL) {
        printf("Não há pontuações registradas.\n");
        return;
    }
    printf("Pontuações:\n");
    Pontuacao *atual = cabeca;
    while (atual != NULL) {
        printf("Jogador %d: %d pontos\n", atual->jogador, atual->pontuacao);
        atual = atual->proximo;
    }
}

void remover_pontuacao(Pontuacao **cabeca, int jogador) {
    Pontuacao *atual = *cabeca;
    Pontuacao *anterior = NULL;

    while (atual != NULL && jogador != atual->jogador) {
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
        printf("Pontuação do jogador %d removida.\n", jogador);
    } else {
        printf("Pontuação do jogador %d não encontrada.\n", jogador);
    }
}

int main() {
    Pontuacao *cabeca = NULL;
    int opcao, jogador, pontuacao;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir pontuação\n");
        printf("2. Exibir pontuações\n");
        printf("3. Remover pontuação\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número do jogador: ");
                scanf("%d", &jogador);
                printf("Digite a pontuação do jogador: ");
                scanf("%d", &pontuacao);
                inserir_pontuacao(&cabeca, jogador, pontuacao);
                break;
            case 2:
                exibir_pontuacoes(cabeca);
                break;
            case 3:
                printf("Digite o número do jogador a ser removido: ");
                scanf("%d", &jogador);
                remover_pontuacao(&cabeca, jogador);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    Pontuacao *atual = cabeca;
    while (atual != NULL) {
        Pontuacao *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}