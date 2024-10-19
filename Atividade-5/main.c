#include <stdio.h>
#define Tamanho_fila_paciente 100 

int fila_pacientes[Tamanho_fila_paciente]; 
int inicio = 0; 
int fim = 0;  

void adicionar_paciente(int id_paciente) {
    if (fim < Tamanho_fila_paciente) {
      
        fila_pacientes[fim] = id_paciente;
        fim++;
        printf("Paciente %d foi adicionado à fila.\n", id_paciente);
    } else {
        printf("A fila está cheia! Não é possível adicionar mais pacientes.\n");
    }
}

void remover_paciente () {
  if (inicio < fim) {
    printf("Paciente %d foi atendido e removido da fila.\n", fila_pacientes[inicio]);
    inicio++;
  } else {
    printf("Não há pacientes na fila para serem atendidos.\n");
  }
}

void exibir_paciente () {
  if (inicio < fim) {
    printf("Pacientes aguardando atendimento:\n");
    for (int i = inicio; i < fim; i++) {
        printf("%d. Paciente %d\n", i - inicio + 1, fila_pacientes[i]);
    }
  } else {
    printf("Não há pacientes aguardando atendimento.\n");
  }
}

int main(void) {
 
      int opcao,id_paciente;

      do {
          printf("\n1. Adicionar paciente à fila\n");
          printf("2. Atender paciente\n");
          printf("3. Exibir lista de pacientes\n");
          printf("4. Sair\n");
          printf("Escolha uma opção: ");
          scanf("%d", &opcao);

          switch(opcao) {
              case 1:
                  printf("Digite o ID do paciente: ");
                  scanf("%d", &id_paciente);
                  adicionar_paciente(id_paciente);
                  break;
              case 2:
                  remover_paciente();
                  break;
              case 3:
                  exibir_paciente();
                  break;
              case 4:
                  printf("Encerrando o programa.\n");
                  break;
              default:
                  printf("Opção inválida! Tente novamente.\n");
          }
      } while (opcao != 4);

      return 0;
  }