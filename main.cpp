#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int opc = 0, posMatrizCaminho = 0, concateneiTXT = 0, concateneiParaRemover = 0;

char caminho[20][20], HD[1024][33];

void comandoType(char entrada[255]){
	char nomeArquivo[255];
	memset(nomeArquivo, 0, 255);
	int c;
	for(c = 5; entrada[c]; c++)
		nomeArquivo[c - 5] = entrada[c];
		
	nomeArquivo[c] = 0;
	
	//printf("O nome do arquivo que vou procurar: %s", nomeArquivo);
		
	if(posMatrizCaminho == 1){
		char pos[5] = "0000", posNaMatriz[5], nomeArquivoHD[255];
		int l = 0;
		
		while(HD[l][0] == '1'){
			for(int c = 4; c < 8; c++){
				posNaMatriz[c - 4] = HD[l][c];
			}
			
			posNaMatriz[4] = 0;
			
			//printf("O endereco que eu achei do arquivo: %s\n", posNaMatriz);
			
			if(strcmp(posNaMatriz, pos) == 0){
				memset(nomeArquivoHD, 0, 255);
				int x;
				for(x = 16; HD[l][x]; x++)
					nomeArquivoHD[x - 16] = HD[l][x];
					
				nomeArquivoHD[x] = 0;
				
				if(strcmp(nomeArquivo, nomeArquivoHD) == 0){
					char posArquivo[5], posArquivoProx[5];
					int pos, y;
					
					for(y = 8; y < 12; y++)
						posArquivo[y - 8] = HD[l][y];
						
					posArquivo[y - 8] = 0;
						
					pos = atoi(posArquivo);
					
					/*for(y = 4; y < 8; y++)
						posArquivoProx[y - 4] = HD[pos][y];
						
					posArquivoProx[y - 4] = 0;
					
					printf("O endereco do proximo: %s\n", posArquivoProx);
					*/
					for(int z = 8; HD[pos - 1][z]; z++){
						printf("%c", HD[pos - 1][z]);
					}
					
					printf("\n");
				}
				
				//printf("\nO nome do arquivo que achei no HD: %s", nomeArquivoHD);
				
			}
			
			l++;
		}
	}
	else{
		char nomePasta[255], posicao[5] = "0000", posicaoConvertida[5], nomePastaHD[255];
			
			int c, linha;
			
			for(c = 0; caminho[posMatrizCaminho - 1][c]; c++)
				nomePasta[c] = caminho[posMatrizCaminho - 1][c];
				
			nomePasta[c] = 0;
			
			int l = 0;
			
			while(HD[l][0] == '1'){
				if(HD[l][2] == '1'){
					//printf("Achei uma pasta\n");
					int x;
					for(x = 16; HD[l][x]; x++)
						nomePastaHD[x - 16] = HD[l][x];
						
					nomePastaHD[x - 16] = 0;
					
					//printf("O nome da pasta que peguei: %s, o nome da pasta que achei no HD: %s", nomePasta, nomePastaHD);
					
					if(strcmp(nomePasta, nomePastaHD) == 0){
						char posArquivo[255];
						//printf("entrei no if");
						linha = l + 1;
						
						int posEmConversao = 0;
						
						itoa(l + 1, posicaoConvertida, 10);
			
						for(int i = 4 - strlen(posicaoConvertida); posicaoConvertida[posEmConversao]; i++){
							posicao[i] = posicaoConvertida[posEmConversao];
							posEmConversao++;
						}		
						//printf("A posicao que vou procurar: %s\n", posicao);
					}			

				}
			
				l++;
			}
			int x = 0;
			
			while(HD[x][0] == '1'){
				char posNoHD[5];
				int s;
				for(s = 4; s < 8; s++)
					posNoHD[s - 4] = HD[x][s];
					
				posNoHD[s - 4] = 0;
				
				if(strcmp(posNoHD, posicao) == 0){
					char nomeArquivoHD[255];
					
					int z;
					
					for(z = 16; HD[x][z]; z++)
						nomeArquivoHD[z - 16] = HD[x][z];
						
					nomeArquivoHD[z - 16] = 0;
					
					if(strcmp(nomeArquivo, nomeArquivoHD) == 0){
						char posArquivo[5];
						int pos, y;
					
						for(y = 8; y < 12; y++)
							posArquivo[y - 8] = HD[x][y];
							
						posArquivo[y - 8] = 0;
							
						pos = atoi(posArquivo);
						
						for(int z = 8; HD[pos - 1][z]; z++){
							printf("%c", HD[pos - 1][z]);
						}
					
						printf("\n");
						
						//printf("Vou procurar aqui: %d", pos);
					}
				}
					
				//printf("O endereco que achei no HD: %s, o que vou procurar: %s", posNoHD, posicao);
				
				x++;
			}
		//printf("Pasta que vou procurar: %s\n", nomePasta);
	}
}

