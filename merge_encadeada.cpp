#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
struct no {
    int dado;
    struct no* next;
};

// Função para criar um novo nó
struct no* criar_no(int dado) {
    struct no* new_no = (struct no*)malloc(sizeof(struct no));
    new_no->dado = dado;
    new_no->next = NULL;
    return new_no;
}

// Função para adicionar um nó no final da lista
struct no* insere_no(struct no* head, int dado) {
    struct no* new_no = criar_no(dado);
    
    // Se a lista estiver vazia, o novo nó será a cabeça
    if (head == NULL) {
        return new_no;
    }
    
    struct no* no_atual = head;
    while (no_atual->next != NULL) {
        no_atual = no_atual->next;
    }
    no_atual->next = new_no;
    
    return head; // Retorna a cabeça original (não houve alteração na cabeça)
}

// Função para imprimir a lista
void printlist(struct no* head) {
    struct no* no_atual = head;
    while (no_atual != NULL) {
        printf("%d -> ", no_atual->dado);
        no_atual = no_atual->next;
    }
    printf("NULL\n");
}

// Liberando memória
void freeList(struct no* head) {
    struct no* current = head;
    struct no* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Função para dividir a lista em duas metades
struct no* dividir(struct no* head) {
    if (head == NULL || head->next == NULL) {
        return NULL; // Retorna NULL quando não há divisão possível
    }
    
    struct no* meio = head;
    struct no* fim = head->next;
    
    while (fim != NULL && fim->next != NULL) {
        meio = meio->next;
        fim = fim->next->next;
    }
    
    struct no* temp = meio->next;
    meio->next = NULL;  // Divide a lista em duas partes
    return temp;
}

// Função para mesclar duas listas ordenadas
struct no* mesclar(struct no* l1, struct no* l2) {
    struct no* resultado = NULL;
    
    // Se uma das listas estiver vazia, retorna a outra
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    // Compara os elementos e constrói a lista ordenada
    if (l1->dado <= l2->dado) {
        resultado = l1;
        resultado->next = mesclar(l1->next, l2);
    } else {
        resultado = l2;
        resultado->next = mesclar(l1, l2->next);
    }
    
    return resultado;
}

// Função para ordenar a lista usando Merge Sort
struct no* merge_sort(struct no* head) {
    if (head == NULL || head->next == NULL) {
        return head; // Lista já está ordenada ou vazia
    }
    
    // Dividir a lista em duas metades
    struct no* segunda_metade = dividir(head);
    
    // Ordenar as duas metades recursivamente
    head = merge_sort(head);
    segunda_metade = merge_sort(segunda_metade);
    
    // Mesclar as duas metades ordenadas
    return mesclar(head, segunda_metade);
}

int main() {
    struct no* head = NULL;
    int n, valor;

    // Solicita ao usuário o número de elementos
    printf("Quantos elementos deseja adicionar a lista? ");
    scanf("%d", &n);

    // Solicita os valores para a lista
    printf("Digite os %d valores para a lista:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        head = insere_no(head, valor);
    }

    printf("Lista original:\n");
    printlist(head);

    head = merge_sort(head);
    printf("Lista ordenada:\n");
    printlist(head);

    freeList(head);

    return 0;
}
