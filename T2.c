	#include <stdio.h>
	#include <math.h>

	int main(int argc, char const *argv[]){
	int n, it;
	float t;

	//n = 5; it = 4; t = 0.7;
	n = 0; it = 0; t = 0.0;
	scanf("%d %d %f", &n, &it, &t);

	//int tabela[5][4] = {5, 3, 2, 0, 1, 3, 4, 3, 0, 3, 0, 2, 0, 0, 0, 3, 1, 3, 2, 4};
	int tabela[n][it];
	float similaridade[n][n];
	float medias[n];

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			tabela[i][j] = 0;
			scanf("%d", &tabela[i][j]);
		}
	}

	int nominadorsimilaridade;
	float raiz1, raiz2;
	float media;
	int indice;

	nominadorsimilaridade = 0; raiz1 = 0; raiz2 = 0; media = 0; indice = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			for (int k = 0; k < it; ++k){
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

	float nominadornota = 0.0;
	float denominadornota = 0.0;
	int teste = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			if(tabela[i][j] == 0){
				for (int k = 0; k < n; ++k){
					if (similaridade[i][k] >= t){
						if (tabela[k][j] > 0){
							nominadornota += similaridade[i][k] * (tabela[k][j] - medias[k]);
							denominadornota += similaridade[i][k];
							teste = 1;
						}
					}
				}				
				if (nominadornota != 0 || denominadornota != 0)
				{
					printf("%.2f ", medias[i] + nominadornota/denominadornota);
				}
				else{
					printf("DI ");
					teste = 1;
				}
			}
			else{
			}
			denominadornota = 0.0; nominadornota = 0.0;
		}
		if (teste == 1)
		{
			printf("\n");
			teste = 0;
		}
	}
	return 0;
	}

	/*5 7 0.65	                                        
	5 3 2 3 4 4 4
	4 5 2 1 5 4 2
	1 4 4 2 3 5 1
	5 2 3 4 2 1 5
	1 0 2 3 2 3 0

	5 4 0.7                                                     
	5 3 2 0
	1 3 4 3
	0 3 0 2
	0 0 0 3
	1 3 2 4
	*/