void comandoDir(){
	if(posMatrizCaminho == 1){
		char pos[5] = "0000", posNaMatriz[5];
		int l = 0;
		
		while(HD[l][0] == '1'){
			for(int c = 4; c < 8; c++){
				posNaMatriz[c - 4] = HD[l][c];
			}
			
			posNaMatriz[4] = 0;
			
			//printf("O endereco que eu achei do arquivo: %s\n", posNaMatriz);
			
			if(strcmp(posNaMatriz, pos) == 0){
				int posNumValido = 12;
				for(int c = 16; HD[l][c]; c++){
					printf("%c",  HD[l][c]);
				}
				
				while(HD[l][posNumValido] == '0'){
					posNumValido++;
				}
				
				printf("         ");
				for(int c = posNumValido; c < 16; c++){
					printf("%c",  HD[l][c]);
				}
				
				if(HD[l][2] != '1')
					printf(" bytes");
				
				printf("\n");
			}
			
			l++;
		}
	}
	else{
		char nomePasta[255], posicao[5] = "0000", posicaoConvertida[5], nomePastaHD[255];
		
		int c, linha;
		
		for(c = 0; caminho[posMatrizCaminho - 1][c]; c++)
			nomePasta[c] = caminho[posMatrizCaminho - 1][c];
			
		nomePasta[c] = 0;
		
		int l = 0;
		
		while(HD[l][0] == '1'){
			if(HD[l][2] == '1'){
				//printf("Achei uma pasta\n");
				int x;
				for(x = 16; HD[l][x]; x++)
					nomePastaHD[x - 16] = HD[l][x];
					
				nomePastaHD[x - 16] = 0;
				
				//printf("O nome da pasta que peguei: %s, o nome da pasta que achei no HD: %s", nomePasta, nomePastaHD);
				
				if(strcmp(nomePasta, nomePastaHD) == 0){
					//printf("entrei no if");
					linha = l + 1;
					
					int posEmConversao = 0;
					
					itoa(l + 1, posicaoConvertida, 10);
		
					for(int i = 4 - strlen(posicaoConvertida); posicaoConvertida[posEmConversao]; i++){
						posicao[i] = posicaoConvertida[posEmConversao];
						posEmConversao++;
					}
				
					//printf("A posicao que vou procurar: %s\n", posicao);
				}			
				
				
			}
		
			
			l++;
		}
		
		int x = 0;
		
		while(HD[x][0] == '1'){
			char posNoHD[5];
			int s;
			for(s = 4; s < 8; s++)
				posNoHD[s - 4] = HD[x][s];
				
			posNoHD[s - 4] = 0;
			
			if(strcmp(posNoHD, posicao) == 0){
				int posNumValido = 12;
				for(int c = 16; HD[x][c]; c++){
					printf("%c",  HD[x][c]);
				}
				
				while(HD[x][posNumValido] == '0'){
					posNumValido++;
				}
				
				printf("         ");
				for(int c = posNumValido; c < 16; c++){
					printf("%c",  HD[x][c]);
				}
				
				if(HD[x][2] != '1')
					printf(" bytes");
				
				printf("\n");
			}
				
			//printf("O endereco que achei no HD: %s, o que vou procurar: %s", posNoHD, posicao);
			
			x++;
		}
		//printf("Pasta que vou procurar: %s\n", nomePasta);
	}
}

