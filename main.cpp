#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

void createHd(char entrada[255]){
	int i = 9, j = 0;
	char nome[255];
	int numero;
	printf("# ");
	while(entrada[i] != '\0'){
		printf("%c", entrada[i]);
		nome[j] = entrada[i];
 		i++;
 		j++;
  		if(entrada[i + 1] == '\0'){
		    printf(">");
		    nome[j] = entrada[i + 1];
			break;
		}
		
	}
	strcat(nome, ".txt");
	FILE *f = fopen(nome, "wt");
	
	for(int l = 1; l < 1025; l++){
		for(int c = 1; c < 33; c++){
            /*if(l == 0){
                //fprintf(f, " ", l);
                l++;
			}*/
			if(c == 1)
			fprintf(f,"0 ");

			//if(k == 0)
			//	fprintf(f, "%d ", l);
			
			if(c == 32)
			    fprintf(f, "\n");

			if(c == 2 && l < 21)
				fprintf(f,"0 ");
				
			else if(c == 2 && l > 20)
			   	 fprintf(f,"1 ");
			
			
		}
	}
	
	fclose(f);
}



int main(int argc, char *argv[])
{
	int x = 1;
	char entrada[255];
	printf("# ");
	fgets(entrada, sizeof(entrada), stdin);
	
	char create[15];
	char hd[15] = "createhd";
	
	for(int i = 0; i <  15; i++){
		create[i] = entrada[i];
	}
	
	//printf("Entrada: %s create: %s hd: %s\n", entrada, create, hd);
	
	int i = 0;
	
	while(create[i] == hd[i] && create[i] != '\0'){
		i++;
	}
	
	if(i == 8){
		createHd(entrada);
	}
	else{
		printf("Fracasso");
	}


	system("pause");
	return 0;
}
