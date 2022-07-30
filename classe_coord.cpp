/******************************************************************************
 classe_coord.cpp

 Linguagem c++

A classe recebe as coordenadas do vetor S

Criado por: Miller calixto almeida
Data de criação: 24/07/2022

Ultima modificacao: 30/07/2022
Status:FUNCIONANDO
* *******************************************************************************/
#include <iostream>



  
 //Classe que recebe as coordenadas do vetor S
  class Coord{
    //coordenadas
   float x,y,z;
   
   private: 
   float vector3d[3];
   
   public:
   void setVerctor3d(float,float,float);
 
};
//método para acessar o vertor
 void Coord::setVerctor3d(float x,float y,float z){
     vector3d[0]= {x};
     vector3d[1]= {y};
     vector3d[2]= {z};

}

int main(){

 Coord coordenadas; //criando objeto
coordenadas.setVerctor3d(0,0,0);//Entrada de coordenadas para o vetor


	return 0;
}
