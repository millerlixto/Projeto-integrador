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

};

//Essas funções abaixo não devem ficar dentro da classe vetor3D

//Use nomes auto_explicativos para as variáveis. Menos comentários no código. Apague todos esses meus comentários depois que os entender tbm.
//esta função deve fazer a transformação de coordenada,
//equatorial(delta) para horizontal(altura)
//observe que os ângulos devem estar em radianos
//formula cos Delta * sin HA/sin phi = theta 
//delta_rad = declinação, hA_rad = ângulo hrario, h_rad = ângulo altura, 
//theta_rad = ângulo zenital,phi_rad = Angulo azimutal
float transf_coord_from_equat_to_horizon_theta(float delta_rad, float phi_rad,float hA_rad){
	float theta_rad;

	//mexi algumas coisas aqui mas a conta ainda nao está correta pq vc está dizendo que o resultado dessa conta é um valor de ângulo quando na verdade é o valor de uma função trigonométrica do ângulo. Foque no ângulo altura: mais fácil.
	//evite que seu código faça operações de memória desnecessárias

	//conversão para radianos do angulo theta
	theta_rad = (90*M_PI )/180;

	theta_rad -= cos(delta_rad)*sin(hA_rad)/sin(phi_rad);

	return theta_rad;
}	

//**********
//**********
//Miller, vou colar aqui a função que construí pra vc ver se ajuda e o que pode aproveitar.
//Algumas coisas pra vc notar:
//Foque nos ângulos Altura (ao invés do zenital) e Azimutal.
//Veja que a conta não vai até o valor do angulo em si, mas sim do seno do angulo
//Sugiro também que vc procure construir suas funções sempre de modo a calcular uma coisa de cada vez.
//Usar sempre funções pequenas a partir de outras funções pequenas. Esse é o estilo "código limpo". Importante pra tudo nao ficar uma bagunçã quando o código fica grande.
//Outra coisa é o nome das variáveis. Procure usar nomes auto-explicativos para as variáveis.
//Veja que os comentários que fiz nessa minha função são redundantes pelos nomes das funções e das variáveis usadas
//Pegue o que quiser daqui, construa sua função e depois apague todos esses comentários e a minha função, por favor.
//
float sin_Alt_calculation(int NDA, float lat, float local_time){

	float hor_rad = ang_hor_rad(local_time); //função que construí que transforma a hora em ângulo horário

	float lat_rad = deg_to_rad(lat);//função que construí que transf graus para radianos

	float decl_rad = decl_calculation(NDA); //função que construí que calcula a declinação a partir do numero do dia do ano (NDA)

	float sin_Alt = sin(lat_rad)*sin(decl_rad) + cos(lat_rad)*cos(decl_rad)*cos(hor_rad); //THIS GUY

	return sin_Alt; //retorna o seno do ângulo altura
}
//**********
//**********



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


//**********
//**********
//Outra função segundo minha construção:
//Veja se entende as construções, pegue o que quiser e depois apague do código, please.
//
float sin_Azim_calculation(int NDA, float lat, float local_time){

	float hor_rad = ang_hor_rad(local_time);

	float lat_rad = deg_to_rad(lat);

	float decl_rad = decl_calculation(NDA);

	float sin_Alt = sin(lat_rad)*sin(decl_rad) + cos(lat_rad)*cos(decl_rad)*cos(hor_rad); //THIS GUY
	float cos_Alt = sqrt(1 - pow(sin_Alt,2));

	//ângulo/distância zenital é o complementar da altura Alt
	/* float zen = acos(sin_Alt); */

	float sin_Azim = cos(decl_rad)*sin(hor_rad)/cos_Alt;  //AND THIS GUY
	/* float cos_Azim = sqrt(1 - pow(sin_Azim,2)); */

	return sin_Azim;// retorna o seno do ângulo azimutal
}

//**********
