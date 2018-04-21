#include <stdio.h>
#include <stdlib.h>

char disco[1000];

int endOfDisk(){
	int i = 0;
	while(disco[i]!='\0'){
		i++;
	}
	return i;
}

void insert(char* matricula, char* nome, char* cpf){
		int j, i = endOfDisk();
		//Inserindo matricula
		disco[i++] = 'm';
		disco[i++] = '=';
		for(j = 0; matricula[j]!='\0'; j++){
			disco[i++] = matricula[j];
		}
		disco[i++] = '|';
		//Inserindo nome
		disco[i++] = 'n';
		disco[i++] = '=';
		for(j = 0; nome[j]!='\0'; j++){
			disco[i++] = nome[j];
		}
		disco[i++] = '|';
		//Inserindo cpf
		disco[i++] = 'c';
		disco[i++] = '=';
		for(j = 0; cpf[j]!='\0'; j++){
			disco[i++] = cpf[j];
		}
		disco[i++] = '$';
}

void listReg(){
	char *reg;
	reg = strtok(disco, "$");
	
	while(reg != NULL){
		printf("%s \n", reg);
		reg = strtok(NULL, "$");
	}
}

int main(){
	char nome[255];
	char matricula[6];
	char cpf[12];
	
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
