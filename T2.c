/*
	Programa que calcula a similaridade de preferencias entre usuarios.
	Trabalho 2 - ICC
	Gustavo de Oliveira Silva - ICMC/USP	
	30/04/2018
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
	//decaração das variaveis de programa
	int usuarios, itens;
	float limiar;

	//leitura dos parâmetros da matriz
	usuarios = 0; itens = 0; limiar = 0.0;
	scanf("%d %d %f", &usuarios, &itens, &limiar);

	//declaração das matrizes
	int tabela[usuarios][itens];
	float similaridade[usuarios][usuarios];
	float medias[usuarios];

	//leitura da tabela de notas
	for (int i = 0; i < usuarios; ++i){
		for (int j = 0; j < itens; ++j){
			tabela[i][j] = 0;
			scanf("%d", &tabela[i][j]);
		}
	}

	//variáveis para o cálculo de similaridade
	int nominadorsimilaridade;
	float raiz1, raiz2;
	float media;
	int indice;

	//calculo de similaridade
	nominadorsimilaridade = 0; raiz1 = 0; raiz2 = 0; media = 0; indice = 0;
	for (int i = 0; i < usuarios; ++i){
		for (int j = 0; j < usuarios; ++j){
			for (int k = 0; k < itens; ++k){
				nominadorsimilaridade += tabela[i][k] * tabela[j][k];
				raiz1 += pow(tabela[i][k], 2);
				raiz2 += pow(tabela[j][k], 2);
				media += tabela[i][k];
				if (tabela[i][k] != 0){
					indice++;
				}
			}
			medias[i] = media/indice;
			similaridade[i][j] = nominadorsimilaridade/(sqrt(raiz1) * sqrt(raiz2));
			if (similaridade[i][j] == 1.00){
				similaridade[i][j] = 0;
			}
			nominadorsimilaridade = 0; raiz1 = 0; raiz2 = 0; media = 0; indice = 0;
		}
	}

	//variaveis para estimar a nota
	float nominadornota = 0.0;
	float denominadornota = 0.0;
	int pseudoBool = 0;

	//cálculo para estimar a nota do usuário
	for (int i = 0; i < usuarios; ++i){
		for (int j = 0; j < itens; ++j){
			if(tabela[i][j] == 0){
				for (int k = 0; k < usuarios; ++k){
					if (similaridade[i][k] >= limiar){
						if (tabela[k][j] > 0){
							nominadornota += similaridade[i][k] * (tabela[k][j] - medias[k]);
							denominadornota += similaridade[i][k];
							pseudoBool = 1;
						}
					}
				}				
				if (nominadornota != 0 || denominadornota != 0)
				{
					printf("%.2f ", medias[i] + nominadornota/denominadornota);
				}
				else{
					printf("DI ");
					pseudoBool = 1;
				}
			}
			else{
			}
			denominadornota = 0.0; nominadornota = 0.0;
		}
		if (pseudoBool == 1)
		{
			printf("\n");
			pseudoBool = 0;
		}
	}
	return 0;
}