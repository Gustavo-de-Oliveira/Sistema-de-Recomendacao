#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int n, it;
	float t;

	//inicio bloco de leitura das variaveis e da tabela/matriz
	n = 0; it = 0; t = 0.0;
	scanf("%d %d %f", &n, &it, &t);

	int tabela[n][it];
	float similaridade[n][n];
  
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			tabela[i][j] = 0;
			scanf("%d", &tabela[i][j]);
		}
	}
	//fim bloco de leitura das variaveis e da tabela/matriz

	//inicio do bloco para calculo das similaridades
	int nominadorsimilaridade;
	float raiz1, raiz2;
	
	nominadorsimilaridade = 0; raiz1 = 0; raiz2 = 0;	
	for (int i = 0; i < n; i = ++i){
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < it; ++k){
				nominadorsimilaridade += tabela[i][k] * tabela[j][k];
				raiz1 += pow(tabela[i][k], 2);
				raiz2 += pow(tabela[j][k], 2);
			}
			similaridade[i][j] = nominadorsimilaridade/(sqrt(raiz1) * sqrt(raiz2));
			if (similaridade[i][j] == 1.00){
				similaridade[i][j] = 0;
			}
			nominadorsimilaridade = 0; raiz1 = 0; raiz2 = 0;
		}
	}
	//fim do bloco de calculo de similaridade

	//inicio do bloco para calculo de estimativa de nota
	float nominadornota = 0.0;
	float denominadornota = 0.0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			if(tabela[i][j] == 0){
				for (int k = 0; k < n; ++k){
					if (similaridade[i][k] >= t){
						if (tabela[k][j] > 0){
							nominadornota += similaridade[i][k] * tabela[k][j];
							denominadornota += similaridade[i][k];
						}
					}
				}
				printf("%.2f\n", nominadornota/denominadornota);
			}
			denominadornota = 0.0;
			nominadornota = 0.0;
		}
	}
	return 0;
}
/*5 7 0.65	                                        
5 3 2 3 4 4 4
4 5 2 1 5 4 2
1 4 4 2 3 5 1
5 2 3 4 2 1 5
1 0 2 3 2 3 0*/