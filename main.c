//Faça um Programa para uma loja de tintas. O programa deverá pedir o tamanho em metros quadrados da área a ser pintada. 
//Considere que a cobertura da tinta é de 1 litro para cada 6 metros quadrados e que a tinta é vendida em latas de 18 litros, 
//que custam R$ 80,00 ou em galões de 3,6 litros, que custam R$ 25,00. Informe ao usuário as quantidades de tinta a serem 
//compradas e os respectivos preços em 3 situações: comprar apenas latas de 18 litros; comprar apenas galões de 3,6 litros;
//misturar latas e galões, de forma que o desperdício de tinta seja menor. Acrescente 10% de folga e sempre arredonde os valores 
//para cima, isto é, considere latas cheias.

#include<stdio.h>
#include<math.h>

float metro_2;
float litros_n;
double latas_de_tinta;
double galoes_de_tinta;
double galoes_e_latas;
float custo_total;

int main(){

//calculo dos litros precisos
printf("Qual o tamanho em metros qudrados da area pintada: ");
scanf("%f",&metro_2);
//(metro_2/6)= litros necessários
litros_n = metro_2/6;
printf("Os litros necessarios e igual a: %2.f L\n", litros_n);


//situação 1, latas de 18
if (litros_n <= 18)
{
    printf("Voce precisa de apenas uma lata de tinta\n");
    printf("Uma lata de tinta custa 80.00R$\n");
}
else if (litros_n > 18)
{

    latas_de_tinta = litros_n/18;
    double arredondar_para_cima(double latas_de_tinta)
    {
        return ceil(latas_de_tinta);       
    }
    printf("O numero de latas de tinta e igual a: %.2f\n", arredondar_para_cima(latas_de_tinta));

    custo_total = 80 * arredondar_para_cima(latas_de_tinta);
    printf("O custo total a ser gasto e igual a: %2.f R$", custo_total);
}

//situação 2, galões de 3,6

galoes_de_tinta = litros_n/3.6;
double arredondar_para_cima(double galoes_de_tinta)
{
   return ceil(galoes_de_tinta);
}
printf("O numero de galoes de tinta e igual a: %.2f\n", arredondar_para_cima(galoes_de_tinta));

custo_total = 25 * arredondar_para_cima(galoes_de_tinta);
printf("O custo total a ser gasto e igual a: %.2f R$", custo_total);

// situação 3, misturar latas e galões

galoes_e_latas = litros_n/21.3;
double arredondar_para_cima(galoes_e_latas)
{
    return ceil(galoes_e_latas);
}

printf("O numero de galoes e latas e igual a: %2.f\n", arredondar_para_cima(galoes_e_latas));

custo_total = 105 * arredondar_para_cima(galoes_e_latas);
printf("O custo total a ser gasto é igual a: %2.f R$", custo_total);


}

