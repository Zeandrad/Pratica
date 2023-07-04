#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char nome[50];
    int quantidade;
    struct Item* proximo;
} Item;

Item* criarItem(const char* nome, int quantidade) {
    Item* novoItem = (Item*)malloc(sizeof(Item));
    strcpy(novoItem->nome, nome);
    novoItem->quantidade = quantidade;
    novoItem->proximo = NULL;
    return novoItem;
}

void adicionarItem(Item** lista, const char* nome, int quantidade) {
    Item* novoItem = criarItem(nome, quantidade);
    
    if (*lista == NULL) {
        *lista = novoItem;
    } else {
        Item* atual = *lista;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }
    
    printf("Item adicionado com sucesso!\n");
}

void removerItem(Item** lista, const char* nome) {
    if (*lista == NULL) {
        printf("A lista de compras está vazia.\n");
        return;
    }
    
    Item* atual = *lista;
    Item* anterior = NULL;
    
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Item removido com sucesso!\n");
            return;
        }
        
        anterior = atual;
        atual = atual->proximo;
    }
    
    printf("O item '%s' não foi encontrado na lista de compras.\n", nome);
}

void consultarItem(Item* lista, const char* nome) {
    Item* atual = lista;
    
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Item: %s\nQuantidade: %d\n", atual->nome, atual->quantidade);
            return;
        }
        
        atual = atual->proximo;
    }
    
    printf("O item '%s' não foi encontrado na lista de compras.\n", nome);
}

void mostrarLista(Item* lista) {
    if (lista == NULL) {
        printf("A lista de compras está vazia.\n");
        return;
    }
    
    printf("Lista de compras:\n");
    Item* atual = lista;
    
    while (atual != NULL) {
        printf("Item: %s\nQuantidade: %d\n\n", atual->nome, atual->quantidade);
        atual = atual->proximo;
    }
}

void liberarLista(Item** lista) {
    Item* atual = *lista;
    
    while (atual != NULL) {
        Item* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    
    *lista = NULL;
    printf("Lista de compras liberada.\n");
}

int main() {
    Item* listaCompras = NULL;
    int opcao, quantidade;
    char nome[50];
    
    do {
        printf("=== Lista de Compras ===\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Consultar item\n");
        printf("4. Mostrar lista\n");
        printf("5. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                scanf("%s", nome);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                adicionarItem(&listaCompras, nome, quantidade);
                printf("\n");
                break;
            case 2:
                printf("Digite o nome do item: ");
                scanf("%s", nome);
                removerItem(&listaCompras, nome);
                printf("\n");
                break;
            case 3:
                printf("Digite o nome do item: ");
                scanf("%s", nome);
                consultarItem(listaCompras, nome);
                printf("\n");
                break;
            case 4:
                mostrarLista(listaCompras);
                printf("\n");
                break;
            case 5:
                liberarLista(&listaCompras);
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                printf("\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}