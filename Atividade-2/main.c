#include <stdio.h>
#include <stdlib.h>


typedef struct compromisso {
    int hora;
    int minuto;
    struct compromisso *proximo;
} Compromisso;


Compromisso *novo_compromisso(int hora, int minuto) {
    Compromisso *novo = (Compromisso *)malloc(sizeof(Compromisso));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->hora = hora;
    novo->minuto = minuto;
    novo->proximo = NULL;
    return novo;
}

void inserir_compromisso(Compromisso **cabeca, int hora, int minuto) {
    Compromisso *novo = novo_compromisso(hora, minuto);
    Compromisso *atual = *cabeca;
    Compromisso *anterior = NULL;

    while (atual != NULL && (hora > atual->hora || (hora == atual->hora && minuto >= atual->minuto))) {
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


void exibir_compromissos(Compromisso *cabeca) {
    if (cabeca == NULL) {
        printf("Não há compromissos na agenda.\n");
        return;
    }
    printf("Compromissos:\n");
    Compromisso *atual = cabeca;
    while (atual != NULL) {
        printf("%02d:%02d\n", atual->hora, atual->minuto);
        atual = atual->proximo;
    }
}

void remover_compromisso(Compromisso **cabeca, int hora, int minuto) {
    Compromisso *atual = *cabeca;
    Compromisso *anterior = NULL;

    while (atual != NULL && (hora != atual->hora || minuto != atual->minuto)) {
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
        printf("Compromisso %02d:%02d removido.\n", hora, minuto);
    } else {
        printf("Compromisso não encontrado.\n");
    }
}
int main() {
    Compromisso *cabeca = NULL;
    int opcao, hora, minuto;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir compromisso\n");
        printf("2. Exibir compromissos\n");
        printf("3. Remover compromisso\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a hora do compromisso (HH): ");
                scanf("%d", &hora);
                printf("Digite o minuto do compromisso (MM): ");
                scanf("%d", &minuto);
                inserir_compromisso(&cabeca, hora, minuto);
                break;
            case 2:
                exibir_compromissos(cabeca);
                break;
            case 3:
                printf("Digite a hora do compromisso a ser removido (HH): ");
                scanf("%d", &hora);
                printf("Digite o minuto do compromisso a ser removido (MM): ");
                scanf("%d", &minuto);
                remover_compromisso(&cabeca, hora, minuto);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

 
    Compromisso *atual = cabeca;
    while (atual != NULL) {
        Compromisso *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}