void removeArquivo(char entrada[255], char HDAtual[255]){
	char nomeArquivo[255], nomeArquivoRemover[255], posRemove[5];
	int i, l = 0, pos;
	
	memset(nomeArquivo, 0, 255);
	
	for(i = 7; entrada[i]; i++){
		nomeArquivo[i - 7] = entrada[i];
	}
	
	while(HD[l][0] == '1' && HD[l][2] == '0' && l < 20){
		for(int c = 16; c < 32; c++){
			nomeArquivoRemover[c - 16] = HD[l][c];
		}
		
		if(strcmp(nomeArquivo, nomeArquivoRemover) == 0){
			for(int i = 8; i < 12; i++)
				posRemove[i - 8] = HD[l][i];
				
			pos = atoi(posRemove);
			
			HD[pos - 1][0] = '0';
				
			HD[l][0] = '0';
			l = 19;
		}
		l++;
		//printf("\nO arquivo que achei: %s, nesse local: %d", nomeArquivoRemover, pos);
	}
	

		
	FILE *fp;
	fp = fopen (HDAtual, "w+");
		
	// Inserindo no arquivo/HD novamente
	for(int i = 0; i < 1024; i++){
	    for(int j = 0; j < 33; j++){
	        fprintf(fp, "%c", HD[i][j]);
	    }
	}
	    
	fclose(fp);
	//nomeArquivo[i - 1] = 0;
	
	//printf("Vou remover esse arquivo: %s", nomeArquivo);
}

void mkdir(char entrada[255]){
	char local[255], HDAtual[255], nomePasta[255];
	int linhaLivre, c, i;
	
	memset(nomePasta, 0, 255);
	
	for(i = 0; caminho[0][i]; i++)
		HDAtual[i] = caminho[0][i];
	
	HDAtual[i] = 0;
		
	strcat(HDAtual, ".txt");
	
	if(posMatrizCaminho == 1){
		for(int i = 0; caminho[posMatrizCaminho - 1][i]; i++)
			local[i] = caminho[posMatrizCaminho - 1][i];
		
		while(HD[linhaLivre][0] == '1')
			linhaLivre++;
			
		HD[linhaLivre][0] = '1';	
		HD[linhaLivre][2] = '1';
		
		for(int i = 4; i < 16; i++)
			HD[linhaLivre][i] = '0';
			
		for(c = 6; entrada[c]; c++)
			nomePasta[c - 6] = entrada[c];
			
		nomePasta[c - 1] = 0;
		
		//printf("Vou salvar essa pasta: %s", nomePasta);
		
		for(int i = 16; i < 32; i++)
			HD[linhaLivre][i] = nomePasta[i - 16];
	}
	else{
		char posicao[5] = "0000", posicaoConvertida[5], nomePastaPai[255];
		int linhaPasta;
		
		for(int i = 0; caminho[posMatrizCaminho - 1][i]; i++)
			local[i] = caminho[posMatrizCaminho - 1][i];
		
		while(HD[linhaLivre][0] == '1')
			linhaLivre++;
			
		HD[linhaLivre][0] = '1';	
		HD[linhaLivre][2] = '1';
		
		for(int i = 8; i < 16; i++)
			HD[linhaLivre][i] = '0';
		
		for(c = 6; entrada[c]; c++)
			nomePasta[c - 6] = entrada[c];
			
		nomePasta[c - 1] = 0;
		
		//printf("Vou salvar essa pasta: %s", nomePasta);
		
		for(int i = 16; i < 32; i++)
			HD[linhaLivre][i] = nomePasta[i - 16];
			
		for(int i = 0; i < 20; i++){
			if(HD[i][2] == '1'){
				int c;
				for(c = 16; HD[i][c]; c++)
					nomePastaPai[c - 16] = HD[i][c];
					
				nomePastaPai[c - 16] = 0;
					
				if(strcmp(nomePastaPai, caminho[posMatrizCaminho - 1]) == 0)
					linhaPasta = i + 1;
				//printf("\nPeguei essa pasta: %s", nomePasta);
			}	
		}
		
		itoa(linhaPasta, posicaoConvertida, 10);
		
		int posEmConversao = 0;
		
		for(int i = 4 - strlen(posicaoConvertida); posicaoConvertida[posEmConversao]; i++){
			posicao[i] = posicaoConvertida[posEmConversao];
			posEmConversao++;
		}
		
		for(int c = 4; c < 8; c++){
			HD[linhaLivre][c] = posicao[c - 4];
		}
	}

	
	FILE *fp;
	fp = fopen (HDAtual, "w+");
		
	// Inserindo no arquivo/HD novamente
	for(int i = 0; i < 1024; i++){
	    for(int j = 0; j < 33; j++){
	        fprintf(fp, "%c", HD[i][j]);
	    }
	}
	    
	fclose(fp);
	//printf("Vou criar a minha pasta em %s", local);
}

