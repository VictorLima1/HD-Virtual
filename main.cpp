#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int opc = 0, temPasta = 0;
char nomePasta[255], nomePasta2[255];

void createArquivo(char nomeArquivo[255]){
	// Matriz para armazenar o conteúdo do arquivo/HD
	char tempComando[255], tempVetorComandos[255], HD[1024][33], arquivo[255], comandos[7][10] = {"createhd", "create", "remove", "mkdir", "cd", "cd ..", "dir"},  comandocreate[7] = "create", comandoremove[7] = "remove", comandomkdir[6] = "mkdir", comandocd[3] = "cd", comandocdvolta[6] = "cd ..", nome[255], conteudo[20000];
	memset(nome, 0, 255);
	memset(conteudo, 0, 20000);
	memset(tempComando, 0, 255);
	memset(tempVetorComandos, 0, 255);
	memset(arquivo, 0, 20000);
	int i, j = 0, r = 0, k = 0, m = 0, s = 0, t = 0, u = 0, endereco, achei = 0, comando, ajeitei = 0, linha;
	// Abrindo o arquivo/HD
	FILE *o = fopen(nomeArquivo, "r");
	
	// Guardando na matriz o conteúdo do arquivo/HD
	for(int l = 0; l < 1024; l++){
		for(int c = 0; c < 33; c++){
			fscanf(o, "%c", HD[l]+c);
		}
	}
	
	fclose(o);

	// Esperando a entrada com o comando "create"
	fgets(arquivo, 255, stdin);
	
	// Colocando o \0 no final do comando create
	for(i = 0; arquivo[i]; i++);
    arquivo[i - 1] = 0;
    
     while(arquivo[j] != 32){
	    tempComando[j] = arquivo[j];
	    if(arquivo[j + 2] == '.' && arquivo[j + 3] == '.'){
	    	tempComando[j + 1] = 32;
			tempComando[j + 2] = arquivo[j + 2];
	    	tempComando[j + 3] = arquivo[j + 3];
	    	tempComando[j + 4] = 0;
	    	ajeitei = 1;
		}
			
	    j++;
	}
	
	if(ajeitei != 1)
			tempComando[i + 1] = 0;
			
	for(j = 0; j < 7; j++){
			int x = 0;
			while(comandos[j][x] != 0){
				tempVetorComandos[x] = comandos[j][x];
				x++;
			}
			
			tempVetorComandos[x] = 0;
			
			if(strcmp(tempComando, tempVetorComandos) == 0){
				//printf("\nTem coisa igual");
				linha = j;
			}
			
			//printf("\nTo com isso em tempComando: %s, e isso em tempVetorComandos: %s", tempComando, tempVetorComandos);
		}
		
	//printf("\nAchei: %d", linha);
	
	//printf("\ntempComando: %s", tempComando);
    
    // Verificando se o comando está escrito corretamente
    while(arquivo[j] == comandocreate[j]){
    	j++;
	}
	
	while(arquivo[r] == comandoremove[r]){
    	r++;
	}
	
	while(arquivo[s] == comandomkdir[s]){
    	s++;
	}
	
	while(arquivo[t] == comandocd[t]){
    	t++;
	}
	
	while(arquivo[u] == comandocdvolta[u]){
    	u++;
	}
	
	// Verificando se cheguei na posição correta
	if(linha == 1){	
		// Guardando no nome do arquivo
		for(k = 7; k < arquivo[k]; k++){
			nome[k - 7] = arquivo[k];
		}
		
		// Colocando o \0 no nome do arquivo
		nome[(k - 7) + 1] = 0;
		
		// Procurando pela primeira linha livre
		int linhaLivre = 0;
		while(HD[linhaLivre][0] != '0')
			linhaLivre++;
			
		int linhaArquivoLivre = 20;
		while(HD[linhaArquivoLivre][0] != '0')
			linhaArquivoLivre++;
		
		endereco = linhaArquivoLivre + 1;
		
		// Trocando a disponibilidade da linha	
		HD[linhaLivre][0] = '1';
		
		// Trocando a terceira posição para indicar o que é armazenado
		HD[linhaLivre][2] = '0';
		
		// Colocando os zeros correspondentes a localização do arquivo
		for(int c = 4; c < 8; c++){
			if(temPasta != 0){
				if(c == 7){
					int x = 0;
					while(HD[x][2] == '0'){
						x++;
					}
					
					//printf("Vou colocar em %d", x);
					char pos = x + '0';
					HD[linhaLivre][c] = pos;
					
				}
				else{
					//printf("Entrei em C = 7");
					HD[linhaLivre][c] = '0';
				}
			}
			else{
				HD[linhaLivre][c] = '0';
			}
		}
		
		// Colocando o nome do arquivo no HD	
		for(int c = 16; c < 32; c++){
			HD[linhaLivre][c] = nome[c - 16];
		}
		
		// Pegando o conteúdo a ser salvo
		fgets(conteudo, 20000, stdin);
		
		// Colocando um \0 no final do conteúdo
		for(m = 0; conteudo[m]; m++);
    	conteudo[m - 1] = 0;
    	
    	// Fazendo a contagem de caracteres no arquivo
    	int n = 0;
		double contagem = 0;
    	while(conteudo[n] != 0){
    		if(conteudo[n] != 32){
    			contagem = contagem + 1;
			}
			n++;
		}
		
		// Fazendo a conversão de int para char
		char tamanho[5], enderecoArquivo[5];
		itoa(contagem,tamanho,10);
		itoa(endereco,enderecoArquivo,10);
		
		// Contando a quantidade de números que existem no vetor char
		int x = strlen(tamanho), y = strlen(enderecoArquivo);
		
		// Colcoando os 0 dependendo da quantidade de números
		if(x == 1){
			tamanho[3] = tamanho[0];
			for(int i = 0; i < 3; i++){
				tamanho[i] = '0';
			}
		}
		else if(x == 2){
			tamanho[2] = tamanho[0];
			tamanho[3] = tamanho[1];
			for(int i = 0; i < 2; i++){
				tamanho[i] = '0';
			}
		}
		else if(x == 3){
			char x = tamanho[1], y = tamanho[2], z = tamanho[3];
			tamanho[1] = tamanho[0];
			tamanho[2] = x;
			tamanho[3] = y;
			for(int i = 0; i < 1; i++){
				tamanho[i] = '0';
			}
		}
		
		// Fazendo a mesma coisa, só que pro endereço
		if(y == 2){
			enderecoArquivo[2] = enderecoArquivo[0];
			enderecoArquivo[3] = enderecoArquivo[1];
			for(int i = 0; i < 2; i++){
				enderecoArquivo[i] = '0';
			}
		}
		else if(y == 3){
			char x = enderecoArquivo[1], y = enderecoArquivo[2], z = enderecoArquivo[3];
			enderecoArquivo[1] = enderecoArquivo[0];
			enderecoArquivo[2] = x;
			enderecoArquivo[3] = y;
			for(int i = 0; i < 1; i++){
				enderecoArquivo[i] = '0';
			}
		}
		
		// Colocando o endereço onde ele começa
		for(int c = 8; c < 12; c++){
			HD[linhaLivre][c] = enderecoArquivo[c - 8];
		}
		
		// Inserindo a informaçõa do tamanho na matriz
		for(int c = 12; c < 16; c++){
			HD[linhaLivre][c] = tamanho[c-12];
		}
		
		double linhas = contagem/24;
		int quant = ceil(linhas);
		
		int pos = 0;
		
		if(quant == 1){
			for(int c = 4; c < 8; c++)
				HD[linhaArquivoLivre][c] = '0';
			
			HD[linhaArquivoLivre][0] = '1';
    	
    		for(int c = 8; c < 32; c++)
				HD[linhaArquivoLivre][c] = conteudo[c-8];
		}
		else{
			for(int i = 0; i < quant; i++){
				if(i != quant - 1){
					while(HD[linhaArquivoLivre][0] != '0'){
						linhaArquivoLivre++;
						endereco++;
					}
					
					endereco++;
					itoa(endereco,enderecoArquivo,10);
					int y = strlen(enderecoArquivo);
					if(y == 2){
						enderecoArquivo[2] = enderecoArquivo[0];
						enderecoArquivo[3] = enderecoArquivo[1];
						for(int i = 0; i < 2; i++){
							enderecoArquivo[i] = '0';
						}
					}
					else if(y == 3){
						char x = enderecoArquivo[1], y = enderecoArquivo[2], z = enderecoArquivo[3];
						enderecoArquivo[1] = enderecoArquivo[0];
						enderecoArquivo[2] = x;
						enderecoArquivo[3] = y;
						for(int i = 0; i < 1; i++){
							enderecoArquivo[i] = '0';
						}
					}
					
					for(int c = 4; c < 8; c++)
						HD[linhaArquivoLivre][c] = enderecoArquivo[c - 4];
				}
				
				if(i == quant - 1){
					for(int c = 4; c < 8; c++)
						HD[linhaArquivoLivre][c] = '0';
				}
				
					
				HD[linhaArquivoLivre][0] = '1';
				for(int c = 8; c < 32; c++){
					HD[linhaArquivoLivre][c] = conteudo[pos];
					pos++;
				}
				linhaArquivoLivre++;
			}	
		}
		
		FILE *fp;
	    fp = fopen (nomeArquivo, "w+");
		
		// Inserindo no arquivo/HD novamente
		for(int i = 0; i < 1024; i++){
	        for(int j = 0; j < 33; j++){
	            fprintf(fp, "%c", HD[i][j]);
	        }
	    }
	    
	    fclose(fp);
	    
	    printf("Arquivo \"%s\" criado com %.0f bytes.\n", nome, contagem);
	}
		
		
	else if(linha == 2){
		char nomeArquivoDeletar[255], nomeTemp[255];
		
		for(k = 7; k < arquivo[k]; k++){
			nomeArquivoDeletar[k - 7] = arquivo[k];
		}
		
		nomeArquivoDeletar[(k - 7) + 1] = 0;
		
		int x = 0, linhaDeletar;
		
		int linhaLivre = 0;
		while(HD[linhaLivre][0] != '0')
			linhaLivre++;
			
		for(int l = 0; l < linhaLivre; l++){
			for(int c = 16; c < 32; c++){
				nomeTemp[c - 16] = HD[l][c];
			}
			while(nomeArquivoDeletar[x] == nomeTemp[x]){
				x++;
				if(nomeArquivoDeletar[x + 1] == 0){
					achei = 1;
					linhaDeletar = l;
				}
			}
			//printf("\nTenho isso pra deletar: %s, peguei isso do arquivo: %s", nomeArquivoDeletar, nomeTemp);
		}
		
		if(achei == 1){
			HD[linhaDeletar][0] = '0';
			
			char posicaoDeleta[3], posicaoProximo[3];
			
			posicaoDeleta[0] = HD[linhaDeletar][10];
			posicaoDeleta[1] = HD[linhaDeletar][11];
			
			int localDeleta = (posicaoDeleta[0] - '0') * 10 + posicaoDeleta[1] - '0', localProximo;
			
			if(HD[linhaDeletar + 1][10] == 32)
				localProximo = localDeleta + 1;
			else{
				posicaoProximo[0] = HD[linhaDeletar + 1][10];
				posicaoProximo[1] = HD[linhaDeletar + 1][11];
			
			
				localProximo = (posicaoProximo[0] - '0') * 10 + posicaoProximo[1] - '0';
			}
			
			//printf("%d", localDeleta);
			//printf("%d", localProximo);
			
			for(int l = localDeleta; l < localProximo; l++){
				HD[l - 1][0] = '0';
			}
			
			FILE *fp;
		    fp = fopen (nomeArquivo, "w+");
			
			// Inserindo no arquivo/HD novamente
			for(int i = 0; i < 1024; i++){
		        for(int j = 0; j < 33; j++){
		            fprintf(fp, "%c", HD[i][j]);
		        }
		    }
		    
		    fclose(fp);
		    
		    printf("Arquivo \"%s\" removido.\n", nomeArquivoDeletar);
		}
		
		else{
			printf("Aquivo inexistente.\n");
		}		    
	}
	
	else if(linha == 3){
	
		
		if(temPasta != 0){
			memset(nomePasta2, 0, 255);
			//printf("\nTo no caso de ter uma pasta");
			for(k = 6; k < arquivo[k]; k++)
				nomePasta2[k - 6] = arquivo[k];
				
			nomePasta2[(k - 6) + 1] = 0;
		}
		else{
			memset(nomePasta, 0, 255);
			//printf("\nTo no caso de nao ter uma pasta");
			for(k = 6; k < arquivo[k]; k++)
				nomePasta[k - 6] = arquivo[k];
			
			nomePasta[(k - 6) + 1] = 0;		
		}
		
		// Procurando pela primeira linha livre
		int linhaLivre = 0;
		while(HD[linhaLivre][0] != '0')
			linhaLivre++;
			
		HD[linhaLivre][0] = '1';
		
		HD[linhaLivre][2] = '1';
		
		
		if(temPasta != 0){
			for(int c = 4; c < 16; c++){
				if(c == 7){
					char nomePastaTemp[255];
					int x = 0;
					while(HD[x][2] == '0'){
						x++;
					}
					
					while(strcmp(nomePastaTemp, nomePasta) != 0 && x < linhaLivre){
						memset(nomePastaTemp, 0, 255);
						for(int i = 16; HD[x][i]; i++)
							nomePastaTemp[i - 16] = HD[x][i];
						
						//printf("\nNome da pasta pai: %s, nome da pasta temp: %s", nomePasta, nomePastaTemp);
						x++;
					}
					
					x = x - 1;
					
					char pos = x + '0';
					HD[linhaLivre][c] = pos;
					
					//printf("\nO nome da pasta: %s", nomePastaTemp);
					
					//printf("Vou colocar em %d", x);
					
				}
				else{
					//printf("Entrei em C = 7");
					HD[linhaLivre][c] = '0';
				}
			}
				//HD[linhaLivre][c] = '0';
		}
		else{
			for(int c = 4; c < 16; c++)
				HD[linhaLivre][c] = '0';
		}
		
		//printf ("\nO tem pasta: %d", temPasta);
		
		if(temPasta != 0){
			for(int c = 16; c < 32; c++)
				HD[linhaLivre][c] = nomePasta2[c-16];
		}
		else{
			for(int c = 16; c < 32; c++)
				HD[linhaLivre][c] = nomePasta[c-16];
		
		}
		
		
		if(temPasta != 0)
			printf("%s criada.\n", nomePasta2);
		
		else
			printf("%s criada.\n", nomePasta);		
			
		
		FILE *fp;
		fp = fopen (nomeArquivo, "w+");
			
		// Inserindo no arquivo/HD novamente
		for(int i = 0; i < 1024; i++){
		    for(int j = 0; j < 33; j++){
		        fprintf(fp, "%c", HD[i][j]);
		    }
		}
		    
		fclose(fp);
	}
	
	else if(linha == 4){
		int achado = 0;
		char nomePastaTemp[255], nomePastaHD[255];
		for(k = 3; k < arquivo[3]; k++){
			nomePastaTemp[k - 3] = arquivo[k];
		}
		
		nomePastaTemp[(k - 3) + 1] = 0;
		
		// Procurando pela primeira linha livre
		int linhaLivre = 0;
		while(HD[linhaLivre][0] != '0')
			linhaLivre++;
			
		for(int l = 0; l < linhaLivre; l++){
			for(int c = 16; c < 32; c++){
				nomePastaHD[c - 16] = HD[l][c];
			}
			
			int x = 0;
			while(nomePastaHD[x] == nomePastaTemp[x]){
				if(nomePastaTemp[x + 1] == 0)
					achado = 1;
				x++;
			}
		}
		
		if(achado == 1){
			for(int c = 0; nomePastaTemp[c]; c++){
				nomePasta[c] = nomePastaTemp[c];
			}
			temPasta++;
		}
		else{
			printf("Pasta inexistente.\n");
		}
	}
	
	else if(linha == 5){
		temPasta--;
	}
	
	else if(linha == 6){
		if(temPasta == 0){
			char pos[5];
			int linhaLivre = 0, quant = 0;
			while(HD[linhaLivre][0] != '0')
				linhaLivre++;
				
			for(int i = 0; i < linhaLivre; i++){
				for(int j = 4; j < 8; j++){
					pos[j - 4] = HD[i][j];
				}
				
				if(strcmp(pos, "0000") == 0){
					int x = 16;
					while(HD[i][x] != 0){
						printf("%c", HD[i][x]);
						x++;
					}
					
					if(HD[i][2] != '1'){
						int y = 12;
						printf ("    ");
						while(HD[i][y] == '0' && y < 16){
							y++;
						}
						
						while(y < 16){
							printf("%c", HD[i][y]);
							y++;
						}
						
						
						printf(" bytes");
					}
				
					printf("\n");
				}	
			}
		}
		
		else{
			if(temPasta == 1){
				char nomeTemp[255], local[5], valor;
				int linhaLivre = 0, linha;
				
				while(HD[linhaLivre][0] != '0')
					linhaLivre++;
					
				for(int i = 0; i < linhaLivre; i++){
					memset(nomeTemp, 0, 255);
					if(HD[i][2] == '1'){
						for(int j = 16; HD[i][j]; j++)
							nomeTemp[j - 16] = HD[i][j];
						
						
						if(strcmp(nomeTemp, nomePasta) == 0){
							linha = i;
							if(i > 10){
								char endereco = i + '0';
							}
							
							else{
								local[3] = i + '0';
								local[0] = '0';
								local[1] = '0';
								local[2] = '0';
							}
						}	
					}
				}
				
				for(int m = 0; m < linhaLivre; m++){
					char localizacao[5];
					
					for(int n = 4; n < 8; n++){
						localizacao[n - 4] = HD[m][n];
					}
					
					if(strcmp(localizacao, local) == 0){
						int x = 16;
						while(HD[m][x] != 0){
							printf("%c", HD[m][x]);
							x++;
						}
						
						if(HD[m][2] != '1'){
							int y = 12;
							printf ("    ");
							while(HD[m][y] == '0' && y < 16){
								y++;
							}
							
							while(y < 16){
								printf("%c", HD[m][y]);
								y++;
							}
							
							
							printf(" bytes");
						}
						printf("\n");
					}
				}
				//printf("\nO local da pasta: %s", local);
			}
		}
	}
	
	//printf("S: %d, T:%d, U: %d", s, t, u);
}

