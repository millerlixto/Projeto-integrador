#ifndef VARIOUS_FUCTIONS_H_INCLUDED
#define VARIOUS_FUCTIONS_H_INCLUDED
#include <iostream>
#include <cmath>

int functions(){


	return 0;
}

//various functions-------------------------------------------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------------------------------------------------------------

#endif