#include<stdio.h>
#include<stdlib.h>

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

// Função para liberar a memória da lista
void freeList(struct no* head) {
    struct no* current = head;
    struct no* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Função para obter o último nó da lista
struct no* get_last_node(struct no* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

// Função para particionar a lista em torno de um pivô
struct no* partition(struct no* low, struct no* high, struct no** new_head, struct no** new_end) {
    struct no* pivot = high;
    struct no* prev = NULL;
    struct no* current = low;
    struct no* tail = pivot;
    
    // Variáveis para reordenação
    while (current != pivot) {
        if (current->dado < pivot->dado) {
            // Se o dado é menor que o pivô, move o nó para a frente
            if (*new_head == NULL) {
                *new_head = current;
            }
            prev = current;
            current = current->next;
        } else {
            // Se o dado é maior que o pivô, move o nó para o final
            if (prev != NULL) {
                prev->next = current->next;
            }
            struct no* tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }

    // Adiciona o pivô ao final da lista
    if (*new_head == NULL) {
        *new_head = pivot;
    }
    *new_end = tail;

    return pivot;
}

// Função recursiva para ordenar a lista utilizando Quick Sort
struct no* quick_sort_rec(struct no* head, struct no* end) {
    // Se a lista tiver 0 ou 1 elementos, já está ordenada
    if (head == NULL || head == end) {
        return head;
    }

    struct no* new_head = NULL;
    struct no* new_end = NULL;

    // Particiona a lista
    struct no* pivot = partition(head, end, &new_head, &new_end);

    // Se o pivô não for o primeiro elemento, ordena a parte esquerda
    if (new_head != pivot) {
        struct no* temp = new_head;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;

        new_head = quick_sort_rec(new_head, temp);

        // Conecta a parte esquerda ao pivô
        temp = get_last_node(new_head);
        temp->next = pivot;
    }

    // Ordena a parte direita
    pivot->next = quick_sort_rec(pivot->next, new_end);

    return new_head;
}

// Função principal para chamar o quick sort
struct no* quick_sort(struct no* head) {
    struct no* end = get_last_node(head);
    return quick_sort_rec(head, end);
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

    head = quick_sort(head);
    printf("Lista ordenada:\n");
    printlist(head);

    freeList(head);

    return 0;
}