void criaArquivo(char nomeArquivo[255]){
	int i = 0;
	char nome[255];
	while(nomeArquivo[i] != 0){
		nome[i] = nomeArquivo[i];
		i++;
	}
	nome[i + 1 ] = 0;
	// Colcando o .txt no nome do arquivo/HD
	strcat(nomeArquivo, ".txt");
	
	while(opc == 0){
		if(temPasta == 0){
			// Imprimindo o # nomeArquivo>
			printf("# %s> ", nome);
		}
		else if(temPasta == 1){
			printf("# %s/%s> ", nome, nomePasta);
		}
		else if(temPasta == 2){
			printf("# %s/%s/%s> ", nome, nomePasta, nomePasta2);
		}
		// Verificando se o arquivo/HD já existe
		if(FILE *o = fopen(nomeArquivo, "r")){
			fclose(o);
			//printf("Vou entrar em um arquivo");
			createArquivo(nomeArquivo);
		}
		
		// Criando o arquivo/HD caso ele não exista
		else{
			FILE *n = fopen(nomeArquivo, "wt");
			
			// For que cria o arquivo/HD
			for(int l = 0; l < 1024; l++){
				for(int c = 0; c < 33; c++){
					if(c == 0)
						fprintf(n, "%c", '0');
						
					else if(c == 32 && l < 1023)
						fprintf(n, "%c", '\n');
						
					else if(c == 1 && l < 20)
						fprintf(n, "%c", '0');
						
					else if(c == 1 && l >= 20)
					   	 fprintf(n, "%c", '1');
		
		            else
		                fprintf(n, "%c", ' ');
				}
			}
			
			fclose(n);
			//printf("Vou criar um arquivo");
			createArquivo(nomeArquivo);
		}
	}
}

