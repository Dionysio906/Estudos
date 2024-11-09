//Você recebe duas matrizes de inteiros nums1 e nums2, classificadas em ordem não decrescente, 
//e dois inteiros me n, representando o número de elementos em nums1 e nums2 respectivamente.
//Mesclar nums1 e nums2em uma única matriz classificada em ordem não decrescente .
//O array final ordenado não deve ser retornado pela função, mas sim armazenado dentro 
//do arraynums1 . Para acomodar isso, nums1tem um comprimento de m + n, onde os primeiros m 
//elementos denotam os elementos que devem ser mesclados, e os últimos n elementos são definidos 
//como 0 e devem ser ignorados. nums2tem um comprimento de n.
//exercicio 88 do leetcode

#include <stdio.h>
#include <stdlib.h>

// Função para mesclar duas sublistas ordenadas
void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;  // Ponteiro para o último elemento válido de nums1
    int j = n - 1;  // Ponteiro para o último elemento de nums2
    int k = m + n - 1;  // Ponteiro para o último elemento de nums1 (onde vamos preencher)

    // Mescla nums1 e nums2 começando do final de nums1
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];  // Coloca o maior elemento de nums1 no final
        } else {
            nums1[k--] = nums2[j--];  // Coloca o maior elemento de nums2 no final
        }
    }

    // Se ainda houver elementos em nums2, copiamos para nums1
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

// Função para ler dados de nums2 e ignorar os zeros
void read_nums2(int nums2[], int n, int* new_n) {
    *new_n = 0;  // Inicializa o contador de elementos válidos
    printf("Digite os %d elementos de nums2:\n", n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num != 0) {  // Ignora os zeros
            nums2[*new_n] = num;
            (*new_n)++;
        }
    }
}

// Função para comparar dois números (necessário para qsort)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int m, n;

    // Solicita ao usuário o número de elementos para o vetor nums1 e nums2
    printf("Digite o numero de elementos para nums1 (m): ");
    scanf("%d", &m);

    printf("Digite o numero de elementos para nums2 (n): ");
    scanf("%d", &n);

    // Aloca memória para os vetores com base no tamanho informado pelo usuário
    int* nums1 = (int*)malloc((m + n) * sizeof(int));  // Vetor nums1 com m+n elementos
    if (nums1 == NULL) {
        printf("Erro de alocação de memória para nums1.\n");
        return 1;  // Encerra o programa em caso de erro
    }
    
    int* nums2 = (int*)malloc(n * sizeof(int));  // Vetor nums2 com n elementos
    if (nums2 == NULL) {
        printf("Erro de alocação de memória para nums2.\n");
        free(nums1);  // Libera a memória de nums1
        return 1;  // Encerra o programa em caso de erro
    }

    // Solicita ao usuário os valores para o vetor nums1
    printf("Digite os %d elementos de nums1:\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Inicializa os últimos n elementos de nums1 com 0 (deve ser feito explicitamente)
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;  // Preenche com zeros a parte "vazia" de nums1
    }

    // Solicita ao usuário os valores para o vetor nums2
    int new_n;
    read_nums2(nums2, n, &new_n);  // Lê os valores de nums2 e ignora zeros

    // Exibe os vetores antes da mesclagem
    printf("Matriz 1 antes da mesclagem: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("Matriz 2 antes da mesclagem: ");
    for (int i = 0; i < new_n; i++) {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    // Chama a função de mesclagem (nums1 já tem espaço suficiente para nums2)
    merge(nums1, m, nums2, new_n);

    // Ordena a matriz mesclada para garantir que ela esteja em ordem crescente
    qsort(nums1, m + new_n, sizeof(int), compare);

    // Exibe a matriz nums1 após a mesclagem e ordenação
    printf("Matriz mesclada e ordenada: ");
    for (int i = 0; i < m + new_n; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    // Libera memória
    free(nums1);
    free(nums2);

    return 0;
}

