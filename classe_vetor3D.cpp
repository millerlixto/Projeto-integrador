/******************************************************************************
 classe_vetor3D.cpp

 Linguagem c++

A classe recebe as coordenadas do vetor S

Criado por: Miller calixto almeida
Data de criação: 24/07/2022

Ultima modificacao: 30/07/2022
Status:FUNCIONANDO
* *******************************************************************************/
#include <iostream>


//Classe que recebe as coordenadas do vetor S
class vetor3d{
 
 public: 
 float coord[3];

 //construtor trivial ... pode ser útil em algum contexto
 vetor3d(){
	this->coord[0] = 0;
	this->coord[1] = 0;
	this->coord[2] = 0;
 }

 //construtor já com coordenadas
 vetor3d(float x, float y, float z){
	this->coord[0] = x;
	this->coord[1] = y;
	this->coord[2] = z;
 }

 	void reset_coord(float x, float y, float z){
	this->coord[0] = x;
	this->coord[1] = y;
	this->coord[2] = z;
}

vetor3d vectorsum(vetor3d v, vetor3d result){
result.coord[0] = this->coord[0] + v.coord[0];
result.coord[1] = this->coord[1] + v.coord[1];
result.coord[2] = this->coord[2] + v.coord[2];

return result;
}

//método que calcula o produto escalar entre dois vetores:
float scalar_product(vetor3d v){
float result = 0.0;
for(int i=0;i<2;i++)result=+ v.coord[i]*this->coord[i];

return result;
}

//código aqui

return result;
}

//esta função deve fazer a transformação de coordenadas esféricas (r, theta, phi) para cartesianas
//observe que os ângulos devem estar em radianos
	void transf_coord_from_spher_to_cart(float r, float theta_rad, float phi_rad){
		this->coord[0] = 
		this->coord[1] = 
		this->coord[2] = 
	}

};
