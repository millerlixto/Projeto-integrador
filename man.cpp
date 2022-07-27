/******************************************************************************
 vetor_S.cpp

 Linguagem c++

O programa retorna o vetor S em coordenadas locais/horizontais a partir das coordenadas equatoriais.

Criado por: Miller calixto almeida
Data de criação: 24/07/2022

Ultima modificacao: 24/07/2022
Status:EM ANDAMENTO
* *******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdlib>

int main(){

std::vector <double> vector_b_j;
std::vector <double> vector_y;//P
std::vector <double> vector_x;//J

 

//
//Variaves das coordenadas
	double altura,anguloAzimultal;//coordenadas locais
	double anguloHorario,delta;//Coordenadas equatoriais
	double theta;//rotação em torno do eixo cartesiano y
	
//abertura de arquivo
    FILE *arq1;

      arq1=fopen("vetor_S.dat","w"); //Abertura de arquivo


       //Parametros da função
       altura=0.0;
       anguloAzimultal = 0.0;
       anguloHorario = 0.0;
       delta = 0.0;
       theta = 0.0;
     
//função 1
double cos_altura = (std::cos(theta)*std::cos(delta)*std::cos(anguloHorario)- std::sin(theta)*std::sin(delta))/std::cos(anguloAzimultal);

//função 2
double cos_angAzimultal = (std::cos(theta)*std::cos(delta)*std::cos(anguloHorario)- std::sin(theta)*std::sin(delta))/std::cos(altura);

//função 3
double sin_angAzimultal = (std::cos(delta)*std::sin(anguloHorario))/std::cos(altura);

//função 4
double sin_altura = std::sin(theta)*std::sin(delta) + std::cos(theta)*std::cos(delta)*std::cos(anguloHorario);





	fprintf(arq1,"%lf",cos_altura); //gravação de arquivo

std::cout<<cos_altura<<","<<cos_angAzimultal<<","<<sin_angAzimultal<<","<<sin_altura;
   
fclose(arq1); //Fechamento do arquivo

	return 0;
}
