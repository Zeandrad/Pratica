#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    char nome[50];
    struct Paciente* proximo;
} Paciente;

typedef struct Atendimento {
    Paciente* inicio;
    Paciente* fim;
} Atendimento;

Atendimento* criarAtendimento() {
    Atendimento* novoAtendimento = (Atendimento*)malloc(sizeof(Atendimento));
    novoAtendimento->inicio = NULL;
    novoAtendimento->fim = NULL;
    return novoAtendimento;
}

void adicionar_paciente(Atendimento* atendimento, const char* nome) {
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    strcpy(novoPaciente->nome, nome);
    novoPaciente->proximo = NULL;

    if (atendimento->fim == NULL) {
        atendimento->inicio = novoPaciente;
        atendimento->fim = novoPaciente;
    } else {
        atendimento->fim->proximo = novoPaciente;
        atendimento->fim = novoPaciente;
    }

    printf("Paciente %s adicionado ao atendimento.\n", nome);
}

void proximo_paciente(Atendimento* atendimento) {
    if (atendimento->inicio == NULL) {
        printf("Não há pacientes na fila.\n");
        return;
    }

    Paciente* proximo = atendimento->inicio;
    atendimento->inicio = proximo->proximo;

    if (atendimento->inicio == NULL) {
        atendimento->fim = NULL;
    }

    printf("Próximo paciente a ser atendido: %s\n", proximo->nome);
    free(proximo);
}

int quantidade_pacientes(Atendimento* atendimento) {
    int count = 0;
    Paciente* atual = atendimento->inicio;

    while (atual != NULL) {
        count++;
        atual = atual->proximo;
    }

    return count;
}

int main() {
    Atendimento* atendimento = criarAtendimento();
    int opcao;
    char nome[50];

    do {
        printf("=== Sistema de Gerenciamento de Atendimento ===\n");
        printf("1. Adicionar paciente\n");
        printf("2. Próximo paciente\n");
        printf("3. Quantidade de pacientes\n");
        printf("4. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Digite o nome do paciente: ");
                scanf("%s", nome);
                adicionar_paciente(atendimento, nome);
                printf("\n");
                break;
            case 2:
                proximo_paciente(atendimento);
                printf("\n");
                break;
            case 3:
                printf("Quantidade de pacientes na fila: %d\n", quantidade_pacientes(atendimento));
                printf("\n");
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                printf("\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}