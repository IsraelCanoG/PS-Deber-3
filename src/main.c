#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "codificacion.h"
#include "cifrado.h"

void imprimirMenu();
void imprimirMenuArgumentos(char *argumentos[]);
int esNumero(char num[]);
int esComando(char *comando);
int main(int arg, char *argv[]){


	switch(arg){

		case 1:
			imprimirMenu();
			break;

		case 4:							//Se verifica si el formato de comando es válido
									//Se verifica si el formato de número es válido
			if(esComando(argv[3])&&esNumero(argv[1])){
				imprimirMenuArgumentos(argv);
			}else{
				printf("\tError: formato invalido\n");
			}
			
			break;

		default:
			printf("\n\n***********************************************************************************************\n\n");
			printf("\tError: faltan argumentos\n");
			printf("\n\n***********************************************************************************************\n\n");
	}

	return 0;

}

void clean_stdin(void) { 
	int c; 
   	do { 
	     c = getchar(); 
	}while (c != '\n' && c != EOF); 
} 


void imprimirMenu(){

        char mensaje[1000], llaveNumerica[1000], cifrado[1000];

        printf("\n\n***********************************************************************************************\n\n");
	printf("\tTipo de cifrado: ");
	scanf("%[^\n]",cifrado);

	switch(cifrado[0]){

		case 'C':
			printf("\tCifrado ciclico\n");
			printf("\tIngrese mensaje a cifrar     : ");
			clean_stdin();
			fgets(mensaje, sizeof(mensaje), stdin);
			printf("\tIngrese la llave numerica    : ");
			scanf("%s",llaveNumerica);
			if(esNumero(llaveNumerica)){
				cifradoCiclico(mensaje,atoi(llaveNumerica));
				printf("\tMensaje cifrado              : %s",mensaje);
				printf("\tMensaje cifrado en morse     : ");
				claveMorse(mensaje);
			}else{
				printf("\n\tError: llave invalida");
			}
			break;

		case 'A':
			//------------------------------------------
			break;

		case 'P':
			//------------------------------------------
			break;

		default:
			printf("\tError: comando invalido");

	}

        printf("\n\n***********************************************************************************************\n\n");
}

void imprimirMenuArgumentos(char *argumentos[]){

	printf("\n\n***********************************************************************************************\n\n");
	printf("\tTipo de cifrado: ");
	char *comando=argumentos[3];

	switch(comando[1]){

		case 'c':
			printf("C");
			printf("\n\tCifrado ciclico\n");
			printf("\tIngrese mensaje a cifrar     : %s\n",argumentos[2]);
        		printf("\tIngrese la llave numerica    : %s\n",argumentos[1]);
			cifradoCiclico(argumentos[2],atoi(argumentos[1])); 
			printf("\tMensaje cifrado              : %s",argumentos[2]); 
			printf("\n\tMensaje cifrado en morse    : "); 
			claveMorse(argumentos[2]);
			break;

		case 'a':
			printf("A");
			//------------------------------------------
			break;

		case 'p':
			printf("P");
			//------------------------------------------
			break;

		default:
			printf("\tError: comando invalido");

	}

	printf("\n\n***********************************************************************************************\n\n");

}

int esComando(char *comando){

	if(!(*comando=='-')){
		return 0;
	}else if(*(comando+1)=='c'||*(comando+1)=='a'||*(comando+1)=='p'){
		if(*(comando+2)=='\0')
			return 1;
		printf("ass");
	}
	return 0;

}

int esNumero(char num[]){

        int i;

        for(i=0;num[i]!='\0';i++){
                if(!((num[i]>=48 && num[i]<=57) || num[i]==45 || num[i]==43)){
                        return 0;
                }
        }
        return 1;
}
