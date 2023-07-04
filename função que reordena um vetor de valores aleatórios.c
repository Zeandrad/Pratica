#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int vetor[], int tamanho) {
    int i, j, menor, aux;
    
    for (i = 0; i < tamanho - 1; i++) {
        menor = i;
        
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        
        // Troca o menor elemento com o primeiro elemento do subvetor
        aux = vetor[i];
        vetor[i] = vetor[menor];
        vetor[menor] = aux;
    }
}

int main() {
    int tamanho, i;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int vetor[tamanho];
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    
    // Preenche o vetor com números aleatórios
    for (i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100; // Números aleatórios entre 0 e 99
    }
    
    printf("Vetor original: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    // Chama a função de classificação por seleção
    selectionSort(vetor, tamanho);
    
    printf("Vetor ordenado: ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    return 0;
}