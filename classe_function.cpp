#include <iostream>
#include <cmath>


    //função que transforma a hora em ângulo horário
	float transformation_localTime_to_anguloHorario(float local_time){
	float ang_hor_rad = (local_time*15*M_PI)/180; 
	return ang_hor_rad;
	}
	
	//função que transforma graus em radianos
	float transformation_deg_to_rad(float deg){
	float rad = deg*M_PI/180;
	return rad;
	}
	
	 //função que calcula a declinação a partir do numero do dia do ano (NDA)
	 float declination_calculation(float nda){
     float decl_rad = 23.45*sin(360*(nda-80)/365);
     return decl_rad;
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
