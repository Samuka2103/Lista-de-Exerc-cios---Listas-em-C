#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

int alunos[MAX_ALUNOS];
int num_alunos = 0; 

void inserir_aluno(int matricula) {
    if (num_alunos < MAX_ALUNOS) {
        alunos[num_alunos] = matricula;
        num_alunos++;
        printf("Aluno com matrícula %d cadastrado.\n", matricula);
    } else {
        printf("Limite de alunos atingido.\n");
    }
}

void exibir_alunos() {
    if (num_alunos == 0) {
        printf("Não há alunos cadastrados.\n");
    } else {
        printf("Alunos cadastrados:\n");
        for (int i = 0; i < num_alunos; i++) {
            printf("Matrícula: %d\n", alunos[i]);
        }
    }
}

int buscar_aluno(int matricula) {
    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i] == matricula) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int opcao, matricula;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir aluno\n");
        printf("2. Exibir alunos\n");
        printf("3. Buscar aluno\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número de matrícula: ");
                scanf("%d", &matricula);
                inserir_aluno(matricula);
                break;
            case 2:
                exibir_alunos();
                break;
            case 3:
                printf("Digite o número de matrícula a ser buscado: ");
                scanf("%d", &matricula);
                if (buscar_aluno(matricula)) {
                    printf("Aluno encontrado.\n");
                } else {
                    printf("Aluno não encontrado.\n");
                }
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