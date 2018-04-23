#include <stdio.h>
#include <stdlib.h>

struct bloco{
	int qEntradas;
	int fim;
	int tamReg[500];
	char reg[1000];
};
struct bloco disco;


void insert(char* matricula, char* nome, char* cpf){
		int j, i = disco.fim; 
		printf("FIM DO ESPACO VAZIO ANTES DA INSERCAO: %d\n", disco.fim);
		disco.qEntradas += 1; 
		//Inserindo matricula
		disco.reg[i--] = 'm';
		disco.reg[i--] = '=';
		for(j = 0; matricula[j]!='\0'; j++){
			disco.reg[i--] = matricula[j];
		}
		disco.reg[i--] = '|';
		//Inserindo nome
		disco.reg[i--] = 'n';
		disco.reg[i--] = '=';
		for(j = 0; nome[j]!='\0'; j++){
			disco.reg[i--] = nome[j];
		}
		disco.reg[i--] = '|';
		//Inserindo cpf
		disco.reg[i--] = 'c';
		disco.reg[i--] = '=';
		for(j = 0; cpf[j]!='\0'; j++){
			disco.reg[i--] = cpf[j];
		}
		disco.reg[i--] = '$';
		disco.reg[i-1] = '\0';
		disco.tamReg[disco.qEntradas-1] = disco.fim - i;
		disco.fim = i;
		printf("FIM DO ESPACO VAZIO APOS DA INSERCAO: %d\n", disco.fim);
		printf("TAMANHO DO REGISTRO INSERIDO: %d\n", disco.tamReg[disco.qEntradas-1]);
		
}

void listReg(){
	//char *reg;
	//reg = strtok(disco.reg, "$");
	/*
	while(reg != NULL){
		printf("%s \n", reg);
		reg = strtok(NULL, "$");
	}
	*/
	for(int i =998; disco.reg[i]!='\0'; i--){
		if(disco.reg[i]=='$') printf("\n");
		else printf("%c", disco.reg[i]);
	}
	
	printf("\n%d registros cadastrados\n", disco.qEntradas); 
}

int main(){
	char nome[255];
	char matricula[6];
	char cpf[12];
	disco.qEntradas = 0;
	disco.fim = 998;
	
	/*
	 '=' - valor ao campo
	 '|' - separador de campos
	 '$' - separador de registros
	 matricula
	 nome
	 cpf
	 */
	 
	 int op = 0;
	 
	 do{
		printf("1 - Inserir registro\n");
		printf("2 - Listar registros\n");
		printf("3 - Sair\n");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("Digite a matricula: ");
				scanf("%s", matricula);
				printf("Digite o nome: ");
				scanf("%s", nome);
				printf("Digite o cpf: ");
				scanf("%s", cpf);
				insert(matricula, nome, cpf);
				break;
			case 2:
				listReg();
				break;
		}
	 }while(op!=3);

}

