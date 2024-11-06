#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<cmath>

using namespace std;

class Forma{
public:
  //método virtual que deve ser sobrescrito
  virtual double area(){
    return 0.0;//área padrão
  }
};

class Retangulo : public Forma{
private:
  double largura;
  double altura;

public:
   Retangulo(double l, double h):largura(l), altura(h){}

   //Complete o método area para calcular a área do retângulo
  double area(){
   return largura*altura;
  }

};

class Circulo : public Forma{
private:
  double raio;
public:
  Circulo(double r): raio(r){}

  //Complete o método area para calcular a área do circulo
  double area(){

    return M_PI*(raio*raio);
  }
};

int main(){
  Forma* formas[2];
  formas[0] = new Retangulo(5, 10);
  formas[1] = new Circulo(7);

  for(int i = 0; i < 2; i++){
    cout<<"Area: "<< formas[i]->area()<<endl;
  }

  //Libere a memória
  delete formas[0];
  delete formas[1];

  return 0;

}