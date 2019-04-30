// Integrantes da dupla: Daniel e Filipe Mattos.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define TAM 5000
//variavel global para contar quantos espaços a str principal tera para definir assim o numero exato de colunas
int x = 1;
//Funcao para alocar matiz
char ** alocarmatrizchar(int quant_linhas, int quant_colunas){
	char **matriz;
	int i;
	matriz = (char **)calloc(quant_linhas,sizeof(char *));
		for(i=0;i<quant_linhas;i++){
			matriz[i] = (char *)calloc(quant_colunas,sizeof(char));
		}
	return (matriz);
}
//função que vai ler uma string
char* lerdados (char *s){
	printf("============== Digite a string ============== \n");
	gets(s);
	int i;
	for(i=0; i<TAM; i++){
		if(s[i] == ' '){
			x++;
		}
	}
	return (s);
	}
// funçao que ira quebrar uma string em varias sub strings alocando elas em cada linha de uma matriz
char ** quebrastr (char *s){
	int i,j = 0,k = 0;
	char **temp = alocarmatrizchar(x,100);
	for(i=0; i<TAM; i++){
		if(s[i] == ' '){
			j++;
			k = 0;
		}else if (s[i] != '\0'){
			temp[j][k] = s[i];
			k++;
		}else{
			break;
		}
	}
	return (temp);
}
// Funcao que vai mudar as vogais por AU seguindo a regra descrita no trabalho
char * lingAU(char *s, int *chave){
	char *temp;
	int i, j=0, k= 0;
	temp = (char *) calloc(TAM, sizeof(char));
	for(i=0; i<strlen(s); i++){
        switch(s[i]){
        	case 'a':
  		    case 'A':
   	            temp[j]= 'A';
                temp[j+1]= 'U';
                j+=2;
                chave[k] = 1;
                k++;
                break;
   	        case 'e':
			case 'E':
				temp[j]= temp[j+2] = 'A';
				temp[j+1]= temp[j+3] = 'U';
				j+=4;
				chave[k] = 2;
                k++;
				break;
			case 'i':
			case 'I':
			    temp[j]= temp[j+2] = temp[j+4] = 'A';
				temp[j+1]= temp[j+3] = temp [j+5] = 'U';
				j+=6;
				chave[k] = 3;
                k++;
				break;
			case 'o':
			case 'O':
				temp[j]= temp[j+2] = temp[j+4] = temp[j+6] = 'A';
				temp[j+1]= temp[j+3] = temp [j+5] = temp[j+7] = 'U';  
				j+=8;
				chave[k] = 4;
                k++;
				break;
			case 'u':
			case 'U':
				temp[j]= temp[j+2] = temp[j+4] = temp[j+6] = temp[j+8] = 'A';
				temp[j+1]= temp[j+3] = temp [j+5] = temp[j+7] = temp[j+9] = 'U';
				j+=10;
				chave[k] = 5;
                k++;
				break;   
            default:
                temp[j] = s[i];
                j++;
                break;
        }
   }
   strcpy(s, temp);
   free(temp);
   //system("pause");
   return(s);
}
// Funcao que ira colocar EI na frente e EI atraz de acordo com a quantidade de X
char * enxertoEI(char *s){
	char * temp, * EI;
	int i = 0, j = 0;
	temp = (char *) calloc(TAM, sizeof(char));
	EI = (char *) calloc(TAM, sizeof(char));
	strcpy(temp, s);
	for(i=0; i<strlen(temp); i++){
		if(temp[i] == 'x' || s[i] == 'X'){
			EI[j]= 'E';
			EI[j+1]= 'I';
			j+=2;
		}
	}
	strcpy(s, EI);
	strcat(s, temp);
	strcat(s, EI);
	free(temp);
	free(EI);
	return(s);
}
// Funcao que ira inverter toda a string
char * inversaoTotal(char *s){
	s = strrev(s);
	return(s);
}
// Funcao que ira fazer a troca entre pares de caracteres
char * inversao2a2(char *s){
	char temp;
	int i=0;
	for(i = 0; i < strlen(s); i+=2){
		if(s[i+1] != '\0'){
			temp = s[i];
		    s[i] = s[i+1];
		    s[i+1] = temp;
		}
	}	
	return(s);
}
// Funçao que ira Juntar todas as regras de Criptografia
char * juncao(char *s, int *chave){
	s = lingAU(s, chave);
	s = enxertoEI(s);
	s = inversaoTotal(s);
	s = inversao2a2(s);
	return(s);
}
// Funçao que ira descriptografar a lingua AU
char * descriptLingAU(char *s, int *chave){
	int i, j = 0, k = 0;
	char * temp = (char*)calloc(TAM,sizeof(char));
	for(i=0; i<strlen(s); i++){
		if(s[i] == 'A' && s[i+1] == 'U'){
			switch (chave[k]){
				case 1:
					temp[j] = 'a';
					i++;
					j++;
					k++;
					break;
				case 2:
					temp[j] = 'e';
					i+=3;
					j++;
					k++;
					break;
				case 3:
					temp[j] = 'i';
					i+=5;
					j++;
					k++;
					break;
				case 4:
					temp[j] = 'o';
					i+=7;
					j++;
					k++;
					break;
				case 5:
					temp[j] = 'u';
					i+=9;
					j++;
					k++;
					break;
				default:
					break;
			}
		}else{
			temp[j] = s[i];
			j++;
		}
	}
	strcpy(s,temp);
	free(temp);
	return(s);
}
// Funcao que ira descriptografar a linguagem EI
char * descriptEnxertoEI(char *s){
	int i, contx=0, j=0, k, l;
	char *temp;
	temp = (char *) calloc(TAM, sizeof(char));
	for(i=0;i<strlen(s);i++){
		if(s[i]=='x' || s[i]=='X'){
			contx++;
		}
	}
	k = contx * 2;
	l = strlen(s) - k;
	for(i=k; i<l;i++){
		temp[j]=s[i];
		j++;
	}
	strcpy(s, temp);
	free(temp);
	return(s);
}
//Funcao que ira descriptografar a funcao da juncao
char * descriptJuncao(char *s, int *chave){
	s = inversao2a2(s);
	s = inversaoTotal(s);
	s = descriptEnxertoEI(s);
	s = descriptLingAU(s,chave);
	return (s);
}
//Funcao que ira chamar todas as funcoes de criptografias
char ** criptografarDados(char ** sub, int count, int *chave){
	int i, j = 1;
	for(i=0; i<count; i++){
		switch(j){
			case 1 :
				sub[i] = lingAU(sub[i], chave);
				j++;
				break;
   			case 2:
				sub[i] = enxertoEI(sub[i]);
				j++;
				break;
			case 3:
				sub[i] = inversaoTotal(sub[i]);
				j++;
				break;
				continue;
			case 4:
				sub[i] = inversao2a2(sub[i]);
				j++;
				break;
			case 5:
				sub[i] = juncao(sub[i], chave);
				j = 1;
				break;
			default:
				break;
		}
	}
	return(sub);
}
//Funcao que ira chamar todas as funcoes de discriptografia
char ** descriptografarDados(char ** sub, int count, int * chave){
	int i, j = 1;
	for(i=0; i<count; i++){
		switch(j){
			case 1:
				sub[i] = descriptLingAU(sub[i], chave);
				j++;
				break;
			case 2:
				sub[i] = descriptEnxertoEI(sub[i]);
				j++;
				break;
			case 3:
				sub[i] = inversaoTotal(sub[i]);
				j++;
				break;
			case 4:
				sub[i] = inversao2a2(sub[i]);
				j++;
				break;
			case 5:
				sub[i] = descriptJuncao(sub[i], chave);	
				j = 1;
				break;
			default:
				break;
		}
	}
	return(sub);
}
// Funcao Principal
int main (){
	setlocale(LC_ALL, "Portuguese");
	int j;
	char **str =alocarmatrizchar(x,100), **mtrx = alocarmatrizchar(x,100);
	int chave[TAM] = {};
	lerdados(*str);
	mtrx = quebrastr(*str);
	mtrx = criptografarDados(mtrx, x, chave);
	printf("A string criptografada é: ");
	for(j=0; j<x; j++){
		printf("%s ", mtrx[j]);
	}
	printf("\n");
	mtrx = descriptografarDados(mtrx, x, chave);
	printf("A string descriptografada é: ");
	for(j=0; j<x; j++){
		printf("%s ", mtrx[j]);
	}
	return (0);
}