#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int i,j;
	char *num = argv[1];
	int sizeC=strlen(argv[1]);
	char **array;

	fprintf(stdout, "arg[1] = %s \n", argv[1]);
	
	array=(char **)malloc(sizeC*sizeof(char *));
	for (i = 0; i < strlen(argv[1]); i++){
		int size=0;
		size = num[i]-48;
		if(size!=0){
			array[i]=(char *)malloc(size*sizeof(char));
		}
		else
			array[i]=NULL;
			
		if(size==0){
				fprintf(stdout,"null");
			}		
			
		for(j = 0;j<size;j ++){
			array[i][j]=num[i];		
			fprintf(stdout,"[%c]",array[i][j]);		
		}
		fprintf(stdout,"\n");
	}

	for (i = 0; i < sizeC; i++) {
        if (array[i] != NULL) {
            free(array[i]);
        }
    }
    free(array);
	return 0;
}