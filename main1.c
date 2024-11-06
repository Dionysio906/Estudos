#include<stdio.h>
#include<string.h>

//\n

int i = 0;
int opcao;

typedef struct {
int codigo;
char nome[100];
float preco;
int qtde;
}lista;
lista produto [100];

void menu(){
printf("\n===MENU===\n1.Inserir produto\n2.Listar todos os produtos\n3.Buscar produto por nome\n4.Excluir produto por nome\n5.Sair\nEscolha uma opcao:");
printf("\n");
scanf("%d", &opcao);
}

void inserir(){
  int code = 0;
  int b = 1;
  int nomeduplicado = 1;
  char name [100];
  while (b == 1){
    printf("Digite o codigo do produto: ");
    scanf("%d", &code);
    for(int k = 0; k<=i; k++){
     if (produto[k].codigo == code){
        while (code == produto[k].codigo){
          printf("codigo ja existente. Insira outro!!\n");
          printf("Digite o codigo do produto: ");
          int tentativa = code;
          scanf("%d",&code);
          if (code < tentativa){
          k = 0;
          }
        }
      }
      b++;

    }
  }

  while (nomeduplicado){
  printf("Digite o nome do produto: "); 
  scanf("%s", name);

  nomeduplicado = 0;
  for (int m = 0; m <= i; m++){
    if (strcmp(produto[m].nome, name) == 0){
      printf("Nome já existente. Insira outro!!\n");
      nomeduplicado = 1;
      break;
    }
    
  }
  }
  
 produto[i].codigo = code;
 strcpy(produto[i].nome, name); 
 printf("Digite o preco do produto: ");
 scanf("%f",&produto[i].preco);
 printf("Digite a quantidade em estoque: ");
 scanf("%d",&produto[i].qtde);
 printf("\nproduto inserido com sucesso!\n");
 i++;
}

void listar(){
 if(i != 0){
  printf("Sua lista de produtos:\n\n");
  for(int c = 0; c < i; c++){
    printf("=====Produto: %s=====\n",produto[c].nome);
    printf("codigo: %d\n", produto[c].codigo);
    printf("codigo: %s\n", produto[c].nome);
    printf("codigo: %.2f\n", produto[c].preco);
    printf("codigo: %d\n", produto[c].qtde);
    printf("\n");
  } 
 }
 else
 {
    printf("Nao ha produtos na sua lista\n");
 }
}

void buscar(){
  char busca[100];
  printf("Qual produto esta procurando? ");
  scanf("%s",&busca);
  for(int t = 0; t <= i; t++){
    int CompBusc = strcmp(busca, produto[t].nome);
      if (CompBusc == 0){
        printf("Codigo: %d\n",produto[t].codigo);
        printf("Nome: %s\n",produto[t].nome);
        printf("Preco: %.2f\n",produto[t].preco);
        printf("Quantidade: %d\n\n",produto[t].qtde);
        //CompBusc++
      }
  }
}

void excluir(){
  char excluir[100];
  printf("Qual produto deseja excluir? ");
  scanf("%s", excluir);
  int encontrado = 0;
  for(int l = 0; l <= i; l++){
    if (strcmp(excluir,produto[l].nome) == 0){
      for (int j = l; j <= i ; j++){
        produto[j] = produto[j+1];
      }
     i--;
     printf("Produto excluido\n\n");
     encontrado = 1;
     break;
    }
  }
  if (!encontrado){
    printf("Produto nao encontrado para exclusao.\n");
  }
  
}

void main(){
 int w = 1;
 while (w==1){
    menu();
    switch (opcao){
    case 1:
      inserir();
      break;
    case 2:
      listar();
      break;
    case 3:
      buscar();
      break;
    case 4:
      excluir();
      break;
    case 5:
      printf("Saindo do programa");
      w++;
      break;    

    default:
      printf("Opcao inexistente");
      break;
    }
 }
 


}