void cdVolta(){
	//printf("To em cd volta");
	if(posMatrizCaminho == 0)
		printf("Impossivel voltar mais. Crie um HD.");
	else{
		posMatrizCaminho--;
		memset(caminho[posMatrizCaminho], 0, 20);
	}

}

void cdLocal(char entrada[255]){
	char localSemTXT[255], localComTXT[255], HDAtual[255];
	int j, i, encontrei = 0;
	
	memset(HDAtual, 0, 255);
	
	for(j = 3; entrada[j]; j++)
		localSemTXT[j - 3] = entrada[j];
	
	localSemTXT[(j - 3)] = 0;
		
	for(i = 0; localSemTXT[i]; i++)
		localComTXT[i] = localSemTXT[i];
		
	localComTXT[i] = 0;
		
	strcat(localComTXT, ".txt");
		
	//printf("Os locais:\nCom TXT: %s\nSem TXT: %s", localComTXT, localSemTXT);
	
	if(posMatrizCaminho == 0){
		if(FILE *o = fopen(localComTXT, "r")){
			for(int i = 0; localSemTXT[i]; i++)
				caminho[posMatrizCaminho][i] = localSemTXT[i];
			
			posMatrizCaminho++;
		
			// Guardando na matriz o conteúdo do arquivo/HD
			for(int l = 0; l < 1024; l++){
				for(int c = 0; c < 33; c++){
					fscanf(o, "%c", HD[l]+c);
				}
			}
			
			fclose(o);
		}
		
		else
			printf("Local inexistente. Utilize o comando \"createhd\" para criar um HD, ou o comando \"mkdir\" para criar uma pasta.\n");
	}
	
	else{
		char pastaAtual[255];
		
		//memset(HD, 0, 2048);
		
		for(int i = 0; caminho[0][i]; i++)
			HDAtual[i] = caminho[0][i];
		
		strcat(HDAtual, ".txt");
		
		FILE *o = fopen(HDAtual, "r");
		
		for(int l = 0; l < 1024; l++){
			for(int c = 0; c < 33; c++){
				fscanf(o, "%c", HD[l]+c);
			}
		}
		
		fclose(o);
		
		//printf("Vou procurar por uma pasta.");
		
		for(int i = 0; i < 21; i++){
			//printf("\nTo procurando uma pasta");
			if(HD[i][2] == '1'){
				//printf("\nAchei uma pasta");
				int c = 16;
				while(HD[i][c] != ' '){
					pastaAtual[c - 16] = HD[i][c];
					c++;
				}
				/*for(int c = 16; HD[i][c]; c++){
					if(HD[i][c] != 32)
						
				}*/
				
				if(strcmp(pastaAtual, localSemTXT) == 0){
					for(int c = 0; localSemTXT[c]; c++)
						caminho[posMatrizCaminho][c] = localSemTXT[c];
						
					posMatrizCaminho++;	
					
					encontrei = 1;				
				}			
				//printf("\nEncontrei uma pasta chamada %s, e vou comparar com essa: %s", pastaAtual, localSemTXT);
			}
		}
		
		if(encontrei == 0)
			printf("Pasta inexistente. Crie-a utilizando o comando \"mkdir\" ou acesse uma existente com o comando \"cd\".\n");
	}	
}