void criaHD(){
	// Declaração de variáveis
	char createhd[9] = "createhd", entrada[255], nomeArquivo[255];
	int c, i, j;
	while(opc == 0){
		// Imprimindo a # que aguarda comandos
		printf("# ");
		// Pegando a entrada com o comando "createhd"
		fgets(entrada, 255, stdin);
		
		// For que acresenta \0 ao final da entrada, pois fgets coloca também o enter/quebra linha
		for(c = 0; entrada[c]; c++);
	    entrada[c - 1] = 0;
	    
	    // Verificando se o comando está escrito corretamente;
	    while(entrada[j] == createhd [j]){
	    	j++;
		}
	    
	    // Verificando se cheguei na posição em que todas as letras do comando estão corretas
	    if(j == 8){
	    	// For que guarda o nome do arquivo/HD após o comando "createhd" na entrada
	    	for(i = 9; i < entrada[i]; i++){
	    		nomeArquivo[i - 9] = entrada[i];
			}
		
			// Colocando o \0 no final do nome do arquivo/HD
			nomeArquivo[(i - 9) + 1] = 0;
		
			criaArquivo(nomeArquivo);
		}
	    else{
	    	// Imprimindo erro caso os textos não sejam iguais;
	    	printf("Comando desconhecido. Tente novamente.\n");
		}	
	}
	
}

int main(){
	criaHD();
	
	
	system("PAUSE");
	return 0;
}
