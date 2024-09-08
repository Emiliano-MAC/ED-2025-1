#include <stdio.h>
#include <stdlib.h>

void leerMatriz(int n, int m, int matriz[n][m]){
	printf("Ingresa los elementos de la matriz: \n");
	
		for(int i = 0; i<n; i++){
			
			for(int j=0; j<m; j++){
			
			printf("Elementos [%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
			
			}
			
		}	
}


void imprimeMatriz(int n, int m, int matriz[n][m]){
	printf("La matriz es:\n");
	for (int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			
			printf("%d ",matriz[i][j]);
		}
		
	printf("\n");
	}
	
	
}

//recorrido en S de la matriz 6x4
void recorridoMatrizEnS(int n, int m, int matriz [n][m]){
	int i,j;
	
	printf("El recorrido de la matriz en S es:\n");
	
	for(i=0;i<n ;i++){
		if(i % 2==0){
			
			for (j=0;j<m;j++)
			printf("%d ", matriz[i][j]);
			
		}else{

			for(j=m-1;j>=0;j--)
			printf("%d ", matriz[i][j]);
			
		}
	printf("\n");		
	}
	
}

//Recorrido de la matrzin 6x6 en Z desde arriba hacia abajo

void recorridoMatrizEnZ(int n, int m, int matriz[n][m]){
	int i,j;
	printf("El recorrido de la matriz 6x6 en Z es desde arriba hacia abajo: \n");
	
	for (j=m-1; j>=0; j--){
		
		if(j==0 || j==n-1){
		
			for(i=0;i<n;i++)
			
			printf("%d ", matriz[i][j]);
		}else{
			
			printf("%d ", matriz[i-1][j]);
		}
	
	printf("\n");	
	}
	
	
}



//Recorrido de la matriz 6x6 en Z desde abajo hacia arriba
void recorridoMatrizEnZ2(int n, int m, int matriz[n][m]){
	int i,j;
	printf("El recorrido de la matriz 6x6 en Z es desde abajo hacia arriba: \n");
	
	for (i=0; i<n; i++){
		
		if(i==0 || i==n-1){
		
			for(j=0;j<m;j++)
			
			printf("%d ", matriz[i][j]);
		}else{
			
			printf("%d ", matriz[i][j-1]);
		}
	
	printf("\n");	
	}
	
	
}





int main() {
	int n,m;
	
	printf("Ingrese el numero de filas [n]: ");
	scanf("%d", &n);
	
	printf("Ingrese el numero de columnas [m]: ");
	scanf("%d", &m);
	
	int matriz[n][m];
	
	leerMatriz(n,m,matriz);
	
	imprimeMatriz(n,m,matriz);
	
	recorridoMatrizEnS(n,m,matriz);
	
	recorridoMatrizEnZ(n,m,matriz);
	
	recorridoMatrizEnZ2(n,m,matriz);
	
	system("pause");
	
	return 0;
}