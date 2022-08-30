/******************************************************************************
 classe_vetor3D.cpp

 Linguagem c++

A classe recebe as coordenadas do vetor S

Criado por: Miller calixto almeida
Data de criação: 24/07/2022

Ultima modificacao: 03/01/2022
Status:FUNCIONANDO
* *******************************************************************************/
#include <cmath>
#include <iostream>



//Classe que recebe as coordenadas do vetor S
class vetor3d{
 
 public: 
 float comp[3];

 //construtor trivial
 vetor3d(){
	this->comp[0] = 0;
	this->comp[1] = 0;
	this->comp[2] = 0;
 }

 //construtor já com coordenadas
 vetor3d(float x, float y, float z){
	this->comp[0] = x;
	this->comp[1] = y;
	this->comp[2] = z;
 }

 	void reset_comp(float x, float y, float z){
	this->comp[0] = x;
	this->comp[1] = y;
	this->comp[2] = z;
}

vetor3d vectorsum(vetor3d v, vetor3d result){
	result.comp[0] = this->comp[0] + v.comp[0];
	result.comp[1] = this->comp[1] + v.comp[1];
	result.comp[2] = this->comp[2] + v.comp[2];

return result;
}

//método que calcula o produto escalar entre dois vetores:
float scalar_product(vetor3d v){
float result = 0.0;
for(int i=0;i<=2;i++)result+= v.comp[i]*this->comp[i];

return result;
}

//esta função deve fazer a transformação de coordenadas esféricas (r, theta, phi) para cartesianas
//observe que os ângulos devem estar em radianos
//r = raio, theta_rad = âgulo zenital,Phi_rad = âgulo azimutal
	void transf_coord_from_spher_to_cart(float r, float theta_rad, float phi_rad){
	    
	float beta_rad = 90-(theta_rad);
	this->comp[0] =r*(std::cos(beta_rad)*cos(phi_rad));
	this->comp[1] =r*(std::cos(beta_rad)*sin(phi_rad));
	this->comp[2] =r*(std::sin(beta_rad));
	}

	
//esta função deve fazer a transformação de coordenada,
//equatorial(delta) para horizontal(altura)
//observe que os ângulos devem estar em radianos
//formula cos Delta * sin HA/sin phi = theta 
//delta_rad = declinação, hA_rad = ângulo hrario, h_rad = ângulo altura, 
//theta_rad = ângulo zenital,phi_rad = Angulo azimutal
    float transf_coord_from_equat_to_horizon_theta(float delta_rad, float phi_rad,float hA_rad){
	float theta,theta_rad,convert_theta,result;

	theta = 90;
	//conversão para radianos do angulo theta
	convert_theta = (theta*3.141592653589793238462643383279502884197169399375105820974944)/180;
	theta_rad = convert_theta;
	theta_rad -= std::cos(delta_rad)*sin(hA_rad)/sin(phi_rad);
	result = theta;
	return result;
	}	



//esta função deve fazer a transformação de coordenada,
//equatorial(phi) para horizontal(Azimutal)
//observe que os ângulos devem estar em radianos
//formula = cos angulo Azimutal = - cos latitude* sin declinação + sin latitude * cos declinação * cos angulo horário/cos altura 
//delta_rad = declinação, hA_rad = ângulo hrario,
//h_rad = altura,phi_rad = Angulo azimutal, beta_rad = latitude
	float transf_coord_from_equat_to_horizon_theta(float delta_rad, float beta_rad,float hA_rad,float h_rad){
	float phi_rad,result;

    phi_rad = - std::cos(beta_rad)*sin(delta_rad)+sin(beta_rad)*cos(delta_rad)*cos(hA_rad)/cos(h_rad);
	result = phi_rad;
	return result;
	}
};


	
	


