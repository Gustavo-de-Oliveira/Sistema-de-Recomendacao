#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]){
	int n, it;
	float t;

	//inicio bloco de leitura das variaveis e da tabela/matriz
	n = 0; it = 0; t = 0.0;
	scanf("%d %d %f", &n, &it, &t);

	int tabela[n][it];
	float similaridade[n][n-1];
  
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			scanf("%d", &tabela[i][it]);
		}
	}
   
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < it; ++j){
			printf(" %d ", tabela[i][it]);
		}
	}
	//fim bloco de leitura das variaveis e da tabela/matriz

	/*//inicio do bloco para calculo das similaridades
	int nominador;
	float denominador;
	float raiz1, raiz2;
	for (int i = 0; i < n; ++i){
		nominador = 0; denominador = 0.0; raiz1 = 0; raiz2 = 0;
		for (int j = 0; j < n; ++j){
				for (int k = 0; k < it; ++k){
					nominador += tabela[i][j]*tabela[i][k];
					printf("%d\n", nominador);
			}
		}
	}*/

	return 0;
}