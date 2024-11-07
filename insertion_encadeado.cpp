#include<stdio.h>
#include<stdlib.h>

//definica do no da lista
struct no{
int dado;
struct no* next;
};

//funcao para criar um novo no
struct no* criar_no(int dado){
   struct no* new_no = (struct no*)malloc(sizeof(struct no));
   new_no -> dado = dado;
   new_no -> next = NULL;
   return new_no;
}

//funçao para adicionar um no no final da lista
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

//funçao para imprimir a lista
void printlist(struct no* head){
  struct no* no_atual = head;
  while (no_atual != NULL) {
   printf("%d -> ", no_atual -> dado);
   no_atual = no_atual -> next;
  }
  printf("NULL\n");
}

//liberando memoria
void freeList(struct no* head){
 struct no* current = head;
 struct no* next;
  
   while(current != NULL){
   next = current -> next;
   free(current);
   current = next;
   }
}


struct no* insertion_sort(struct no* head){
 if(head == NULL || head->next == NULL){
   return head;
 }

struct no* sorted = NULL; //lista ordenada, inicialmente vazia
struct no* atual = head;

//percorrer a lista original
while (atual != NULL){
    struct no* proximo = atual->next; //guardar  o proximo nó para a próxima iteração

    //inserir nó atual na posição correta da lista ordenada
    if (sorted == NULL || sorted->dado >= atual->dado){
        //inserir no inicio ou na posição correta da lista ordenada
        atual->next = sorted;
        sorted = atual;
    } else {
        struct no* temp = sorted;
        //encontrar o local de inserção (entre dois nós)
        while (temp->next != NULL && temp->next->dado < atual->dado){
            temp = temp->next;
        }
        atual->next = temp->next;
        temp->next = atual;
    }
    
    //avançar para o próximo nó
    atual = proximo;
}
return sorted;//retorna a nova cabeça da lista ordenada

}


//funçao principal
int main(){
  struct no* head = NULL;
  
  //add elememtos
  head = criar_no(2);
  insere_no(head,3);
  insere_no(head,1);
  insere_no(head,5);
  insere_no(head,4);

  // Imprimindo a lista original
    printf("Lista original:\n");
    printlist(head);

    // Chamando o insertion_sort
    head = insertion_sort(head);

    // Imprimindo a lista ordenada
    printf("Lista ordenada:\n");
    printlist(head);

  
  //liberando memoria
  freeList (head);
  
  return 0;
}
