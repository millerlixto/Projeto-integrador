#include <iostream>
#include <cmath>

//Basic functions-------------------------------------------------------------------------------------------------------------------

   	//função que transforma graus em radianos
	inline float transformation_deg_to_rad(float deg){
	float rad = (2*deg*M_PI)/(360);
	return rad;
	}
   
    //função que transforma a hora em ângulo horário
    inline float transformation_localTime_to_anguloHorario(float local_time){
	float ang_hor_rad = transformation_deg_to_rad((12.00-local_time)*15); 
	return ang_hor_rad;
	}
	
	 //função que calcula a declinação a partir do numero do dia do ano (NDA)
	inline float declination_calculation(float nda){
    float decl_rad = transformation_deg_to_rad(360.0*(nda-80.00)/365.25);
    decl_rad = 23.45*sin(decl_rad);
    transformation_deg_to_rad(decl_rad);
    return decl_rad;
	 }
	 
//Other functions------------------------------------------------------------------------------------------------------------------------------------

    //esta função deve fazer a transformação de coordenada,equatorial(declinaçao) para horizontal(altura)
    //observe que os ângulos devem estar em radianos
    inline float transf_coord_from_equat_declination_to_horizon_altura(float nda, float azim_rad,float local_time){
        
	float altura_rad = 90; 

	altura_rad = transformation_deg_to_rad(altura_rad);//conversão para radianos, do angulo altura
	
	float decl_rad =  declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
	
    float ang_hor_rad = transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
	
    altura_rad -= cos(decl_rad)*sin(ang_hor_rad)/sin(azim_rad);

	return cos(altura_rad);
	}	



    //função que deve fazer a transformação de coordenada, equatorial(phi) para horizontal(Azimutal)
    //observe que os ângulos devem estar em radianos
    inline	float transf_coord_from_equat_phi_to_horizon_azimutal(float nda, float lat,float local_time,float altura_rad){
	float azim_rad;

    float decl_rad =  declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
    
    float lat_rad  = transformation_deg_to_rad(lat);// converte a latitude em graus para radianos
    
    float ang_hor_rad = transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
    
    azim_rad = -cos(lat_rad)*sin(decl_rad)+sin(lat_rad)*cos(decl_rad)*cos(ang_hor_rad)/cos(altura_rad);

	return cos(azim_rad);
	}
    
    //função que deve retornar o seno da altura
    inline	float return_sin_altura(float nda, float lat,float local_time){
	    
	float decl_rad =  declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
	
	float lat_rad  = transformation_deg_to_rad(lat);// converte a latitude em graus para radianos
	
	float ang_hor_rad = transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
	 
    float sin_Alt = sin(lat_rad)*sin(decl_rad) + cos(lat_rad)*cos(decl_rad)*cos(ang_hor_rad);
    
	return sin_Alt; //retorna o seno do ângulo altura
	}

  //função que deve retornar o seno do angulo azimutal
    inline	float return_sin_azimulte(float nda, float lat,float local_time){
	    
	float decl_rad =  declination_calculation(nda); //calculo da declinação a partir do numero do dia do ano
	
	float lat_rad  = transformation_deg_to_rad(lat);// converte a latitude em graus para radianos
	
	float ang_hor_rad = transformation_localTime_to_anguloHorario(local_time);//conversão de horas para angulo horário
	 
    float sin_Alt = sin(lat_rad)*sin(decl_rad) + cos(lat_rad)*cos(decl_rad)*cos(ang_hor_rad);
    
    float cos_Alt = sqrt(1-pow(sin_Alt,2));
    
    float sin_Azimulte = cos(decl_rad)* sin(ang_hor_rad)/cos_Alt;
    
	return sin_Azimulte; //retorna o seno do ângulo azimutal
	}
