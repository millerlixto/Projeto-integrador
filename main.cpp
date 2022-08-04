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

vetor3d v1; //criando objeto;
v1.reset_comp(1,0,0);//Entrada de coordenadas para o vetor

std::cout << "Valores das componentes do vetor v1:" << std::endl;
std::cout << "v1_x="<< v1.comp[0] << std::endl;
std::cout << "v1_y="<< v1.comp[1] << std::endl;
std::cout << "v1_z="<< v1.comp[2] << std::endl;

vetor3d v2(1,1,1);

vetor3d result;//criando o objeto assim ele já recebe 0 nas componentes pelo construtor trivial

result = v1.vectorsum(v2, result);

std::cout << "Valores das componentes do vetor soma:" << std::endl;
std::cout << "result_x="<< result.comp[0] << std::endl;
std::cout << "result_y="<< result.comp[1] << std::endl;
std::cout << "result_z="<< result.comp[2] << std::endl;



	return 0;
}
