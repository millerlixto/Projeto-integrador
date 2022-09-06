#include "classe_function.cpp"
#include <iostream>
#include <cmath>


//Classe que recebe as coordenadas do vetor S
class vetor3d{
 
 function f1;//objeto criado
 
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
	this->comp[0] =r*std::cos(beta_rad)*cos(phi_rad);
	this->comp[1] =r*std::cos(beta_rad)*sin(phi_rad);
	this->comp[2] =r*std::sin(beta_rad);
	}

    //esta função deve fazer a transformação de coordenada,equatorial(declinaçao) para horizontal(altura)
   //observe que os ângulos devem estar em radianos
    float transf_coord_from_equat_declination_to_horizon_altura(float nda, float azim_rad,float local_time){
        
	float altura_rad = 90; altura_rad = f1.transformation_deg_to_rad(altura_rad);//conversão para radianos, do angulo altura
	
	float decl_rad =  f1.declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
	
    float ang_hor_rad = f1.transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
	
    altura_rad -= cos(decl_rad)*sin(ang_hor_rad)/sin(azim_rad);

	return cos(altura_rad);
	}	



//função que deve fazer a transformação de coordenada, equatorial(phi) para horizontal(Azimutal)
//observe que os ângulos devem estar em radianos
	float transf_coord_from_equat_phi_to_horizon_azimutal(float nda, float lat,float local_time,float altura_rad){
	float azim_rad;

    float decl_rad =  f1.declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
    
    float lat_rad  = f1.transformation_deg_to_rad(lat);// converte a latitude em graus para radianos
    
    float ang_hor_rad = f1.transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
    
    azim_rad = -cos(lat_rad)*sin(decl_rad)+sin(lat_rad)*cos(decl_rad)*cos(ang_hor_rad)/cos(altura_rad);

	return cos(azim_rad);
	}
    
    //função que deve retornar o seno da altura
	float return_sin_altura(float nda, float lat,float local_time){
	    
	float decl_rad =  f1.declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
	
	float lat_rad  = f1.transformation_deg_to_rad(lat);// converte a latitude em graus para radianos
	
	 float ang_hor_rad = f1.transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
	 
    float sin_Alt = sin(lat_rad)*sin(decl_rad) + cos(lat_rad)*cos(decl_rad)*cos(ang_hor_rad);
    
	return sin_Alt; //retorna o seno do ângulo altura
	}

};

