#include <stdio.h>
#include <stdlib.h>

typedef struct produto {
    float preco;
    struct produto *proximo;
} Produto;

Produto *novo_produto(float preco) {
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->preco = preco;
    novo->proximo = NULL;
    return novo;
}

void inserir_produto(Produto **cabeca, float preco) {
    Produto *novo = novo_produto(preco);
    Produto *atual = *cabeca;
    Produto *anterior = NULL;

    while (atual != NULL && preco > atual->preco) {
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

void exibir_produtos(Produto *cabeca) {
    if (cabeca == NULL) {
        printf("Não há produtos disponíveis.\n");
        return;
    }
    printf("Preços dos produtos:\n");
    Produto *atual = cabeca;
    while (atual != NULL) {
        printf("R$ %.2f\n", atual->preco);
        atual = atual->proximo;
    }
}

void remover_produto(Produto **cabeca, float preco) {
    Produto *atual = *cabeca;
    Produto *anterior = NULL;

    while (atual != NULL && preco != atual->preco) {
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
        printf("Produto com preço R$ %.2f removido.\n", preco);
    } else {
        printf("Produto não encontrado.\n");
    }
}

int main() {
    Produto *cabeca = NULL;
    int opcao;
    float preco;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Remover produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o preço do produto: R$ ");
                scanf("%f", &preco);
                inserir_produto(&cabeca, preco);
                break;
            case 2:
                exibir_produtos(cabeca);
                break;
            case 3:
                printf("Digite o preço do produto a ser removido: R$ ");
                scanf("%f", &preco);
                remover_produto(&cabeca, preco);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    Produto *atual = cabeca;
    while (atual != NULL) {
        Produto *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}