void insereConteudo(char HDAtual[255], char nome[255], int linhaLivreArquivo){
	int linhaLivre = 20, c;
	char conteudo[20000];
	
	memset(conteudo, 0, 20000);
	
	while(HD[linhaLivre][0] == '1')
		linhaLivre++;
		
	//HD[linhaLivre][0] = '1';
		
	fgets(conteudo, 20000, stdin);
	
	for(c = 0; conteudo[c]; c++);
	
	conteudo[c - 1] = 0;
	
	double tamanho = strlen(conteudo);
	
	double linhas = tamanho/24;
	int linhasEmInt = (int)linhas;
	int quant = ceil(linhas);
	
	int posNoConteudo = 0;
	
	char localArquivo[5] = "0000";
	
	char localArquivoConversao[5];
	
	itoa(linhaLivre + 1, localArquivoConversao, 10);
	
	for(int i = 0; i < quant; i++){
		int pos = 0;
		
		HD[linhaLivre][0] = '1';
		
		if(i != quant - 1){
			char localArquivoFor[5] = "0000";
		
			char localArquivoConversaoFor[5];
			
			itoa(linhaLivre + 2, localArquivoConversaoFor, 10);
			
			for(int i = 4 - strlen(localArquivoConversaoFor); localArquivoConversaoFor[pos]; i++){
				localArquivoFor[i] = localArquivoConversaoFor[pos];
				pos++;
			}
			
			for(int i = 4; i < 8; i++)
				HD[linhaLivre][i] = localArquivoFor[i - 4];
		}
		
		else{
			for(int i = 4; i < 8; i++)
				HD[linhaLivre][i] = '0';
		}
		
			
		for(int i = 8; i < 32; i++){
			HD[linhaLivre][i] = conteudo[posNoConteudo];
			posNoConteudo++;
		}
		
		linhaLivre++;
	}
	
	char tamanhoconteudo[5] = "0000";
	
	char conversao[5];
	itoa(tamanho, conversao, 10);
	
	int posEmConversao = 0;
	
	for(int i = 4 - strlen(conversao); conversao[posEmConversao]; i++){
		tamanhoconteudo[i] = conversao[posEmConversao];
		posEmConversao++;
	}
	
	tamanhoconteudo[4] = 0;
	
	for(int i = 12; i < 16; i++){
		HD[linhaLivreArquivo][i] = tamanhoconteudo[i - 12];
	}

	posEmConversao = 0;
	
	for(int i = 4 - strlen(localArquivoConversao); localArquivoConversao[posEmConversao]; i++){
		localArquivo[i] = localArquivoConversao[posEmConversao];
		posEmConversao++;
	}
	
	for(int i = 8; i < 12; i++){
		HD[linhaLivreArquivo][i] = localArquivo[i - 8];
	}
	
	//printf("O local do arquivo: %s", localArquivo);
	//printf("a posicao que vou guardar: %s", tamanhoconteudo);
	
	//printf("%s", conversao);
	
	
	FILE *fp;
	fp = fopen (HDAtual, "w+");
		
	// Inserindo no arquivo/HD novamente
	for(int i = 0; i < 1024; i++){
	    for(int j = 0; j < 33; j++){
	        fprintf(fp, "%c", HD[i][j]);
	    }
	}
	    
	fclose(fp);
	
	printf("Arquivo %s criado com %.0f bytes, e vou precisar de %d linhas.\n", nome, tamanho, quant);
	//printf("Minha conta deu %s", conversao);
	
	
	//printf("\nO tamamho do conteudo: %d, que vou colocar na linha: %d", tamanho, linhaLivre);
}

