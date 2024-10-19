#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVROS 100

int livros[MAX_LIVROS]; 
int num_livros = 0;

void adicionar_livro(int codigo) {
    if (num_livros < MAX_LIVROS) {
        livros[num_livros] = codigo;
        num_livros++;
        printf("Livro com código %d adicionado ao acervo.\n", codigo);
    } else {
        printf("Limite de livros no acervo atingido.\n");
    }
}
void exibir_livros() {
    if (num_livros == 0) {
        printf("Não há livros no acervo.\n");
    } else {
        printf("Livros disponíveis:\n");
        for (int i = 0; i < num_livros; i++) {
            printf("Código: %d\n", livros[i]);
        }
    }
}
void remover_livro(int codigo) {
    int encontrado = 0;
    for (int i = 0; i < num_livros; i++) {
        if (livros[i] == codigo) {
            encontrado = 1;

            for (int j = i; j < num_livros - 1; j++) {
                livros[j] = livros[j + 1];
            }
            num_livros--;

            printf("Livro com código %d removido do acervo.\n", codigo);
            break;
        }
    }
    if (!encontrado) {
        printf("Livro com código %d não encontrado no acervo.\n", codigo);
    }
}
int main() {
    int opcao, codigo;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar livro\n");
        printf("2. Exibir livros\n");
        printf("3. Remover livro\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o código do livro: ");
                scanf("%d", &codigo);
                adicionar_livro(codigo);
                break;
            case 2:
                exibir_livros();
                break;
            case 3:
                printf("Digite o código do livro a ser removido: ");
                scanf("%d", &codigo);
                remover_livro(codigo);
                break;
            case 4:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}