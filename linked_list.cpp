/*#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
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
    if (head == NULL) {
        return new_no;
    }

    struct no* no_atual = head;
    while (no_atual->next != NULL) {
        no_atual = no_atual->next;
    }
    no_atual->next = new_no;
    return head;
}

// Função para percorrer a lista e imprimir seus elementos
void percorrer_lista(struct no* head) {
    struct no* no_atual = head;
    while (no_atual != NULL) {
        printf("%d -> ", no_atual->dado);
        no_atual = no_atual->next;
    }
    printf("NULL\n");
}

// Função para trocar dois nós de lugar (trocando os ponteiros, não os valores)
struct no* trocar_nos(struct no* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Se a lista tiver 0 ou 1 elemento, não há o que trocar
    }

    int trocou;
    do {
        trocou = 0;
        struct no* atual = head;
        struct no* anterior = NULL;

        // Percorre a lista verificando pares de nós adjacentes
        while (atual != NULL && atual->next != NULL) {
            struct no* proximo = atual->next;
            // Verifica se o nó atual é maior que o próximo
            if (atual->dado > proximo->dado) {
                // Se for maior, realiza a troca de ponteiros

                if (anterior == NULL) {
                    // Caso seja o primeiro nó, a cabeça da lista muda
                    head = proximo;
                } else {
                    // Caso contrário, o nó anterior deve apontar para o próximo nó
                    anterior->next = proximo;
                }

                // O próximo nó passa a apontar para o nó atual
                atual->next = proximo->next;
                proximo->next = atual;

                // Marca que houve uma troca
                trocou = 1;
            }

            // Avança os ponteiros
            anterior = atual;
            atual = atual->next;
        }
    } while (trocou);  // Repete enquanto houver trocas

    return head;  // Retorna a cabeça da lista
}

// Função principal
int main() {
    struct no* head = NULL;

    // Inserindo alguns elementos na lista
    head = insere_no(head, 5);
    head = insere_no(head, 3);
    head = insere_no(head, 8);
    head = insere_no(head, 2);
    head = insere_no(head, 6);

    // Imprimindo a lista original
    printf("Lista original:\n");
    percorrer_lista(head);

    // Chamando a função para percorrer a lista e fazer as trocas até a lista estar ordenada
    head = trocar_nos(head);

    // Imprimindo a lista após as trocas
    printf("Lista ordenada (crescente):\n");
    percorrer_lista(head);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista
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
    if (head == NULL) {
        return new_no;
    }

    struct no* no_atual = head;
    while (no_atual->next != NULL) {
        no_atual = no_atual->next;
    }
    no_atual->next = new_no;
    return head;
}

// Função para percorrer a lista e imprimir seus elementos
void percorrer_lista(struct no* head) {
    struct no* no_atual = head;
    while (no_atual != NULL) {
        printf("%d -> ", no_atual->dado);
        no_atual = no_atual->next;
    }
    printf("NULL\n");
}

// Função para inserir um nó na posição correta da lista (insertion sort)
struct no* insertion_sort(struct no* head) {
    if (head == NULL || head->next == NULL) {
        return head;  // Se a lista tem 0 ou 1 elemento, já está ordenada
    }

    struct no* sorted = NULL;  // Lista ordenada, inicialmente vazia
    struct no* atual = head;

    // Percorrer a lista original
    while (atual != NULL) {
        struct no* proximo = atual->next;  // Guardar o próximo nó para a próxima iteração

        // Inserir o nó atual na posição correta da lista ordenada
        if (sorted == NULL || sorted->dado >= atual->dado) {
            // Inserir no início ou na posição correta na lista ordenada
            atual->next = sorted;
            sorted = atual;
        } else {
            struct no* temp = sorted;
            // Encontrar o local de inserção (entre dois nós)
            while (temp->next != NULL && temp->next->dado < atual->dado) {
                temp = temp->next;
            }
            atual->next = temp->next;
            temp->next = atual;
        }

        // Avançar para o próximo nó
        atual = proximo;
    }

    return sorted;  // Retorna a nova cabeça da lista ordenada
}

// Função principal
int main() {
    struct no* head = NULL;

    // Inserindo alguns elementos na lista
    head = insere_no(head, 5);
    head = insere_no(head, 3);
    head = insere_no(head, 8);
    head = insere_no(head, 2);
    head = insere_no(head, 6);

    // Imprimindo a lista original
    printf("Lista original:\n");
    percorrer_lista(head);

    // Chamando a função de Insertion Sort
    head = insertion_sort(head);

    // Imprimindo a lista ordenada
    printf("Lista ordenada (crescente):\n");
    percorrer_lista(head);

    return 0;
}