void criaArquivo(char entrada[255]){
	char nome[255], HDAtual[255];
	int linhaLivre, c;
	
	memset(nome, 0, 255);
	
	
	for(c = 0; caminho[0][c]; c++)
		HDAtual[c] = caminho[0][c];
		
	HDAtual[c] = 0;
	
	if(concateneiTXT == 0){
		strcat(HDAtual, ".txt");
		concateneiTXT = 1;
	}
	
	FILE *o = fopen(HDAtual, "r");
	
	// Guardando na matriz o conteúdo do arquivo/HD
	for(int l = 0; l < 1024; l++){
		for(int c = 0; c < 33; c++){
			fscanf(o, "%c", HD[l]+c);
		}
	}
	
	fclose(o);
	
	
	for(c = 7; entrada[c]; c++)
		nome[c - 7] = entrada[c];
		
	nome[(c - 7) + 1] = 0;

	c = 0;
	
	while(HD[c][0] == '1' && c < 21){
		linhaLivre++;
		c++;
	}
	
	HD[linhaLivre][0] = '1';
	
	HD[linhaLivre][2] = '0';

	// Colocando o nome do arquivo no HD	
	for(int c = 16; c < 32; c++){
		HD[linhaLivre][c] = nome[c - 16];
	}
	
	if(posMatrizCaminho == 1){
		for(c = 4; c < 8; c++)
			HD[linhaLivre][c] = '0';
	}
	else{
		int linhaPasta = 0;
		char nomePasta[255], posicao[5] = "0000", posicaoConvertida[5];
		
		for(int i = 0; i < 20; i++){
			if(HD[i][2] == '1'){
				int c;
				for(c = 16; HD[i][c]; c++)
					nomePasta[c - 16] = HD[i][c];
					
				nomePasta[c - 16] = 0;
					
				if(strcmp(nomePasta, caminho[posMatrizCaminho - 1]) == 0)
					linhaPasta = i + 1;
				//printf("\nPeguei essa pasta: %s", nomePasta);
			}	
		}
		
		itoa(linhaPasta, posicaoConvertida, 10);
		
		int posEmConversao = 0;
		
		for(int i = 4 - strlen(posicaoConvertida); posicaoConvertida[posEmConversao]; i++){
			posicao[i] = posicaoConvertida[posEmConversao];
			posEmConversao++;
		}
		
		for(int c = 4; c < 8; c++){
			HD[linhaLivre][c] = posicao[c - 4];
		}
		
		//printf("A posicao que vou gaurdar: %s", posicao);
		
		/*for(c = 4; c < 8; c++)
			HD[linhaLivre][c] = '1';*/
	}
	
	
	//printf("O posMatrizCaminho que tenho: %d", posMatrizCaminho);
	
	/*else if (posMatrizCaminho > 1){
		printf("\nVou salvar aqui: %s", caminho[posMatrizCaminho - 1]);
		int linhaPasta = 0;
		char nomePasta[255];
		
		printf("Vou comecar o for");
		for(int i = 0; i < 20; i++){
			for(int c = 16; HD[linhaPasta][c]; c++)
				nomePasta[c - 16] = HD[linhaPasta][c];
				
			printf("\nPeguei essa pasta: %s", nomePasta);	
	
		}
	}*/
	
	FILE *fp;
	fp = fopen (HDAtual, "w+");
		
	// Inserindo no arquivo/HD novamente
	for(int i = 0; i < 1024; i++){
	    for(int j = 0; j < 33; j++){
	        fprintf(fp, "%c", HD[i][j]);
	    }
	}
	    
	fclose(fp);
		
	insereConteudo(HDAtual, nome, linhaLivre);
		
	//printf("Nome do arquivo: %s, vou salvar nessa linha: %d", nome, linhaLivre);
	
	
}

void criaHD(char entrada[255]){
	char nomeArquivo[255], nomeHD[255];
	int i;
	
	for(i = 9; i < entrada[i]; i++){
	    nomeArquivo[i - 9] = entrada[i];
	}
	
	for(i = 9; i < entrada[i]; i++){
	    nomeHD[i - 9] = entrada[i];
	}
	
	nomeHD[(i - 9) + 1] = 0;

	nomeArquivo[(i - 9) + 1] = 0;

	strcat(nomeArquivo, ".txt");
	
	if(FILE *o = fopen(nomeArquivo, "r")){
		fclose(o);
		printf("Nome de HD repetido. Altere o nome ou utilize o comando cd para acessa-lo.\n");
	}
	
	else{
		for(int c = 0; nomeHD[c]; c++){
			caminho[posMatrizCaminho][c] = nomeHD[c];
		}
		
		posMatrizCaminho++;
		
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
		
		printf("HD criado com 32K bytes.\n");
			
		fclose(n);
	}
}

