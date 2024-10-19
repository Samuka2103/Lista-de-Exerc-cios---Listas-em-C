#include <stdio.h>
#define MAX_PEDIDOS 100 

int pedidos[MAX_PEDIDOS];
int inicio = 0; 
int fim = 0; 

void adicionar_pedido(int novo_pedido) {
    if (fim < MAX_PEDIDOS) {
        pedidos[fim] = novo_pedido;
        fim++;
        printf("Pedido %d adicionado à fila.\n", novo_pedido);
    } else {
        printf("A fila de pedidos está cheia!\n");
    }
}

void exibir_pedidos() {
    if (inicio < fim) {
        printf("Pedidos na fila:\n");
        for (int i = inicio; i < fim; i++) {
            printf("%d. Pedido %d\n", i - inicio + 1, pedidos[i]);
        }
    } else {
        printf("Não há pedidos na fila.\n");
    }
}

void remover_pedido() {
    if (inicio < fim) {
        printf("Pedido %d removido da fila.\n", pedidos[inicio]);
        inicio++;
    } else {
        printf("Não há pedidos para serem removidos.\n");
    }
}

int main() {
    int opcao, pedido;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar pedido\n");
        printf("2. Exibir pedidos\n");
        printf("3. Remover pedido\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número do pedido: ");
                scanf("%d", &pedido);
                adicionar_pedido(pedido);
                break;
            case 2:
                exibir_pedidos();
                break;
            case 3:
                remover_pedido();
                break;
            case 4:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}