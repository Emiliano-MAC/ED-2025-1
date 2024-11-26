#include <stdio.h>
#include <string.h>
#include <stdlib.h>

main(){
	char c[10];
	int par;
	int n, num;
	int i,n2;
	
	do{
		printf("\nIngresa numero de cuenta: ");
		scanf("%s", &c);
		
		
		if(strlen(c) > 10){
			printf("\nNo existen numeros de cuenta con 10 digitos o mas, intentar de nuevo.");
		}
		
	}while(strlen(c) > 10);
	
	par=20;
	
	for(i = 0; i <= 9; i++){
			
		printf("[%d] ", par);
		par=par-2;
		
	}
	
	printf("\n");
	n = atoi(c);
	printf("\n%d",n);
	
	if(n>0){
		n2 = n%10;
	}
	if(n<0){
		n2 = n%10*-1;
	}
		printf("\n%d",n2);
		printf("\n\n");
	
	par=20;
	
	for(i = 0; i <= 9; i++){

		if(n2 == 0 && i == n2){
			printf("[%d] ", n2-1);
		}
		
		else if(i == n2){
			printf("[%d] ", n2/-n2);
		}
		
		else
			printf("[%d] ", par);
			par=par-2;
	}
	printf("\n");
	system("pause");
	
}