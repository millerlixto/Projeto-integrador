/******************************************************************************
 vetor_S.cpp

 Linguagem c++

O programa retorna o vetor S em coordenadas locais/horizontais a partir das coordenadas equatoriais.

Criado por: Miller calixto almeida
Data de criação: 24/07/2022

Ultima modificacao: 03/01/2022
Status:FUNCIONA
* *******************************************************************************/

#include "classe_vetor3D.cpp"
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>


int main(){

vetor3d coordenadas; //criando objeto;
coordenadas.reset_comp(0,0,0);//Entrada de coordenadas para o vetor

std::cout << "Valores das componentes do vetor:" << std::endl;
std::cout << "Vx="<< coordenadas.comp[0] << std::endl;
std::cout << "Vy="<< coordenadas.comp[1] << std::endl;
std::cout << "Vz="<< coordenadas.comp[2] << std::endl;


	return 0;
}
