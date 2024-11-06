#include <stdio.h>
//\n

void troca(int *a, int *b){
   int temp;
   temp = *a; // armazena o  valr de a
   *a = *b; //
   *b = temp; // b recebe o valor aramazenado de a

}

int main(){
    int p = 15;
    int q = 30;

    troca(&p, &q);

printf("p: %d, q: %d\n", p, q);

return 0 ;
}