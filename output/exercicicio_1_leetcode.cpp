//Dada a natureza headde uma lista encadeada, retorne a lista após classificá-la em ordem crescente 
//exercicio 148 do leetcode

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

struct no* bubble_sort(struct no* head) {
  // Caso a lista tenha menos de 2 elementos, não há nada para trocar
  if (head == NULL || head->next == NULL) {
   return head;
  }
  
  int trocou;
  do{
    trocou = 0;
    struct no* atual = head;
    struct no* anterior = NULL;

    //percorre a lista verificando pares de nós adjacentes
    while(atual != NULL && atual->next != NULL){
      struct no* proximo = atual->next;
      //verifica se o nó atual é maior que o próximo
      if(atual->dado > proximo->dado){
        //se for maior, realiza a troca 
        if(anterior == NULL){
          //caso seja o primeiro nó, a cabeça da lista muda
          head = proximo;
        } else {
          //caso contrário, o nó anterior deve apontar para o próximo
          anterior->next = proximo;
        }

        //o próximo nó passa a apontar para o nó atual
        atual->next = proximo->next;
        proximo->next = atual;

        //marca que houve uma troca
        trocou = 1;
      }

      //avança os ponteiros
      anterior = atual;
      atual = atual->next;
    }
  } while (trocou);//repete enquanto houver trocas
  
  return head;//retorna a cabeça da lista

}




int main(){
struct no* head = NULL;
printf("lista original:\n ");
head = criar_no(7);
insere_no(head, 1);
insere_no(head, 0);
insere_no(head, 2);

printlist(head);
printf("lista ordenada:\n ");
head = bubble_sort(head);

printlist(head);
}