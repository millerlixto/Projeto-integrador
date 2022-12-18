# Objetivo: 

	Calcular a potência P refletida por um espelho localizado na posição r_e =
	(x_e,y_e,z_e) sobre um ponto focal localizado em r_f = (x_f,y_f,z_f) numa
	latitude (lat), dia do ano (NDA) e hora do dia (hora_local):
	P=P(r_e, r_f, lat, NDA, hora_local)

# Estratégia:

	1. Os valores de lat, NDA e hora_local devem ser usados para calcular o vetor
		 s que dá a direção do raio de sol (vetor que aponta para o sol a partir da
		 origem) em coordenadas horizontais locais. Ou seja, s é uma função
		 vetorial (retorna um vetor, o vetor s) que depende de 3 variáveis: s = s(lat, NDA, hora_local).

		 1. terminar a conta de mudança das coordenadas equatoriais para as
				horizontais e escrever s em coordenadas cartesianas locais. 
				(TRABALHAR AQUI - comentário em 02/11)

	2. Com s calculado, e conhecendo o vetor que liga a posição do espelho ao
		 ponto focal, o qual dá a direção do raio refletido, usamos a lei
		 de reflexão para calcular qual será o vetor normal n à superfície do
		 espelho. A lei de reflexão traz duas afirmações matemáticas aqui: 1) o
		 ângulo entre o vetor incidente com a normal é igual ao ângulo do vetor
		 refletido com a normal; 2) os vetores incidente, normal e refletido são
		 coplanares.

	3. A potência refletida pelo espelho é calculada pelo produto escalar entre a
		 normal do espelho e s (ambos tomados em suas versões unitárias)
		 multiplicado pela área A do espelho multiplicada pela constante solar C_s
		 (estamos assumindo por enquanto que toda a radiação solar chega à
		 superfície da terra sem qualquer atenuação atmosférica) :
		 P = A C_s (n.s)

# Passos posteriores:

	* Considerar correções de absorção de radiação na atmosfera.
	* Fazer várias simulações. 
	* Fazer estudo de dados de estações metereológicas e estimar potência real coletada.
	* Construir modelo 3d de um heliostato.
	* Construir heliostato real.