void recebeComando(){
	int c, i, j = 0, k = 0, ajeiteiCdVolta = 0;
	char comandos[8][10] = {"createhd", "create", "remove", "mkdir", "cd", "cd ..", "dir", "type"}, entrada[255];
	char comando[255];
	
	concateneiTXT = 0;
	
	memset(entrada, 0, 255);
	
	// Imprimindo a # que aguarda comandos
	if(posMatrizCaminho == 0)
		printf("# ");
	else{
	//	printf("Pos igual: %d", posMatrizCaminho)
		printf("# ");
		for(int c = 0; c < posMatrizCaminho; c++){
			for(int d = 0; caminho[c][d]; d++){
				printf("%c", caminho[c][d]);
			}
			
			if(c != posMatrizCaminho - 1)
				printf("/");
		}
		printf("> ");
	}
	
	fgets(entrada, 255, stdin);
	
	for(c = 0; entrada[c]; c++);	
	entrada[c - 1] = 0;
	
	c = 0;
	
	//printf("A entrada: %s", entrada);
	
	while(entrada[c] != 32 && entrada[c] != 0){
		comando[c] = entrada[c];
		if(entrada[c + 2] == '.' && entrada[c + 3] == '.'){
			comando[c + 1] = 32;
			comando[c + 2] = '.';
			comando[c + 3] = '.';
			
			ajeiteiCdVolta = 1;
		}
		
		c++;
	}
	
	if(ajeiteiCdVolta == 0)
		comando[c] = 0;
	else
		comando[c + 4] = 0;
		
	//printf("O comando: %s", comando);
	
	if(strcmp(comando, comandos[0]) == 0)
		criaHD(entrada);
	else if(strcmp(comando, comandos[1]) == 0){
		if(posMatrizCaminho == 0)
			printf("Um HD/pasta precisa ser criado/acessado para que um arquivo exista.\nUtilize o comando \"createhd\" para criar um HD, o comando \"cd\" para acessar um HD existente, ou o comando \"mkdir\" para criar uma pasta.\n");
		else
			criaArquivo(entrada);
	}
	else if(strcmp(comando, comandos[2]) == 0){
		if(posMatrizCaminho == 0)
			printf("Um arquivo HD precisa existir para que um arquivo seja removido.\nUtilize o comando \"createhd\" para criar um HD, ou o comando \"cd\" para acessar um HD existente.\n");
		else{
			char HDAtual[255];
			for(int i = 0; caminho[0][i]; i++)
				HDAtual[i] = caminho[0][i];
			
			strcat(HDAtual, ".txt");
				
			FILE *o = fopen(HDAtual, "r");
	
			// Guardando na matriz o conteúdo do arquivo/HD
			for(int l = 0; l < 1024; l++){
				for(int c = 0; c < 33; c++){
					fscanf(o, "%c", HD[l]+c);
				}
			}
			
			fclose(o);
			
			removeArquivo(entrada, HDAtual);
		}
	}
	else if(strcmp(comando, comandos[3]) == 0){
		if(posMatrizCaminho == 0)
			printf("Um HD/pasta precisa ser criado/acessado para que uma pasta exista.\nUtilize o comando \"createhd\" para criar um HD, ou o comando \"cd\" para acessar um HD existente.\n");
		else{
			char HDAtual[255];
			for(int i = 0; caminho[0][i]; i++)
				HDAtual[i] = caminho[0][i];
				
			strcat(HDAtual, ".txt");
			
			FILE *o = fopen(HDAtual, "r");
	
			// Guardando na matriz o conteúdo do arquivo/HD
			for(int l = 0; l < 1024; l++){
				for(int c = 0; c < 33; c++){
					fscanf(o, "%c", HD[l]+c);
				}
			}
			
			fclose(o);
			
			mkdir(entrada);
		}
	}
	else if(strcmp(comando, comandos[4]) == 0)
		cdLocal(entrada);
		
	else if(strcmp(comando, comandos[5]) == 0)
		cdVolta();
		
	else if(strcmp(comando, comandos[6]) == 0){
		char HDAtual[255];
		for(int i = 0; caminho[0][i]; i++)
			HDAtual[i] = caminho[0][i];
				
		strcat(HDAtual, ".txt");
			
		FILE *o = fopen(HDAtual, "r");
	
		// Guardando na matriz o conteúdo do arquivo/HD
		for(int l = 0; l < 1024; l++){
			for(int c = 0; c < 33; c++){
				fscanf(o, "%c", HD[l]+c);
			}
		}
			
		fclose(o);
		
		comandoDir();		
	}
	
	else if(strcmp(comando, comandos[7]) == 0){
		char HDAtual[255];
		for(int i = 0; caminho[0][i]; i++)
			HDAtual[i] = caminho[0][i];
				
		strcat(HDAtual, ".txt");
			
		FILE *o = fopen(HDAtual, "r");
	
		// Guardando na matriz o conteúdo do arquivo/HD
		for(int l = 0; l < 1024; l++){
			for(int c = 0; c < 33; c++){
				fscanf(o, "%c", HD[l]+c);
			}
		}
			
		fclose(o);
		
		comandoType(entrada);
	}
		
		
		
}

int main(){
	while(opc == 0)
		recebeComando();
	
	system("PAUSE");
	return 0;
}
